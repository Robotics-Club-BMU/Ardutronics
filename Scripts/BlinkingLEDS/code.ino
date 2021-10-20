unsigned long myTime;

#define N 5

int LIGHTS[N] = {2, 3, 4, 5, 6}; // Pin numbers of all the lights!
int DELAYS[N] = {3, 4, 6, 1, 2}; //In seconds!
bool LIGHTS_ON[N] = {false};

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
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
    delay(1000);
    for (int i = 0; i < N; i++)
    {
        control_lights(i, millis() / 1000);
    }
}