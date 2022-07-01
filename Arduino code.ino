#include<Servo.h>              // including the servo library in our project
 
int LED_b = 12;               // set the input pin for LEDs
int LED_r = 10;
int Incoming_value = 0;           // initialize the flag variable for bluetooth input
int pin_motor = 8;              // set the input pin for the servo motor
Servo servo;                  // initializing an object of the Servo class 

void setup()
{
  Serial.begin(9600);               
  pinMode(LED_b, OUTPUT);         // fixing the LED_b pin for outputting data
  pinMode(LED_r, OUTPUT);         // fixing the LED_r pin for outputting data
  pinMode(pin_motor, OUTPUT);       // fixing the servo pin for outputting data
  servo.attach(pin_motor);        // attaching the servo at pin "pin_motor"
  servo.write(0);             // set the servo at 0 degrees
}

void loop() 
{
    if(Serial.available()>0)          // checks if the bluetooth module is attached to the Rx and Tx pin properly
    {                                 // by returning a particular number of bytes
        Incoming_value = Serial.read();      
             
        if(Incoming_value == 1)       // correct fingerprint inputted
        { 
            for(int i=0;i<1;i++)      // produces a particular lighting effect
            {
                digitalWrite(LED_b,HIGH);
                digitalWrite(LED_r,HIGH);
                delay(500);
                digitalWrite(LED_b,LOW);
                digitalWrite(LED_r,LOW);
                delay(500);
            }
            servo.write(90);        // set the servo at 90 degrees
            delay(5000);          // wait for 5 seconds
            servo.write(0);         // resets the servo at 0 degrees

        }
        else if(Incoming_value == 0)        // incorrect fingerprint inputted
        {
            for(int i=0;i<8;i++)      // produces a particular lighting effect
            {
                digitalWrite(LED_r,HIGH);
                delay(60);
                digitalWrite(LED_r,LOW);
                digitalWrite(LED_b,HIGH);
                delay(60);
                digitalWrite(LED_b,LOW);     
            }
        }
    }
}
