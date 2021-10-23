# Potentiometer

* A Potentiometer is a simple knob that provides a variable resistance, which we can read into the Arduino board as an analog value. In this example, that value controls the rate at which an LED blinks.
* We connect three wires to the Arduino board. The first goes to ground from one of the outer pins of the potentiometer. The second goes from 5 volts to the other outer pin of the potentiometer. The third goes from analog input 2 to the middle pin of the potentiometer.

## Code Explanation

* Firstly, we use `Serial.begin(9600)` function to display the output on the Serial Monitor.
* We read the input given by PIR Sensor to Arduino using `analogRead(KNOB)`, map the led power and then display it.
* You can also [click here](https://github.com/tb-rules10/Ardutronics/blob/branch-1/Scripts/Potentiometer/Code.ino) to check the code.

## Screenshot

![Potentiometer](https://user-images.githubusercontent.com/58645688/137880468-6b775f09-614c-4a36-b8f0-76029b991cdd.png)
