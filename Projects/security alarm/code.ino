int ledPin =5;
int Buzzer = 6; // choose the pin for the Buzzer
int inputPin = 2; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
 
void setup() {
pinMode(ledPin, OUTPUT); // declare LED as output
pinMode(Buzzer, OUTPUT); // declare Buzzer as output
pinMode(inputPin, INPUT); // declare sensor as input
 
Serial.begin(9600);
}
 
void loop(){
val = digitalRead(inputPin); // read input value
int value_ldr = analogRead(A0); // read LDR value
 
if((300>value_ldr) && ( val==HIGH) ){
if (val == HIGH) { // check if the input is HIGH
digitalWrite(ledPin, HIGH); // turn LED ON
digitalWrite(Buzzer, 1); // turn Buzzer ON
delay(5000);
if (pirState == LOW) {
// we have just turned on
Serial.println("Motion detected!");
// We only want to print on the output change, not state
pirState = HIGH;
}
} else {
digitalWrite(ledPin, LOW); // turn LED OFF
digitalWrite(Buzzer, 0); // turn Buzzer OFF
if (pirState == HIGH){
// we have just turned of
Serial.println("Motion ended!");
// We only want to print on the output change, not state
pirState = LOW;
}
}
}
}