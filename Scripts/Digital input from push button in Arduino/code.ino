#define PSH_BUTTON 2
int buttonState = 0;

void setup()
{
    pinMode(PSH_BUTTON, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    // To read the state of push-button
    buttonState = digitalRead(PSH_BUTTON);
    // check if the push button is pressed, if it is,
    // then the button state is HIGH
    if (buttonState == HIGH)
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW);
    }
    delay(10);
}