#define SENSOR 11

void setup()
{
    pinMode(SENSOR, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int a = digitalRead(SENSOR);
    Serial.println(a);
}
