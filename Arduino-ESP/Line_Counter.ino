/*
'-------------------------------------------------------------------------------
'-------------------------------------------------------------------------------
'Name                     : Line Counter 
'Type                     : Opensource Project Hacktoberfest-2021
'Project                  : To Program the Robot to count White Lines on Dark Surface using Microcontroller
'Microcontroller          : Atmega128P PU(Arduino Uno)
           
		        HAPPY HACKTOBERFEST
--------------------------------------------------------------------------------

'Reference Connections.........
'[Motors]
'Motor1-MT1(PIN 4 , PIN 5)
'Motor2-MT2(PIN 6 , PIN 7)

'[LCD]
'DB4-PIN 8........ RS- PIN 13........
'DB5-PIN 9........ E  -PIN 12........
'DB6-PIN 10....... DB7-PIN 11........

'[SENSORS]
'SENSOR1  -PIN A0.......

'Operation
'ROBOT COUNTS WHITE LNES AND DISPLAYS IT ON LCD
'--------------------------------------------------------------------------------*/





#include <LiquidCrystal.h>                                                              // Include the Library for LCD

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);                                                // Define the pin connections of Board for LCD      
int MOT11 = 4;                                                                          // Defining the Controller pins for Motors
int MOT12 = 5;
int MOT21 = 6;
int MOT22 = 7;

int parity = 0;                                                                         // Define an integers to store the count and set the parity
int count = 0;
int sensorValue = 0;                                                                    // Define an integer to store the Sensor's output

void setup()                                                                            // Start of the Set up Loop  
{  
  pinMode(MOT11, OUTPUT);                                                               // Setting the pins connected to Motors as output pins
  pinMode(MOT12, OUTPUT);
  pinMode(MOT21, OUTPUT);
  pinMode(MOT22, OUTPUT);

  lcd.begin(16, 2);                                                                     // Configuring the 16*2 as type of LCD
  lcd.setCursor(0, 0);                                                                  // Displaying the name of the Robot on LCD
  lcd.print("Line Counter");
  delay(3000);
  lcd.clear();                                                                          // Clear the LCD after waiting for 3 Seconds
}  
  
void loop()                                                                             // Start of the Main Loop
{  
  
  digitalWrite(MOT11, LOW);  
  analogWrite(MOT12, 150);                                                              // Move both the Motors in Forward Direction so that the Robot Could move Forward
  analogWrite(MOT21, 150); 
  digitalWrite(MOT22, LOW); 

  sensorValue=analogRead(A0);                                                           // Read and Store the Sensors output in soecific Integer
   
  if(sensorValue <= 600 && parity == 0)                                                 // If the Sensor detects whit Line and parity is 0 then perform the given loop  
    {
      count = count + 1;                                                                // increase the lines count by 1 and set parity as 1     
      parity = 1;  
      sensorValue = analogRead(A0);                                                     // Read and Store the Sensors output in soecific Integer
    }
     
  if(sensorValue >= 600 )                                                               // If the Sensor is not detecting any line then make the parity 0
    {
       parity = 0; 
    } 
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("Count = ");                                                                // Display "Count = " on LCD

  lcd.setCursor(8, 0);
  lcd.print(count);                                                                     // Display number of Lines counted on LCD  
  delay(100);    
    
}                                                                                       // End of the Main Loop 
