// DEFINING PUSH BUTTONS
int Sa = 2;
int Re = 3;
int Ga = 4;
int Ma = 5;
int Pa = 6;
int Dha = 7;
int Ni = 8;
int Saa = 9;
// DEFINING BUZZER
int buzzer = 13;

void setup()
{
  // DECLARING BUTTON PINS AS INPUT
  pinMode(Sa,INPUT);
  pinMode(Ri,INPUT);
  pinMode(Ga,INPUT);
  pinMode(Ma,INPUT);
  pinMode(Pa,INPUT);
  pinMode(Dha,INPUT);
  pinMode(Ni,INPUT);
  pinMode(Saa,INPUT);
  // DECLARING BUTTON AS OUTPUT
  pinMode(buzzer,OUTPUT);
  
}

void loop()
{
  // READ THE VALUES FROM BUTTONS
  int b1 = digitalRead(Sa);
  int b2 = digitalRead(Ri);
  int b3 = digitalRead(Ga);
  int b4 = digitalRead(Ma);
  int b5 = digitalRead(Pa);
  int b6 = digitalRead(Dha);
  int b7 = digitalRead(Ni);
  int b8 = digitalRead(Saa);
  
  if( b1 == 1 ){
     tone(buzzer,240,100);
  }
    if( b2 == 1 ){
     tone(buzzer,270,100);
  }
    if( b3 == 1 ){
     tone(buzzer,300,100);
  }
    if( b4 == 1 ){
     tone(buzzer,337.5,100);
  }
    if( b5 == 1 ){
     tone(buzzer,360,100);
  }
    if( b6 == 1 ){
     tone(buzzer,400,100);
  }
    if( b7 == 1 ){
     tone(buzzer,450,100);
  }
    if( b8 == 1 ){
     tone(buzzer,470,100);
  }
  
// now let's put a short delay for a nice pitch
  delay(10);
  
  
}