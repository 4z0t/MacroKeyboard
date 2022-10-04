#define USE_IMAGES 1
// removes adafruit splash for memory optimization
#define SSD1306_NO_SPLASH
#include "Profile.h"
#if USE_IMAGES
#include "images.h"
#define IMAGE_(image) image
#else
#define IMAGE_(image) nullptr
#endif
#include <Adafruit_SSD1306.h>
#include <Keyboard.h>
#include <Keypad.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define ROWS 3
#define COLS 3

const char keys[ROWS][COLS] = {
    {'7', '8', '9'},
    {'4', '5', '6'},
    {'1', '2', '3'},
};

const byte rowPins[ROWS] = {6, 5, 4};
const byte colPins[COLS] = {9, 8, 7};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void GitFunc(char key)
{
    switch (key)
    {
    case '1':

        break;
    case '2':

        break;
    case '3':

        break;
    case '4':
        Keyboard.println("git status");
        break;
    case '5':
        Keyboard.print("git checkout ");
        break;
    case '6':
        Keyboard.println("git diff");
        break;
    case '7':

        break;
    case '8':
        Keyboard.println("git log");
        break;
    case '9':

        Keyboard.print("git commit -am \"\"");
        Keyboard.press(KEY_LEFT_ARROW);
        break;
    }
}

void MSVSFunc(char key)
{
    switch (key)
    {
    case '1':
        // navigate backward
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.print('-');
        break;
    case '2':
        // comment out
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.print('k');
        Keyboard.print('/');
        break;
    case '3':
        // navigate forward
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.print('-');
        break;
    case '4':
        // go to left document
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_PAGE_UP);
        break;
    case '5':

        break;
    case '6':
        // go to right document
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_PAGE_DOWN);
        break;
    case '7':
        // step into
        Keyboard.press(KEY_F11);
        break;
    case '8':
        // step over
        Keyboard.press(KEY_F10);
        break;
    case '9':
        // step out
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_F11);
        break;
    }
}

void VSCodeFunc(char key)
{
    switch (key)
    {
    case '1':

        break;
    case '2':
        // comment out
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.print('f');
        break;
    case '3':

        break;
    case '4':
        // Keyboard.println("git status");
        break;
    case '5':
        Keyboard.println("Punch lox");
        break;
    case '6':

        break;
    case '7':

        break;
    case '8':

        break;
    case '9':

        break;
    }
}

const byte TOTAL_PROFILES = 3;
const Profile profiles[TOTAL_PROFILES] = {
    Profile{IMAGE_(git_logo), "GIT", &GitFunc},
    Profile{IMAGE_(msvs_logo), "Microsoft\nVisual Studio", &MSVSFunc},
    Profile{IMAGE_(vscode_logo), "Visual Studio Code", &VSCodeFunc},
};

byte curProfile = 0;
byte prevP16 = 0;
byte prevP10 = 0;

void SwitchProfile()
{
    curProfile = (curProfile + 1) % TOTAL_PROFILES;
    display.clearDisplay();
#if USE_IMAGES
    auto image = profiles[curProfile].GetImage();
    if (image)
    {
        display.drawBitmap(
            (display.width() - LOGO_WIDTH) / 2,
            16,
            image, LOGO_WIDTH, LOGO_HEIGHT, 1);
    }
#endif

    display.setTextSize(1);              // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.cp437(true);                 // Use full 256 char 'Code Page 437' font
    display.setCursor(0, 0);             // Start at top-left corner

    display.print(profiles[curProfile].GetName());

    display.display();
}

//#define __DEBUG

void setup()
{
#ifdef __DEBUG
    Serial.begin(9600); // initialize serial communication:
#endif

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
#ifdef __DEBUG
        Serial.println(F("SSD1306 allocation failed"));
#endif
        for (;;)
        {
        }; // Don't proceed, loop forever
    }
#ifdef __DEBUG
    Serial.println(F("SSD1306 allocation good"));
#endif

    Keyboard.begin();
    display.display();
    delay(2000); // Pause for 2 seconds
    display.clearDisplay();
    SwitchProfile();

    pinMode(10, INPUT_PULLUP);
    pinMode(16, INPUT_PULLUP);
}

void loop()
{

    char key = keypad.getKey();

    if (key)
    {
#ifdef __DEBUG
        Serial.println(key);
#endif

        profiles[curProfile].Call(key);

        delay(100);
        Keyboard.releaseAll(); // this releases the buttons
    }
    else
    {
        byte p10 = digitalRead(10);
        byte p16 = digitalRead(16);
        if (p10 == 0 && p10 != prevP10)
        {

            SwitchProfile();
        }
        if (p16 == 0 && p16 != prevP16)
        {

            SwitchProfile();
        }
        prevP10 = p10;
        prevP16 = p16;
    }
}