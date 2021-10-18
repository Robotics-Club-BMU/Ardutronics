// C++ code
//
void setup()
{
  pinMode(11,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int a = digitalRead(11);
  Serial.println(a);

}
