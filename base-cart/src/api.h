/**
 * @return Ticks
*/
uint32_t getTicks(void);

/**
 * @return controller
*/
uint32_t getStatus(void);

/**
 * (for internal testing)
 * @return Video Toggle variable 
*/
uint32_t getVideoToggle(void);

/**
 * @return Video Interrupt counter
*/
uint32_t getVidIntCtr(void);

/**
 * Calcs and returns the large sprite control.
 * Note: Maybe change to set and add spriteIdx param
  */
uint32_t calcLargeSpriteControl(int32_t x, int32_t y, uint32_t w, uint32_t h, uint32_t p);

/**
 * Writes the video interrupt counter to the screen starting at text 
 * postition 17 and grows left as the counter increases
*/
uint32_t writeVidIntCtrToScreen();

/**
 * @return pseudo-random integer between 0 and RAND_MAX.
*/
uint32_t rand();

/**
 * Seeds the random number generator
 * @return 1 on success
*/
uint32_t seed_rand(uint32_t seed);

/**
 * Moves the large sprite at a specified large sprite index to a certain (x, y) on the screen
 * @return 1 on success
*/
uint32_t moveLargeSprite(uint32_t spriteIdx, int32_t x, int32_t y);

/**
 * Sets the large sprite control data at the spriteIdx to 0x0
 * @return 1 on success
*/
uint32_t deleteLargeSprite(uint32_t spriteIdx);

/**
 * Writes some char c to some text position pos
 * @return 1 on success
*/
uint32_t writeCharToTextPos(uint32_t pos, char c);

/**
 * Writes some int num to text position 17 (grows left as it gets bigger)
 * @return 1 on success
*/
uint32_t writeIntToScreen(int num);



/* ===================== To-Do Below ===================== */

/**
 * 
*/
void sleep(uint32_t time);

/**
 * 
*/
uint32_t calcSmallSpriteControl(int32_t x, int32_t y, uint32_t w, uint32_t h, uint32_t p);

/**
 * 
 * @return 1 on success
*/
uint32_t moveSmallSprite(uint32_t spriteIdx, int32_t x, int32_t y);

/**
 * 
 * @return 1 on success
*/
uint32_t getNearbySprites(uint32_t param1); // Maybe split into large and small

/**
 * 
 * @return 1 on success
*/
uint32_t setBackgroundColor();

/**
 * @return 1 on success
*/
uint32_t setBackgroundImage();

/**
 * @return 
*/
uint32_t* getLargeSpriteControl(uint32_t spriteIdx);

/**
 * 
 * @return 
*/
uint32_t* getSmallSpriteControl(uint32_t spriteIdx);

// Functions for setting small/large sprite data

// Removed key input API for now...
