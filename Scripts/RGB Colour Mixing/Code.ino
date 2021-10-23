#define LEDR 11
#define LEDG 12
#define LEDB 13

void setup() {                
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

int r = 0;
int g = 0;
int b = 0;
void loop() {
  r = random(0, 255);     // to store a random colour
  g = random(0, 255);
  b = random(0, 255);
  analogWrite(LEDR, r);     
  analogWrite(LEDG, g);
  analogWrite(LEDB, b);
  delay(1000);
  /* above lines will make the rgb glow in different colours */
}
