#define BUZZER 13

class Tone
{
public:
    float first;
    int pin;

    Tone(int _pin, float a)
    {
        pin = _pin;
        first = a;
    }
};

Tone tones[] = {
    Tone(2, 240),   // Sa
    Tone(3, 270),   // Re
    Tone(4, 300),   // Ga
    Tone(5, 337.5), // Ma
    Tone(6, 360),   // Pa
    Tone(7, 400),   // Dha
    Tone(8, 450),   // Ni
    Tone(9, 470)    // Saa
};
int SIZE = sizeof(tones) / sizeof(tones[0]);

void setup()
{

    //Declaring all to be in input mode
    for (int i = 0; i < SIZE; i++)
    {
        pinMode(tones[i].pin, INPUT);
    }
    // DECLARING BUTTON AS OUTPUT
    pinMode(BUZZER, OUTPUT);
}

void loop()
{
    // READ THE VALUES FROM BUTTONS
    for (int i = 0; i < SIZE; i++)
    {
        if (digitalRead(tones[i].pin) == 1)
        {
            tone(BUZZER, tones[i].first, 100);
        }
    }
    // now let's put a short delay for a nice pitch
    delay(10);
}