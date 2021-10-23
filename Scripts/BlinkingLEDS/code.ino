#include <LiquidCrystal.h>
#define N 5

int LIGHTS[N] = {6, 7, 8, 9, 10}; // Pin numbers of all the lights!
int DELAYS[N] = {3, 4, 6, 1, 2};  //In seconds!
bool LIGHTS_ON[N] = {false};
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    lcd.begin(16, 2);
    lcd.print("Seconds Passed");
    Serial.begin(9600);
    for (int i = 0; i < N; i++)
    {
        pinMode(LIGHTS[i], OUTPUT);
    }
}

void control_lights(int light, int time)
{
    if (time % DELAYS[light] == 0)
    {
        if (LIGHTS_ON[light])
        {

            LIGHTS_ON[light] = false;
            digitalWrite(LIGHTS[light], LOW);
            Serial.print("Turning off the light: ");
            Serial.print(light);
            Serial.print("At time: ");
            Serial.println(time);
        }
        else
        {
            LIGHTS_ON[light] = true;
            digitalWrite(LIGHTS[light], HIGH);
            Serial.print("Turning on the light: ");
            Serial.print(light);
            Serial.print("At time: ");
            Serial.println(time);
        }
    }
}

void loop()
{
    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
    delay(1000);
    for (int i = 0; i < N; i++)
    {
        control_lights(i, millis() / 1000);
    }
}
