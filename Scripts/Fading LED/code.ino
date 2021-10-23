#define LED 11
#define DELAY_TIME 500

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    int i = 0;
    for (i = 0; i <= 255; i++)
    {
        analogWrite(LED, i);
        delay(5);
    }

    delay(DELAY_TIME);
    for (i = 255; i >= 0; i--)
    {
        analogWrite(LED, i);
        delay(5);
    }
    delay(DELAY_TIME);
}
