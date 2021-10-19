# Light Sensor (Photoresistor)

* Photoresistors, also known as light dependent resistors (LDR), are light sensitive devices most often used to indicate
the presence or absence of light, or to measure the light intensity. In the dark, their resistance is very high, sometimes up to 1 MΩ, but when the LDR sensor is exposed to light, the resistance drops dramatically, even down to a few ohms, depending on the light intensity.
* LDRs have a sensitivity that varies with the wavelength of the light applied and are nonlinear devices. 
They are used in many applications, but this light sensing function is often performed by other devices such as photodiodes and phototransistors.

## Code Explanation

* Firstly, we use `Serial.begin(9600)` function to display the output on the Serial Monitor.
* We read the input given by PIR Sensor to Arduino using `analogRead(A0)` and then display it.
* And then we glow the LED according to the reading given by photoresistor.

## Screenshot

![Photoresistor](https://user-images.githubusercontent.com/58645688/137791415-9759bfe0-6fa5-41c7-b1a3-141c5d650274.png)
