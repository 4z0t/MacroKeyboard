#define USE_IMAGES 1
// removes adafruit splash for memory optimization
#define SSD1306_NO_SPLASH

#include <Adafruit_SSD1306.h>
#include <Keyboard.h>
#include <Keypad.h>
#include <Wire.h>
#include "Profile.h"
#if USE_IMAGES
#include "images.h"
#define IMAGE_(image) image
#else
#define IMAGE_(image) nullptr
#endif

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define ROWS 3
#define COLS 3

#define DRAW_AT_CENTER false

const char keys[ROWS][COLS] = {
  { '7', '8', '9' },
  { '4', '5', '6' },
  { '1', '2', '3' },
};

const byte rowPins[ROWS] = { 6, 5, 4 };
const byte colPins[COLS] = { 9, 8, 7 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void GitFunc(char key, KeyState state) {
  if (state == PRESSED)
    switch (key) {
      case '1':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('v');
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
        Keyboard.write(KEY_LEFT_ARROW);
        break;
    }
}

void MSVSFunc(char key, KeyState state) {
  if (state == PRESSED)
    switch (key) {
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

void VSCodeFunc(char key, KeyState state) {
  if (state == PRESSED)
    switch (key) {
      case '1':

        break;
      case '2':
        // format file
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

void UnrealEngineFunc(char key, KeyState state) {
  if (state == PRESSED)
    switch (key) {
      case '1':

        break;
      case '2':

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

const byte TOTAL_PROFILES = 4;
const Profile profiles[TOTAL_PROFILES] = {
  Profile{ IMAGE_(git_logo), "GIT", &GitFunc, IMAGE_(git_icons), false },
  Profile{ IMAGE_(msvs_logo), "Microsoft\nVisual Studio", &MSVSFunc, IMAGE_(msvs_icons) },
  Profile{ IMAGE_(vscode_logo), "Visual Studio Code", &VSCodeFunc },
  Profile{ IMAGE_(unreal_engine_logo), "Unreal Engine", &UnrealEngineFunc },
};

byte curProfile = 0;
byte prevP16 = 0;
byte prevP10 = 0;

void NextProfile() {
  curProfile = (curProfile + 1) % TOTAL_PROFILES;
}

void PrevProfile() {
  if (curProfile == 0)
    curProfile = TOTAL_PROFILES - 1;
  else
    curProfile = (curProfile - 1);
}

void RedrawImage() {
  display.clearDisplay();
#if USE_IMAGES
  auto image = profiles[curProfile].GetImage();
  if (image) {
    display.drawBitmap(
      DRAW_AT_CENTER ? (display.width() - LOGO_WIDTH) / 2 : 0,
      16,
      image, LOGO_WIDTH, LOGO_HEIGHT, 1);
  }
  IconGrid icons = profiles[curProfile].GetIcons();
  if (icons) {
    for (unsigned char i = 0; i < 3; i++) {
      for (unsigned char j = 0; j < 3; j++) {
        const unsigned char * icon = icons[i * 3 + j];
        if (icon) {
          display.drawBitmap(
            SCREEN_WIDTH - LOGO_WIDTH + ICON_SIZE * j,
            16 + i * ICON_SIZE,
            icon, ICON_SIZE, ICON_SIZE, 1);
        } else {
          display.drawPixel(
            SCREEN_WIDTH - LOGO_WIDTH + ICON_SIZE * j + ICON_SIZE / 2,
            16 + i * ICON_SIZE + ICON_SIZE / 2,
            1);
        }
      }
    }
  }

#endif
  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.cp437(true);                  // Use full 256 char 'Code Page 437' font
  display.setCursor(0, 0);              // Start at top-left corner

  display.print(profiles[curProfile].GetName());

  display.display();
}

// #define __DEBUG

void setup() {
#ifdef __DEBUG
  Serial.begin(9600);  // initialize serial communication:
#endif

  // SSD1306_SWITCHCAVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
#ifdef __DEBUG
    Serial.println(F("SSD1306 allocation failed"));
#endif
    for (;;) {
    };  // Don't proceed, loop forever
  }
#ifdef __DEBUG
  Serial.println(F("SSD1306 allocation good"));
#endif

  Keyboard.begin();
  display.display();
  delay(2000);  // Pause for 2 seconds
  RedrawImage();
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
}

void loop() {

  if (keypad.getKeys() && keypad.keyStateChanged()) {

    char key = keypad.getChar();
    KeyState state = keypad.getState();
#ifdef __DEBUG
    Serial.println(key);
    Serial.println(state);
#endif
    bool release = profiles[curProfile].Call(key, state);

    delay(50);
    if (release)
      Keyboard.releaseAll();  // this releases the buttons
  } else {
    byte p10 = digitalRead(10);
    byte p16 = digitalRead(16);
    if (p10 == 0 && p10 != prevP10) {
      Keyboard.releaseAll();
      NextProfile();
      RedrawImage();
      delay(100);
    } else if (p16 == 0 && p16 != prevP16) {
      Keyboard.releaseAll();
      PrevProfile();
      RedrawImage();
      delay(100);
    }
    prevP10 = p10;
    prevP16 = p16;
  }
}