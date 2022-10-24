#include"../HAL/INC/lcd.h"
#include"util/delay.h"
int main() {
	LCD_init();
	uint8 key;
	while (1) {
		key = KEYPAD_getPressedKey();
		LCD_intgerToString(key);
		_delay_ms(1000);
	}
	return 0;
}


