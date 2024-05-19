#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "TCA6424.h"

#define DIGIT1_VALUES {0b01110111, 0b01000001, 0b01101110, 0b01101011, 0b01011001, 0b00111011, 0b00111111, 0b01100001, 0b01111111, 0b01111011}
#define DIGIT23_VALUES {0b01111110, 0b00011000, 0b01101101, 0b00111101, 0b00011011, 0b00110111, 0b01110111, 0b00011100, 0b01111111, 0b00111111}

#define DISPLAY_MODE_1DIGIT 0x00
#define DISPLAY_MODE_2DIGITS 0x01
#define DISPLAY_MODE_3DIGITS 0x02

typedef struct {
	TCA6424 *IOHandle;
} Display;

HAL_StatusTypeDef Display_SetDigits(Display *display, uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t mode);

HAL_StatusTypeDef Display_SetValue(Display *display, uint16_t value, uint8_t mode);

HAL_StatusTypeDef Display_SetMinSec(Display *display, uint8_t minutes,  uint8_t seconds);

#endif
