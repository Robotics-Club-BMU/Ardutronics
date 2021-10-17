#define LED 13
int time = 1000;
int increment = 500;
void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  if (Serial.available())
  {
    char output = Serial.read();
    if (output == 'h')
    {
      time += increment;
      Serial.print("Increasing the blinking time, currently set to ");
      Serial.println(time);
    }

    if (output == 'l')
    {
      time -= increment;
      Serial.print("Decreasing the blinking time, currently set to ");
      Serial.println(time);
    }
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(time);
  digitalWrite(LED_BUILTIN, LOW);
  delay(time);
}