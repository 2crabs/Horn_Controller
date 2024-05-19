#include "Display.h"

HAL_StatusTypeDef Display_SetDigits(Display *display, uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t mode){
	uint8_t digit1Values[10] = DIGIT1_VALUES;
	uint8_t digit23Values[10] = DIGIT23_VALUES;

	uint8_t ports[3];
	ports[0] = digit1Values[digit1] | (digit23Values[digit2] << 7);
	ports[1] = (digit23Values[digit2] >> 1) | (digit23Values[digit3] << 6);
	ports[2] = digit23Values[digit3] >> 2;

	if(mode == DISPLAY_MODE_1DIGIT){
		ports[2] = 0;
		ports[1] = 0;
	}

	if(mode == DISPLAY_MODE_2DIGITS){
		ports[2] = 0;
	}

	return TCA6424_WriteRegisters(display->IOHandle, TCA6424_REG_OUT0 | TCA6424_AUTO_INCREMENT, ports, 3);
}

HAL_StatusTypeDef Display_SetValue(Display *display, uint16_t value, uint8_t mode){

}

HAL_StatusTypeDef Display_SetMinSec(Display *display, uint8_t minutes,  uint8_t seconds){

}
