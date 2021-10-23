#include <LiquidCrystal.h>
#define BTN_PIN 6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button_state = 0;
int previous_state = 0;
int COUNTER = 0;
unsigned long start_time, end_time;

void setup()
{
    lcd.begin(16, 2);
    pinMode(BTN_PIN, INPUT);
    Serial.begin(9600);
    lcd.print("Push BTN Count: ");
}

void loop()
{
    lcd.setCursor(0, 1);
    lcd.print(COUNTER);
    button_state = digitalRead(BTN_PIN);
    if (button_state != previous_state)
    {
        if (button_state == HIGH)
        {
            start_time = millis();
            COUNTER += 1;
            Serial.println("on");
            Serial.print("number of button pushes: ");
            Serial.println(COUNTER);
        }
        else
        {
            end_time = millis();
            int time = (end_time - start_time) / 1000;
            if (time >= 2)
            {
                COUNTER = 0;
            }
            Serial.println("off");
            Serial.print("Lasted for: ");
            Serial.println(time);
        }
        delay(5); // Wait for 5 millisecond(s)
    }
    previous_state = button_state;
}
