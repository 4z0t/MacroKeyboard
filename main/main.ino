

#include "Profile.h"
#include "images.h"
#include <Adafruit_SSD1306.h>
#include <Keyboard.h>
#include <Keypad.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const byte ROWS = 3;
const byte COLS = 3;

char keys[ROWS][COLS] = {
    {'7', '8', '9'},
    {'4', '5', '6'},
    {'1', '2', '3'},
};

byte rowPins[ROWS] = {6, 5, 4};
byte colPins[COLS] = {9, 8, 7};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void GitFunc(char key)
{
    switch (key)
    {
    case '1':
        // previous page
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
        // next page
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
        // case '7':
        //  Keyboard.println("Alpha key7");
        break;
    case '8':
        // Keyboard.println("Alpha key8");
        break;
    case '9':

        Keyboard.println("Hello world!");
        break;
    }
}

const int TOTAL_PROFILES = 3;
const Profile profiles[TOTAL_PROFILES] = {
    Profile{git_logo, "GIT", &GitFunc},
    Profile{msvs_logo, "Microsoft\nVisual Studio", &GitFunc},
    Profile{vscode_logo, "Visual Studio Code", &GitFunc},
};

int curProfile = 0;

void SwitchProfile()
{
    curProfile = (curProfile + 1) % TOTAL_PROFILES;
    display.clearDisplay();
    display.drawBitmap(
        (display.width() - LOGO_WIDTH) / 2,
        16,
        profiles[curProfile].GetImage(), LOGO_WIDTH, LOGO_HEIGHT, 1);

    display.setTextSize(1);              // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.cp437(true);                 // Use full 256 char 'Code Page 437' font
    display.setCursor(0, 0);             // Start at top-left corner

    display.print(profiles[curProfile].GetName());

    display.display();
}

void setup()
{

    Serial.begin(9600); // initialize serial communication:

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
        {
        }; // Don't proceed, loop forever
    }

    Serial.println(F("SSD1306 allocation good"));

    Keyboard.begin();
    display.display();
    delay(2000); // Pause for 2 seconds
    display.clearDisplay();
    SwitchProfile();
}

void loop()
{
    char key = keypad.getKey();

    if (key)
    {
        Serial.println(key);
        if (key == '7')
        {
            SwitchProfile();
        }
        else
        {
            profiles[curProfile].Call(key);
        }
        delay(100);
        Keyboard.releaseAll(); // this releases the buttons
    }
}
