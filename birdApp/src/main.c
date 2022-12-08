#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "api.h"

volatile int global = 42;
volatile uint32_t controller_status = 0;
volatile uint32_t running_flag = 1;
extern int INIT_Y;
extern int INIT_X;

struct position
{
    uint32_t x;
    uint32_t y;
};

void initVideoSetting();
void showGamerOverSprite();

int main()
{
    writeTarget(0xFF414, 0x1);

    if(running_flag)
        initVideoSetting();

    int x_pos = INIT_X;
    int y_pos = INIT_Y;
    uint32_t last_time = 0;
    uint32_t last_time_2 = 0;
    int move_frequency = 3;

    while (running_flag)
    {
        global = getTicks();
        if (global != last_time)
        {
            movePillars();
            birdFly(&x_pos, &y_pos);

            controller_status = getStatus();
            if (controller_status)
            {
                birdMove(&x_pos, &y_pos);
            }

            if (global - last_time_2 >= move_frequency)
            {
                birdFall(&x_pos, &y_pos);
                last_time_2 = global;
            }

            birdCollide(&x_pos, &y_pos);
        }
        last_time = global;
    }
}

void birdFly(int *x_pos, int *y_pos)
{
    for (int i = 0; i < 3; i++)
    {
        setLargeSpriteControl(i, 64, 64, *x_pos, *y_pos, i == global % 3);
    }
}

void birdMove(int *x_pos, int *y_pos)
{
    int sprite_inc_x;
    int sprite_inc_y;
    int move_speed = 5;
    sprite_inc_x = 0;
    sprite_inc_y = 0;
    if (controller_status & 0x1)
    {
        sprite_inc_x = -move_speed;
    }
    if (controller_status & 0x2)
    {
        sprite_inc_y = -move_speed;
    }
    if (controller_status & 0x4)
    {
        sprite_inc_y = move_speed;
    }
    if (controller_status & 0x8)
    {
        sprite_inc_x = move_speed;
    }
    *x_pos += sprite_inc_x;
    *y_pos += sprite_inc_y;
    for (int i = 0; i < 3; i++)
    {
        setLargeSpriteControl(i, 64, 64, *x_pos, *y_pos, i == global % 3);
    }
}

void birdFall(int *x_pos, int *y_pos)
{
    *y_pos += 3;
    for (int i = 0; i < 3; i++)
    {
        setLargeSpriteControl(i, 64, 64, *x_pos, *y_pos, i == global % 3);
    }
}

void birdCollide(int *x_pos, int *y_pos)
{
    for (int j = 0; j < 6; j++)
    {
        if (calculateCollision(*x_pos, *y_pos, j) == 1)
        {
            // deal with collision
            running_flag = 0;
            // show up the "game over" sprites.
            showGamerOverSprite();
            // linePrintf(14, "collision has occurred: %d,%d,pillar_index=%d                    ", bird_x, bird_y, j);
        }
    }
}
