// NA DVK512 ploči se koristi KEY0 i LED3,
// a LED0 svetli dok taster nije pritisnut




#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define COLUMNS 16
#define LCD_RS 3
#define LCD_E 14
#define LCD_D4 4
#define LCD_D5 12
#define LCD_D6 13
#define LCD_D7 6

char c[8] = { 0b00000, 0b00000, 0b00000, 0b00000,
					0b00000, 0b00000, 0b00000, 0b11111};


int main() {
	int i=0, taster1_pritisnut=0,taster2_pritisnut=0;
	int r_value1,r_value2;
	int lcd;
	int x = 0, y = 0;


	if (wiringPiSetup() == -1)
		exit(1);

	
	 if(lcd = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4,LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0)){
		 printf ("lcdInit nije uspeo! \n");
		 return -1 ;
	 }

	pinMode(21, INPUT);
	pinMode(22, INPUT);
	
	
	taster1_pritisnut = 0;
	taster2_pritisnut = 0;
	lcdClear(lcd);

	while (1) {
		r_value1 = digitalRead(21);
		r_value2 = digitalRead(22); // procitaj KEY1
		
		//cekamo na pritisak tastera
		if (!r_value1 && !taster1_pritisnut) {
			taster1_pritisnut = 1;	

			lcdClear(lcd);		
			x++;

			if(x == 16){
				x = 0;
			}

			printf("i = %d\n", r_value1);
			fflush(stdout);
		
		}
		if (!r_value2 && !taster2_pritisnut) {
			taster2_pritisnut = 1;

			lcdClear(lcd);
			y++;

			if(y == 2){
				y = 0;
			}
			
			printf("i = %d\n", r_value2);
			fflush(stdout);
		
		}

		// cekamo da se taster otpusti
		if (r_value1) taster1_pritisnut = 0;
		if (r_value2) taster2_pritisnut = 0;

		
		lcdCharDef (lcd, 0, c);

		lcdPosition (lcd, x,y);

		lcdPutchar(lcd, 0);
		//lcdPuts (lcd, "A");










		sleep(0.1);

	}
	return 0;
}