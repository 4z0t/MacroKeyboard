

#include <Keypad.h>
#include <Keyboard.h>



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
        // Keyboard.press(KEY_LEFT_CTRL); // COPY
        // Keyboard.print('c');
        break;
      case '2':
        //Keyboard.press(KEY_LEFT_CTRL); // PASTE
        // Keyboard.print('v');
        break;
      case '3':
        // Keyboard.println("Alpha key3");
        break;
      case '4':
        // Keyboard.println("Alpha key4");
        break;
      case '5':
        Keyboard.println("Punch lox");
        break;
      case '6':
        //Keyboard.println("Alpha key6");
        break;
      case '7':
        //Keyboard.println("Alpha key7");
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
