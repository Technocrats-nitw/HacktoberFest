/*
'-------------------------------------------------------------------------------
'--------------------------------------------------------------------------------
'Name                     : Light Follower using three Sensors
'Project                  : To Program the Robot to follow the Light using Microcontroller
'Event                    : Hacktoberfest-2021


'Reference Connections.........
'[MOors]
'MOor1-MO1(PIN 4 , PIN 5)
'MOor2-MO2(PIN 6 , PIN 7)

'[LCD]
'DB4-PIN 8........ RS- PIN 13........
'DB5-PIN 9........ E  -PIN 12........
'DB6-PIN 10....... DB7-PIN 11........

'[SENSORS]
'SENSOR1(LEFT SENSOR) -PIN A0.......
'SENSOR2(MID SENSOR)  -PIN A1.......
'SENSOR3(RIGHT SENSOR)-PIN A2.......

'Operation
'ROBOT FOLLOWS LIGHT
'--------------------------------------------------------------------------------*/




#include <LiquidCrystal.h>                                                              // Include the Library for LCD

LiquidCrystal lcd(13, 12, 11, 10, 19, 18);                                                // Define the pin connections of Board for LCD      
int MO11 = 2;                                                                          // Defining the Controller pins for MOors
int MO12 = 3;
int MO22 = 4;
int MO21 = 5;
int leftsensor = 0;                                                                     // Defining the integers to store the Sensors output  
int middlesensor = 0;  
int rightsensor = 0;  

void setup()                                                                            // Start of the Set up Loop  
{  
  pinMode(MO11, OUTPUT);                                                               // Setting the pins connected to MOors as output pins
  pinMode(MO12, OUTPUT);
  pinMode(MO21, OUTPUT);
  pinMode(MO22, OUTPUT);

   lcd.begin(16, 2);                                                                    // Configuring the 16*2 as type of LCD
  lcd.setCursor(0, 0);                                                                  // Displaying the name of the Robot on LCD
  lcd.print("Light Follower");
  delay(3000);
  lcd.clear();                                                                          // Clear the LCD after waiting for 3 Seconds
}  
  
void loop()                                                                             // Start of the Main Loop
{  
  
   leftsensor=analogRead(A1);                                                           // Store each Sensors output on their specific integers  
   middlesensor=analogRead(A2); 
   rightsensor=analogRead(A3);
   
   if(leftsensor < 100)                                                                // If light is falling on Left Sensor then program the Robot to turn Right
    {  
       lcd.clear(); 
       lcd.setCursor(0, 0);
       lcd.print("Turn Left");                                                          // Display the direction of Robot on LCD
 
       digitalWrite(MO11, LOW);  
       analogWrite(MO12, 0);                                                           // Move only Right MOor so that Robot could turn Left
       analogWrite(MO21, 150); 
       digitalWrite(MO22, LOW); 
    }
   
    else if(middlesensor < 100)                                                        // Else if the light is falling on the Middle Sensor then programm the Robot to Move Forward
    {  
       lcd.clear(); 
       lcd.setCursor(0, 0);
       lcd.print("Forward");                                                            // Display the Direction of Robot on LCD   
 
       digitalWrite(MO11, HIGH);  
       analogWrite(MO12, 105);                                                         // Move both the MOors in Forward Direction so thst Robot could move Forward
       analogWrite(MO21, 150); 
       digitalWrite(MO22, LOW);
       
    }
   

    else if(rightsensor < 100)                                                         // Else if the Light is falling on the Right Sensor then program the Robot to turn Right 
    {  
       lcd.clear(); 
       lcd.setCursor(0, 0);
       lcd.print("Turn Right");                                                         // Display the Direction of Robot on LCD  
 
       digitalWrite(MO11, HIGH);  
       analogWrite(MO12, 105);                                                         // Move the Left MOor in Forward Direction so that the Robot could Turn Right
       analogWrite(MO21, 0); 
       digitalWrite(MO22, LOW); 
    }
      else                                                                              // Else make the Robot Stand on its position
    {  
       lcd.clear(); 
       lcd.setCursor(0, 0);
       lcd.print("Stop");                                                               // Display "Stop" on LCD    
 
       digitalWrite(MO11, LOW);  
       analogWrite(MO12, 0);                                                           // Stop both the MOors of the Robot
       analogWrite(MO21, 0); 
       digitalWrite(MO22, LOW); 
    }  
delay(100);    
    
}                                                                                       // End of Main Loop    
