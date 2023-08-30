//This code is written to help with visualization of what exactly is going on. Version 1
//Shorter & more advanced versions of this code are on my github as well!

#include <LiquidCrystal.h> //because we will be using the LCD (liquid crystal display) we need to include this library

//First we need to declare our variables, which in this case are the components we have attached to the breadboard
//we use "const int" because it ensures that the value of these LED lights won't change. The value is the port that it is plugged into. 
//these values can vary, depending on what port you plug each LED into, it doesn't really matter which port, these are the ports that correspond to the instructions. 

const int redLED = 24, yellowLED = 26, greenLED = 28, blueLED = 30, RGBred = 32, RGBgreen = 34, RGBblue = 36; 
//next we will declare variables for the buzzer and the button. We will use const int again for the same reason we did for the LEDs
const int button = 22, buzzer = 38; 
//with these variables below, we will use "int" and not "const int", as they will be implemented into a loop later in the program, and are subject to change. 
//We will initzialize these both to 0, which will make sense later when it appears in the loop 
int blink = 0, blinkmore = 0; 
//finally for declarations we need to use the lcd function for the screen display. As mentioned in the setup, you can plug these wires in any port.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //these are the power ports for the lcd. whichever ports you have plugged them into, you must go in descending order 

//We are now done with declarations, and can move onto the rest of the code!

void setup() {
  //here we are setting up each piece we attached to the board 
  //if the piece will output something, for example the LEDs will output light, we write pinMode(piecename, OUPUT)
  //the same thing goes for input. For example, the button we press will gives commands to the computer to start running the code 
  pinMode(redLED, OUTPUT); 
  pinMode(yellowLED, OUTPUT); 
  pinMode(greenLED, OUTPUT); 
  pinMode(blueLED, OUTPUT); 
  pinMode(RGBred, OUTPUT); 
  pinMode(RGBgreen, OUTPUT); 
  pinMode(RGBblue, OUTPUT); 
  pinMode(buzzer, OUTPUT); 
  pinMode(button, INPUT); 
  lcd.begin(16, 2); //you must put this here because we used liquidcrystal library
  Serial.begin(9600); //same with this 
}

//We are now done with the setup, and we can move onto the code that gives commands to the board!

void loop() {
  //Because we want our project to start when we press the button (not just when we connect to the computer) we need to first write code that will tell the board to do so 
  //I used while loops for this program as they help you visualize what is going on. See version 2 for "for loops"
  if(digitalRead(button) == HIGH){ //this essentially says "if the button is pressed, continue executing the code"
    delay(500); //the code will delay for 0.5 seconds, the delay function is in miliseconds 
    while(blink < 4){ //the blink variable we declared as 0 will be used to keep track of how many times this LED blinks 
      if(blink == 0){ //before the first blink, "ignition seq." will print on the lcd 
        lcd.setCursor(0,0);
        lcd.print("Ignition Seq.");
      }
      digitalWrite(redLED, HIGH); //now the red LED will turn on
      tone(buzzer, 1000); //the buzzer will turn on 
      delay(100); //this will happen for 0.1 seconds 
      digitalWrite(redLED, LOW); //now the red LED will turn off
      noTone(buzzer); //the buzzer will also turn off
      delay(100); //this will happen for 0.1 seconds
      blink++; //because we are in a loop, we will increment the blink variable. This is the same as saying blink = blink + 1;
    }
    digitalWrite(redLED, HIGH); //turn red LED on and keep it on 
    lcd.setCursor(0,1); //set lcd to print on the bottom line only
    lcd.print("Start"); //print start on the lcd 
    tone(buzzer, 1000); //the "tone" function will make the buzzer go off. This value can change, but I have picked 1000 for simplicity 
    delay(1000); //keep this for 1 seconds 
    noTone(buzzer); //turn off the buzzer
    delay(2000); //delay for 2 seconds, the light will still be on! 
    lcd.clear(); //clear the lcd 
    //We need to repeat this process for the rest of the LED lights. Any notes indicate something is had to be changed 
    digitalWrite(yellowLED, HIGH); 
    lcd.setCursor(0,0); //because we had set lcd.setCursor to (0,1) it will only print on the bottom of the lcd. we need to change it back
    lcd.print("Level 2: Reached"); 
    tone(buzzer, 1000); 
    delay(1000); 
    noTone(buzzer); 
    delay(2000); 
    lcd.clear(); 
    //for the rest of the LED lights, we do not have to set lcd.setCursor 
    digitalWrite(greenLED, HIGH); 
    lcd.print("Level 3: Reached"); 
    tone(buzzer, 1000); 
    delay(1000); 
    noTone(buzzer); 
    delay(2000); 
    lcd.clear(); 

    digitalWrite(blueLED, HIGH); 
    lcd.print("Max Level"); 
    tone(buzzer, 1000); 
    delay(1000); 
    noTone(buzzer); 
    delay(50); 
    lcd.clear(); 
    //now moving on to the rgb LED
    lcd.print("Congratulations!"); 
    while(blinkmore < 3){
      digitalWrite(RGBred, HIGH); 
      tone(buzzer, 1000); 
      delay(100); 
      digitalWrite(RGBred, LOW); 
      noTone(buzzer); 
      delay(100);
      digitalWrite(RGBgreen, HIGH); 
      tone(buzzer, 1000); 
      delay(100); 
      digitalWrite(RGBgreen, LOW);
      noTone(buzzer); 
      delay(100); 
      digitalWrite(RGBblue, HIGH);
      tone(buzzer, 1000);  
      delay(100); 
      digitalWrite(RGBblue, LOW);
      noTone(buzzer);  
      delay(100); 
      blinkmore++; 
    }  
    lcd.clear(); 
    digitalWrite(RGBred, HIGH); 
    tone(buzzer, 1000); 
    lcd.print("Shutting Off"); 
    delay(1000);
    lcd.clear(); 
    noTone(buzzer); 
    digitalWrite(RGBred, LOW); 
    digitalWrite(blueLED, LOW); 
    digitalWrite(greenLED, LOW); 
    digitalWrite(yellowLED, LOW); 
    digitalWrite(redLED, LOW); 
  }
}