/**
 * Arduino Uno FreeRTOS Program where an Inertial Measurement Unit (IMU) Sensor captures Roll+Pitch+Yaw data over I2C buss and 
 * streams data to Rasberry Pi over the serial port. 
 * 
 * @author Patrick Radecki
 */

#include <Arduino_FreeRTOS.h>
#include <Adafruit_BNO055.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

// define two tasks for Blink & AnalogRead
void TaskBlink( void *pvParameters );
void TaskReadIMU(void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {
  
  // Initialize serial communication at 9600 bits per second.
  Serial.begin(9600);
 
  Serial.println("Project 8: IMU Data Capture"); Serial.println("");
 
  // Initialize the IMU (BNO055) sensor
  if(!bno.begin())
  {
    // There was a problem detecting the BNO055
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
 
  delay(1000);
 
  bno.setExtCrystalUse(true);
  
  // Set up tasks to run independently.
  xTaskCreate(
    TaskBlink
    ,  (const char *)"Blink"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  1  // priority
    ,  NULL );

  xTaskCreate(
    TaskReadIMU
    ,  (const char *) "ReadIMU"
    ,  128  // Stack size
    ,  NULL
    ,  2  // Priority
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

// Blink built in LED
void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  // initialize built in LED as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(LED_BUILTIN, HIGH);          // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 1000 / portTICK_PERIOD_MS );  // wait for five seconds
    digitalWrite(LED_BUILTIN, LOW);           // turn the LED off by making the voltage LOW
    vTaskDelay( 1000 / portTICK_PERIOD_MS );  // wait for five seconds
  }
}


//  IMUReadSerial
//  Capture the Roll+Pitch+Yaw data from IMU
void TaskReadIMU(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
 
  for (;;)
  {
    // Get a new sensor event
    sensors_event_t event;
    bno.getEvent(&event);
  
    // Display the Yaw, Pitch, Roll data
    Serial.print("Yaw: ");
    Serial.print(event.orientation.x, 4);
    Serial.print("\tPitch: ");
    Serial.print(event.orientation.y, 4);
    Serial.print("\tRoll: ");
    Serial.print(event.orientation.z, 4);
    Serial.println("");
     
    vTaskDelay(10);  // 10 tick delay in between reads for stability
  }
}
 
// Read value from Analog port
void TaskAnalogRead(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  for (;;)
  {
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    // print out the value you read:
    Serial.println(sensorValue);
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}
