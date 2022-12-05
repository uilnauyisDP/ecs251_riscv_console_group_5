#include <stdint.h>
#include <string.h>
#include "api.h"

uint32_t* regAddrFromMemHandle(uint32_t mem_handle)
{
    return (uint32_t*)(mem_handle + 0x50000000);
}

uint32_t memLengthCheck(uint32_t mem_handle, uint32_t mem_len)
{
    return (uint32_t)0;
}

uint32_t writeTargetMem(uint32_t mem_handle, uint32_t source_addr, uint32_t mem_len)
{
    uint32_t* addr = regAddrFromMemHandle(mem_handle);
    uint32_t result = memLengthCheck(mem_handle, mem_len);
    if(result != 0) return result;
    // memcpy(addr, (void*)source_addr, mem_len);
    for(uint32_t i = 0; i < mem_len; i++) ((uint8_t*)addr)[i] = ((uint8_t*)source_addr)[i];
    return 0;
}

uint32_t writeTarget(uint32_t mem_handle, uint32_t value)
{
    uint32_t* addr = regAddrFromMemHandle(mem_handle);
    uint32_t result = memLengthCheck(mem_handle, 4);
    if(result != 0) return result;
    *addr = value;
    return 0;
}

int writeIndexedTarget(uint32_t offset, uint32_t mem_size, uint32_t idx, uint8_t * addr, uint32_t mem_len)
{
    uint32_t handle = offset + idx * mem_size;
    if(mem_len > mem_size) return -1;
    writeTargetMem(handle, (uint32_t)addr, mem_len);
    // writeTargetMem((uint32_t)0x00, (uint32_t)bird_background_img, 512*10);
    return 0;
}

int setBackgroundDataImage(uint32_t idx, uint8_t * addr)
{
    return writeIndexedTarget(0x000, 0x24000, idx, addr, 288*512);
}

int initBackgroundPalette(uint32_t idx, uint8_t * addr, uint32_t mem_len)
{
    return writeIndexedTarget(0xFC000, 0x400, idx, addr, mem_len);
}

void setBackgroundControl(uint32_t idx, uint32_t x, uint32_t y, uint32_t z, uint32_t palette)
{
    uint32_t background_handle_offset = 0xFF100;
    uint32_t handle = background_handle_offset + idx * 4;
    y = (y + 288) & 0x3FF;
    x = (x + 512) & 0x3FF;
    z = (z + 0) & 0x7;
    palette = palette & 0x3;
    uint32_t value = (z << 22) + (y << 12) + (x << 2) + palette;
    writeTarget(handle, value);
}

void setLargeSpriteControl(uint32_t idx, uint32_t h, uint32_t w, uint32_t x, uint16_t y, uint32_t palette)
{
    uint32_t larget_sprite_handle_offset = 0xFF114;
    uint32_t handle = larget_sprite_handle_offset + idx * 4;
    h = (h - 33) & 0x1F;
    w = (w - 33) & 0x1F;
    y = (y + 64) & 0x1FF;
    x = (x + 64) & 0x3FF;
    palette = palette & 0x3;
    uint32_t value = (h << 26) + (w << 21) + (y << 12) + (x << 2) + palette;
    writeTarget(handle, value);
}

int initSpritePalette(uint32_t idx, uint8_t * addr, uint32_t mem_len)
{
    return writeIndexedTarget(0xFD000, 0x400, idx, addr, mem_len);
}

int setLargeSpriteDataImage(uint32_t idx, uint8_t * addr)
{
    return writeIndexedTarget(0xB4000, 0x1000, idx, addr, 64*64);
}

int initTransparentSpritePalette(uint32_t idx)
{
    uint32_t data_len = 0x400;
    uint8_t data[0x400];
    memset(data, 0, data_len);

    return writeIndexedTarget(0xFD000, data_len, idx, data, data_len);
}