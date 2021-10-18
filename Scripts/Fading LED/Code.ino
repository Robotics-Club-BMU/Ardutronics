// C++ code
//
// Fading LED
void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  int i=0;
  for(i=0; i<=255; i++){
    analogWrite(11, i);
    delay(5);
  }
  
  delay(500);
  for(i=255; i>=0; i--){
    analogWrite(11, i);
    delay(5);
  }
  delay(500);
}
