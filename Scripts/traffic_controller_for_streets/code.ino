int times[] = {5000, 2000, 6000};
class Street
{

public:
    int lights[3]; //array to keep track of all the pin numbers!

    Street(int start)
    {
        for (int i = 0; i < 3; i++)
        {
            lights[i] = start + i;
        }
    }

    void setup()
    {
        for (int i = 0; i < 3; i++)
        {
            pinMode(lights[i], OUTPUT); //Setting all the pins to outpput mode
        }
    }

    void light(int choice)
    {
        //Choice 0 for red, 1 for yellow, and 2 for red
        for (int i = 0; i < 3; i++)
        {
            if (i == choice)
                digitalWrite(lights[i], HIGH);
            else
                digitalWrite(lights[i], LOW);
            //Suppose we wanna turn on red light, we have to turn the other lights off
        }
    }
};

Street top(0);
Street right(3);
Street bottom(6);
Street left(9);

Street streets[] = {top, right, bottom, left};
enum colors
{
    red = 0,
    yellow,
    green
};
int current_street = 0;

void setup()
{

    for (int i = 0; i < 4; i++)
    {
        streets[i].setup();
    }

    for (int i = 0; i < 4; i++)
    {
        streets[i].light(red);
    }
}

void loop()
{
    delay(times[red]);
    current_street = current_street % 4;
    //current street should have the green light on!
    for (int i = 0; i < 4; i++)
    {
        if (current_street != i)
        {
            streets[i].light(red);
        }
        else
        {
            streets[i].light(yellow);
            delay(times[yellow]);
            streets[i].light(green);
        }
    }
    delay(green);
    current_street++;
}