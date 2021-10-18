
# EXP 3: Digital Input with a Pushbutton with Arduino 


***Objective: To take digital input from a push button connected to an arduino to turn an LED on & off resp. on its pressing . LED connected to whole setup. Dropping & raising voltage in the LED on pressing the button would be shown by a voltage multimeter.***

[link of simulation video of the exp](https://drive.google.com/file/d/10O3bvoAbODxiXWn6TA9eeszWnxzI2FzH/view?usp=sharing)

[tinkerlink of Exp](https://www.tinkercad.com/embed/6xIqcW527hg?editbtn=1)


Code:

// C++ code

//

int buttonState = 0;

void setup()

{

pinMode(2, INPUT);

pinMode(LED_BUILTIN, OUTPUT);

}

void loop()

{

// To read the state of push-button

buttonState = digitalRead(2);

// check if the push button is pressed, if it is,

// then the button state is HIGH

if (buttonState == HIGH) {

digitalWrite(LED_BUILTIN, HIGH);

}

else {

digitalWrite(LED_BUILTIN, LOW);

}

delay(10); // Delay a little bit to improve simulation performance

}
---------------------------------------------------
---------------------------------------------------

Explanation:

buttonState: variable to denote the state of pin 2( to which button is connected, whether it is HIGH or LOW), i.e. the button is pressed or not.

Setup part:

pinmode():used to call button on pin 2 as an INPUT pin to get digital output of pressing & the LED on pin 13 as an OUTPUT pin to get its lighting output.

Loop part:

digitalWrite(): reads state of pin 2 as the state of the push button. ie. if the button the pressed , then the pin state is HIGH, else it is LOW.

if buttonState is high:

digitalWrite():sets LED to HIGH(ON)

else:

digitalWrite():sets LED to LOW(OFF)

delay(): Causes delay of 10secs b/w LED ON&OFF for good simulation performance.

//: for diplaying single line comments

/*…*/: to display multi-line comments

{..} : contains loops (i.e. statements which are repeated continuously.