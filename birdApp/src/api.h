uint32_t* regAddrFromMemHandle(uint32_t mem_handle);
uint32_t memLengthCheck(uint32_t mem_handle, uint32_t mem_len);
uint32_t writeTargetMem(uint32_t mem_handle, uint32_t source_addr, uint32_t mem_len);
uint32_t writeTarget(uint32_t mem_handle, uint32_t value);
int writeIndexedTarget(uint32_t offset, uint32_t mem_size, uint32_t idx, uint8_t * addr, uint32_t mem_len);
int setBackgroundDataImage(uint32_t idx, uint8_t * addr);
int initBackgroundPalette(uint32_t idx, uint8_t * addr, uint32_t mem_len);
void setBackgroundControl(uint32_t idx, uint32_t x, uint32_t y, uint32_t z, uint32_t palette);
void setLargeSpriteControl(uint32_t idx, uint32_t h, uint32_t w, uint32_t x, uint16_t y, uint32_t palette);
int initSpritePalette(uint32_t idx, uint8_t * addr, uint32_t mem_len);
int setLargeSpriteDataImage(uint32_t idx, uint8_t * addr);
int initTransparentSpritePalette(uint32_t idx);

#define DISPLAY_MODE_TEXT 0
#define DISPLAY_MODE_GRAPHICS 1
#define DISPLAY_WIDTH_PX 512
#define DISPLAY_HEIGHT_PX 288
#define DISPLAY_WIDTH_CHAR 0x40

