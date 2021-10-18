// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String text = "Arduino says Hello World!  ";

void print(String text)
{
    lcd.setCursor(0, 0);
    if (text.length() > 16)
    {
        text = text.substring(0, 16);
    }
    lcd.print(text);
}

void left_shift_string(String &text)
{
    char start = text[0];
    for (int i = 1; i < text.length(); i++)
    {
        text[i - 1] = text[i];
    }
    text[text.length() - 1] = start;
}

void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 1);
    Serial.begin(9600);
}

int DELAY_TIME = 150;

void loop()
{

    if (Serial.available() > 5)
    {
        text = Serial.readString();
        Serial.print("Changing the text to: ");
        Serial.println(text);
      	if (text.length() < 16)
        {
            for (int i = 0; i <= 16 - text.length(); i++)
            {
                text = text + ' ';
            }
        }
        lcd.clear();
    }

    for (int i = 0; i < text.length(); i++)
    {
        print(text);
        left_shift_string(text);
        delay(DELAY_TIME);
    }
}
