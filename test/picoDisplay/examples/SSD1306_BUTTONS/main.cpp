// === Libraries ===
#include <cstdio>
#include "pico/stdlib.h"
#include "ssd1306/SSD1306_OLED.hpp"
#include "ssd1306/gpio.hpp"
#include "ssd1306/CatGameBitmaps.hpp"

// Screen settings
#define myOLEDwidth  128
#define myOLEDheight 64
#define myScreenSize (myOLEDwidth * (myOLEDheight/8)) // eg 1024 bytes = 128 * 64/8
#define BUTTON4 0
#define BUTTON3 1
#define BUTTON2 2
#define BUTTON1 3
#define BUTTON8 4
#define BUTTON7 5
#define BUTTON6 6
#define BUTTON5 7




uint8_t screenBuffer[myScreenSize]; // Define a buffer to cover whole screen  128 * 64/8

// I2C settings
const uint16_t I2C_Speed = 100;
const uint8_t I2C_Address = 0x3C;

// instantiate  an OLED object
SSD1306 myOLED(myOLEDwidth, myOLEDheight);

// =============== Function prototype ================
void Initialize(void);
void Run(void);
void End(void);

// ======================= Main ===================
int main()
{
	Initialize();
	Run();
	
}
// ======================= End of main  ===================

// ===================== Function Space =====================
void Initialize()
{
	stdio_init_all(); // Initialize chosen serial port, default 38400 baud
	busy_wait_ms(500);
	printf("OLED SSD1306 :: Start!\r\n");
	while (myOLED.OLEDbegin(I2C_Address, i2c1, I2C_Speed, 26, 27) != true)
	{
		printf("SetupTest ERROR : Failed to initialize OLED!\r\n");
		busy_wait_ms(1500);
	} // initialize the OLED
	if (myOLED.OLEDSetBufferPtr(myOLEDwidth, myOLEDheight, screenBuffer, sizeof(screenBuffer) / sizeof(uint8_t)) != 0)
	{
		printf("SetupTest : ERROR : OLEDSetBufferPtr Failed!\r\n");
		while (1) { busy_wait_ms(1000); }
	} // Initialize the buffer
	myOLED.OLEDFillScreen(0xF0, 0); // splash screen bars
	busy_wait_ms(1000);
}

