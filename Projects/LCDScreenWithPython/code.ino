#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int DELAY_TIME = 150;
int COUNT = 0;
String TEXT;
bool SLIDE = false;

void print(String text)
{
    lcd.setCursor(0, 0);
    if (text.length() > 16)
    {
        text = text.substring(0, 16);
    }
    lcd.print(text);
}

void set_count(int time)
{
    lcd.setCursor(0, 1);
    lcd.print(time);
}

/*

Features that program needs to have 
1) Increase the counter, by 1, or decrease by 1 
2) Set the counter to a particular number
3) Chage the text
4) Be able make the text slide

For 1) commands = icr, or dcr
For 2) cnt NUMBER
For 3) txt TEXT
For 4) sld on to turn on sliding, and sld off to turn off sliding.

*/

void handle_commands(String command)
{

    String type = command.substring(0, 3);
    if (type == "icr")
    {
        //Code to increment
        Serial.println("Incrementing the counter!");
        COUNT++;
    }

    else if (type == "dcr")
    {
        //Code to decrement
        Serial.println("Decrementing the counter!");
        COUNT--;
    }

    else if (type == "cnt")
    {
        //Changing the count!
        String sub = command.substring(4);
        COUNT = sub.toInt();
        Serial.println("Changing the count!");
    }

    else if (type == "txt")
    {
        //Changing the text
        String text = command.substring(4);
        for (int i = 0; i < 16 - text.length(); i++)
            text = text + " ";
        Serial.println("Changing the text");
        TEXT = text;
        lcd.clear();
    }
    else if (type == "sld")
    {
        //Changing the text
        String text = command.substring(4);
        if (text == "on")
        {
            Serial.println("Turning the sliding text on");
            SLIDE = true;
        }
        else if (text == "off")
        {
            Serial.println("Turning the slliding text off");
            SLIDE = false;
        }
    }
}

void left_shift_string(String &text)
{
    // Utility function for the shift functionality
    char start = text[0];
    for (int i = 1; i < text.length(); i++)
    {
        text[i - 1] = text[i];
    }
    text[text.length() - 1] = start;
}

void handle_serial_comm()
{
    if (Serial.available())
    {
        String command = Serial.readString();
        handle_commands(command);
    }
}

void setup()
{
    lcd.begin(16, 2);
    handle_commands("txt Flask Count: ");
    Serial.begin(9600);
}

void loop()
{
    handle_serial_comm();
    if (SLIDE)
    {
        for (int i = 0; i < TEXT.length(); i++)
        {
            handle_serial_comm();
            print(TEXT);
            left_shift_string(TEXT);
            delay(DELAY_TIME);
        }
    }
    else
        print(TEXT);
    set_count(COUNT);
}
