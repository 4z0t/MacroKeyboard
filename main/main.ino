

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Keyboard.h>
#include <Keypad.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1     
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


const byte ROWS = 3; // four rows
const byte COLS = 3; // four columns

char keys[ROWS][COLS] = {
    {'7', '8', '9'},
    {'4', '5', '6'},
    {'1', '2', '3'},
};

byte rowPins[ROWS] = {6, 5, 4};
byte colPins[COLS] = {9, 8, 7};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{

    Serial.begin(9600); // initialize serial communication:

    Keyboard.begin();
}

void loop()
{
    char key = keypad.getKey();

    if (key)
    {
        Serial.println(key);
        switch (key)
        {
        case '1':
            //previous page
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.print('-');
            break;
        case '2':
            //comment out
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.print('k');
            Keyboard.print('/');
            break;
        case '3':
            //next page
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.print('-');
            break;
        case '4':
            Keyboard.println("git status");
            break;
        case '5':
            Keyboard.println("Punch lox");
            break;
        case '6':
            // Keyboard.println("Alpha key6");
            break;
        case '7':
            // Keyboard.println("Alpha key7");
            break;
        case '8':
            // Keyboard.println("Alpha key8");
            break;
        case '9':

            Keyboard.println("Hello world!");
            break;
        }
        delay(100);
        Keyboard.releaseAll(); // this releases the buttons
    }
}