void Run()
{
	for (int i = 0; i < 9; i++) {
		gpio_init(i);
	}
	gpio_set_dir(BUTTON1, GPIO_IN);
	gpio_set_dir(BUTTON2, GPIO_IN);
	gpio_set_dir(BUTTON3, GPIO_IN);
	gpio_set_dir(BUTTON4, GPIO_IN);
	gpio_set_dir(BUTTON5, GPIO_IN);
	gpio_set_dir(BUTTON6, GPIO_IN);
	gpio_set_dir(BUTTON7, GPIO_IN);
	gpio_set_dir(BUTTON8, GPIO_IN);
	gpio_pull_up(BUTTON1);
	gpio_pull_up(BUTTON2);
	gpio_pull_up(BUTTON3);
	gpio_pull_up(BUTTON4);
	gpio_pull_up(BUTTON5);
	gpio_pull_up(BUTTON6);
	gpio_pull_up(BUTTON7);
	gpio_pull_up(BUTTON8);

	myOLED.OLEDclearBuffer();
	myOLED.setFont(pFontDefault);
	myOLED.setCursor(0, 8);
	myOLED.print("Bottom Right Button");
	myOLED.setCursor(0, 16);
	myOLED.print("Will stop system");
	myOLED.setCursor(0, 0);
	myOLED.print("Press Buttons!");
	myOLED.OLEDupdate();



	while (true) {
		if (!gpio_get(BUTTON1)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 1 pressed!");
			myOLED.OLEDupdate();
			busy_wait_ms(100);
			myOLED.OLEDclearBuffer();
			myOLED.OLEDupdate();
			busy_wait_ms(10);
			myOLED.OLEDBitmap(0, 0, 24, 24, smallCat, true, sizeof(smallCat) / sizeof(uint8_t));
			myOLED.OLEDupdate();


		}
		else if (!gpio_get(BUTTON2)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 2 pressed!");
			myOLED.OLEDupdate();
			busy_wait_ms(100);
			myOLED.OLEDclearBuffer();
			myOLED.OLEDupdate();
			busy_wait_ms(10);
			int i = 0;
			while (i < 10) {
				myOLED.OLEDBitmap(0, 0, myOLEDwidth, myOLEDheight, cat1, true, sizeof(cat1) / sizeof(uint8_t));
				myOLED.OLEDupdate();
				busy_wait_ms(166);
				myOLED.OLEDBitmap(0, 0, myOLEDwidth, myOLEDheight, cat2, true, sizeof(cat1) / sizeof(uint8_t));
				myOLED.OLEDupdate();
				busy_wait_ms(166);
				myOLED.OLEDBitmap(0, 0, myOLEDwidth, myOLEDheight, cat3, true, sizeof(cat1) / sizeof(uint8_t));
				myOLED.OLEDupdate();
				busy_wait_ms(166);
				myOLED.OLEDBitmap(0, 0, myOLEDwidth, myOLEDheight, cat4, true, sizeof(cat1) / sizeof(uint8_t));
				myOLED.OLEDupdate();
				busy_wait_ms(166);
				myOLED.OLEDBitmap(0, 0, myOLEDwidth, myOLEDheight, cat5, true, sizeof(cat1) / sizeof(uint8_t));
				myOLED.OLEDupdate();
				busy_wait_ms(166);
				myOLED.OLEDBitmap(0, 0, myOLEDwidth, myOLEDheight, cat6, true, sizeof(cat1) / sizeof(uint8_t));
				myOLED.OLEDupdate();
				busy_wait_ms(166);
				myOLED.OLEDBitmap(0, 0, myOLEDwidth, myOLEDheight, cat7, true, sizeof(cat1) / sizeof(uint8_t));
				myOLED.OLEDupdate();
				busy_wait_ms(166);
				i++;
			}
		}
		else if (!gpio_get(BUTTON3)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 3 pressed!");
				myOLED.OLEDupdate();
				myOLED.OLEDupdate();
				busy_wait_ms(100);
				myOLED.OLEDclearBuffer();
				myOLED.OLEDupdate();
				busy_wait_ms(10);
				myOLED.OLEDBitmap(8, 0, 24, 24, smallCat, true, sizeof(smallCat) / sizeof(uint8_t));
				myOLED.OLEDupdate();
		}
		else if (!gpio_get(BUTTON4)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 4 pressed!");
				myOLED.OLEDupdate();
				myOLED.OLEDupdate();
				busy_wait_ms(100);
				myOLED.OLEDclearBuffer();
				myOLED.OLEDupdate();
				busy_wait_ms(10);
				myOLED.OLEDBitmap(0, 8, 24, 24, smallCat, true, sizeof(smallCat) / sizeof(uint8_t));
				myOLED.OLEDupdate();
		}
		else if (!gpio_get(BUTTON5)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 5 pressed!");
				myOLED.OLEDupdate();
				myOLED.OLEDupdate();
				busy_wait_ms(100);
				myOLED.OLEDclearBuffer();
				myOLED.OLEDupdate();
				busy_wait_ms(10);
				myOLED.OLEDBitmap(16, 0, 24, 24, smallCat, true, sizeof(smallCat) / sizeof(uint8_t));
				myOLED.OLEDupdate();
		}
		else if (!gpio_get(BUTTON6)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 6 pressed!");
				myOLED.OLEDupdate();
				myOLED.OLEDupdate();
				busy_wait_ms(100);
				myOLED.OLEDclearBuffer();
				myOLED.OLEDupdate();
				busy_wait_ms(10);
				myOLED.OLEDBitmap(0, 16, 24, 24, smallCat, true, sizeof(smallCat) / sizeof(uint8_t));
				myOLED.OLEDupdate();
		}
		else if (!gpio_get(BUTTON7)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 7 pressed!");
			myOLED.setCursor(0, 40);
			myOLED.print("Resetting...");
			myOLED.OLEDupdate();
				busy_wait_ms(1000);
				Run();
		}
		else if (!gpio_get(BUTTON8)) {
			myOLED.setCursor(0, 32);
			myOLED.print("Button 8 pressed!");
			myOLED.setCursor(0, 40);
			myOLED.print("Stopping...");
			myOLED.OLEDupdate();
			busy_wait_ms(1000);
			End();

		}
	}



}

void End()
{
	myOLED.OLEDPowerDown(); // Switch off display
	myOLED.OLEDdeI2CInit();
	printf("OLED SSD1306 :: End\r\n");
}
// ============== EOF =========
