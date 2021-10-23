#include <IRremote.h>

#define MOTOR_1 5
#define MOTOR_2 6
#define MOTOR_3 9
#define MOTOR_4 10
#define BTN_POWER_1 0xFD00FF
#define GAS 0xFD50AF
#define SLOW 0xFD10EF

int MOTORS[] = {MOTOR_1, MOTOR_2, MOTOR_3, MOTOR_4};
int MOTOR_SPEED = 0;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
    Serial.begin(9600);
    // In case the interrupt driver crashes on setup, give a clue
    // to the user what's going on.
    Serial.println("Enabling IRin");
    irrecv.enableIRIn(); // Start the receiver
    Serial.println("Enabled IRin");
    for (int i = 0; i < 4; i++)
        pinMode(MOTORS[i], OUTPUT);
}

void motors_speed(int speed)
{

    for (int i = 0; i < 4; i++)
    {
        analogWrite(MOTORS[i], speed);
    }
}

void loop()
{
    if (irrecv.decode(&results))
    {
        Serial.println(results.value, HEX);
        if (results.value == BTN_POWER_1)
        {
            if (MOTOR_SPEED != 0)
                MOTOR_SPEED = 0;
            else
                MOTOR_SPEED = 255;
            Serial.println("Switching Motors on/off");
        }

        if (results.value == GAS)
        {
            //Increase the speed!
            if (MOTOR_SPEED < 255)
            {
                MOTOR_SPEED += 25;
                Serial.println("Increasing the speed by 5!");
            }
            else
                Serial.println("Cannot increase speed, already at full!");
        }
        if (results.value == SLOW)
        {
            //Decrease the speed
            if (MOTOR_SPEED > 0)
            {
                MOTOR_SPEED -= 25;
                Serial.println("Decreasing the speed by 5!");
            }
            else
                Serial.println("Cannot decrease speed, motor a!");
        }
        irrecv.resume(); // Receive the next value
    }

    motors_speed(MOTOR_SPEED);

    delay(100);
}
