#include <NewPing.h>  //Download the NewPing library from https://playground.arduino.cc/Code/NewPing/

#define SONAR_PIN 5  //We will use D5 for both the trig and echo pin.
#define MAX_DISTANCE 200 //Max distance set to 200cm can be up to 400cm

NewPing sonar(SONAR_PIN, SONAR_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int startTime = 0; //Use to monitor the execution time of the main loop
int loopTime = 0; //Use to monitor the execution time of the main loop
int elapsedTime = 0;

int _distance = 0;
    
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200); // Allows us to get results via the Serial Monitor in Arduino IDE
}

void loop() {
    // put your main code here, to run repeatedly:
    startTime = millis();

    delay(1); //Add a 1mS delay otherwise the program will execute too quickly
    if (elapsedTime > 50) //If 50mS has elapsed since last measurement
    {
        _distance = sonar.ping_cm();  //Get the distance measurement
        loopTime = millis() - startTime; //Calculate how long it took to get the measurement
        Serial.print(_distance); //Print the distance out
        Serial.print(",");
        Serial.println(loopTime); //Print the loop time out
        elapsedTime = 0; //Reset elspased time
    }

    loopTime = millis() - startTime; //Calculate the looptime when a measurement is not being taken
    elapsedTime = elapsedTime + loopTime; //Count the elapsed time from when the last measurement was taken
}
