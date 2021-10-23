int LIGHTS[] = {2, 3, 4, 5, 6, 7, 8};
void setup()
{
    for (int i = 0; i < 7; i++)
    {
        pinMode(LIGHTS[i], OUTPUT);
    }
    Serial.begin(9600); //Begin the communication for arduino serial
}

void handle_commands(String command)
{

    int length = command.length();

    if (length == 1 && command[0] == 'L')
    {
        Serial.println("Turning all the lights off");
        for (int i = 0; i < 7; i++)
        {
            digitalWrite(LIGHTS[i], LOW);
            delay(50);
        }
    }

    if (command[length - 1] == 'H')
    {

        Serial.print("Turning the nodes ");
        Serial.print(command);
        Serial.println(" on");

        //first turn all off
        for (int i = 0; i < 7; i++)
        {
            digitalWrite(LIGHTS[i], LOW);
            delay(50);
        }

        //then turn the ones in the command one
        for (int i = 0; i < length - 1; i++)
        {
            digitalWrite(LIGHTS[command[i] - 'A'], HIGH);
            delay(50);
        }
    }
}

void loop()
{
    if (Serial.available())
    {
        String command = Serial.readString();
        handle_commands(command);
    }
}