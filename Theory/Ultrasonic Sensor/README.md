![Robotics club](https://socialify.git.ci/Robotics-Club-BMU/Ardutronics/image?description=1&forks=1&issues=1&language=1&owner=1&pulls=1&stargazers=1&theme=Light)

# Ultrasonic Sensor

* An ultrasonic sensor is an instrument that measures the distance to an object using ultrasonic sound waves. 
* The Ultrasonic sensor sends a pulse to the sensor to initiate a reading, then listens for a pulse to return. The length of the returning pulse is proportional to the distance of the object from the sensor & it's high-frequency sound waves reflect from boundaries to produce distinct echo patterns.


![15569-Ultrasonic_Distance_Sensor_-_HC-SR04-01a](https://user-images.githubusercontent.com/58645688/137685231-45eebd3d-4ca8-499c-9a37-a863b090cdbd.jpg)

## Working

* Ultrasonic sensors work by sending out a sound wave at a frequency above the range of human hearing.  The transducer of the sensor acts as a microphone to receive and send the ultrasonic sound. Our ultrasonic sensors, like many others, use a single transducer to send a pulse and to receive the echo.  The sensor determines the distance to a target by measuring time lapses between the sending and receiving of the ultrasonic pulse.
* The working principle of this module is simple.  It sends an ultrasonic pulse out at 40kHz which travels through the air and if there is an obstacle or object, it will bounce back to the sensor.  By calculating the travel time and the speed of sound, the distance can be calculated.



## Example
* I've added a [code](https://github.com/tb-rules10/Ardutronics/blob/branch-2/Theory/Code.ino) where i have connected and ultrasonic sensor to an arduino, led and a buzzer. This circuit is set to make buzzing sound from buzzer when an object somes near ultasonic sensor and also light up the led when it is less than 25 inches away from sensor


![Amazing Uusam-Wluff](https://user-images.githubusercontent.com/58645688/137639645-fc649d1a-2163-44ff-9ed6-431c445dd2bf.png)


[You can also check the simulation by clicking here!](https://youtu.be/DZzotOV-d1E)

