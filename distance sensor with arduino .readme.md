
# Ultrasonic Distance Sensor in Arduino with Tinkercad

**Objective** : *To measure distance of an object near an arduino up to a specific distance using an ultrasonic distance sensor which uses ultrasonic sound waves to measure distance and uses analog output of the sound waves to give accurate distance output; and to also plot a graph of the distance travelled by the object .*

 [Simulation video link of the exp](https://drive.google.com/file/d/10RIIE5rGQ1jnC_iLwuwlixG84if9KrBl/view?usp=sharing)

 [tinkerlink of exp](https://www.tinkercad.com/embed/8X98pwK98qd?editbtn=1)

 >// C++ code
//
/*
Code for measuring distance using arduino &
distance sensor
*/
>long readUltrasonicDistance(int triggerPin, int echoPin)
>{

>pinMode(triggerPin, OUTPUT); // Clear the trigger

>digitalWrite(triggerPin, LOW);

delayMicroseconds(2);

// Sets the trigger pin to HIGH state for 10 microseconds

digitalWrite(triggerPin, HIGH);

delayMicroseconds(10);

digitalWrite(triggerPin, LOW);

pinMode(echoPin, INPUT);
// Reads the echo pin, and returns the sound wave travel time in microseconds

>return pulseIn(echoPin, HIGH);
}
>void setup()

>{
Serial.begin(9600);
}
void loop()
>{
Serial.println(0.01723 * readUltrasonicDistance(11, 10));
delay(500); // Wait for 500 millisecond(s)
}


**Explanation:**

>triggerPin(): variable that stores the analog outputs of the trigger in of distance sensor & monitors its state.

>echoPin(): variable that stores the intputs of the trigger in of distance sensor & monitors its state.

reading the trigger pin & the echo pin {of distance sensor & send & receive analog output & input from them} part:

long readUltrasonicDistance(): reads the state of trigger pin & echo pin of the distance sensor & to receive and display the output & input of the resp. pin as an integer.
>digitalWrite():sets trigger pin as OUTPUT {to release ultrasonic signal} , first sets it at LOW to clear the trigger, then after 2 µs, again sets it to HIGH for 10µs to send signal then again turns it off.

>pinmode(): used to call the echo pin of the distance sensor as an INPUT pin to receive the analog input of reflected back ultrasonic waves from the object whose distance is to be measured.

return pulseIn(): Reads the echo pin, and returns the sound wave travel time in microseconds (µs).
Setup part:
Serial.begin(): Makes the serial monitor ready for printing output.

>Loop Part:
Serial.println(0.01723 * readUltrasonicDistance(11, 10)); =used to convert and print the outputs of distance sensor’s trigger & echo pins {in time travelled in microseconds}at pins 11&10 resp. of arduino to corresponding distance of the object from the distance sensor. Each value is printed in a new line.
>delay(500)=used to delay the printing of distances on the serial monitor by 500 µs/0.5sec for convenience of the simulation of the program.

//: for displaying single line comments
>/*…*/: to display multi-line comments
{..} : contains loops (i.e. statements which are repeated continuously.*
