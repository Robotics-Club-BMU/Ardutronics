int top[] = {0, 1, 2};
int times[] = {5000, 2000, 6000};

void setup()
{
    for (int i = 0; i < 3; i++)
    {
        pinMode(top[i], OUTPUT);
    }
}

int current_light = 0;
void loop()
{
    for (int i = 0; i < 3; i++)
    {
        if (current_light % 3 == i)
        {
            digitalWrite(top[i], HIGH);
        }
        else
        {
            digitalWrite(top[i], LOW);
        }
    }
    delay(times[current_light % 3]);
    current_light++;
}