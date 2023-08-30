//short/more advanced code version 2 is below! :) 
//all loops I've written are "for loops" as they often require less lines of code than while loops
//Please see version 1 of this code if you are confused about anything

#include <LiquidCrystal.h> 

const int redLED = 24, yellowLED = 26, greenLED = 28, blueLED = 30, RGBred = 32, RGBgreen = 34, RGBblue = 36, button = 22, buzzer = 38; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
//In this program we will be writing other functions and calling them in our loop function. 
//this way, we can write less lines of code and avoid redundancy 
//we need to declare our functions here 
void blinky(const char* LED);
void lightsON(const char* LED, int c, const char* text, int sec);

void setup() {
  /*instead of writing out pinMode for each LED, we can use this shortcut that involves an ARRAY. This way, we can write less lines of code.
  The variable "counter" tracks which element of the array we are on. counter++ increments this variable by 1, so we move through the array
  We initialize counter to 0 because the firt element of an array is indexed at 0, not 1.
  "numOuputs" give us the total number of elements in the array.
  
  sizeof(outputs) gives the entire size of the array in bytes, while sizeof(outputs[0]) gives us the size of each element indivdually
  If we divide the entire size of the array by the size of each indivudal array, it will give us the total number of elements. 
  Think about it like a square with x number of equal-size smaller squares that make it up: 
    Ex. Each of these smaller squares has an area of 16, and the total square has an area of 64.
    If we divide 64 by 16 we get 4, and therefore there are a total of 4 squares with an area of 16 that make up this larger square 
  */
  int outputs[] = { redLED, yellowLED, greenLED, blueLED, RGBred, RGBgreen, RGBblue, buzzer};
  int numOutputs = sizeof(outputs) / sizeof(outputs[0]); 
  for(int counter = 0; counter < numOutputs; counter++){ //as long as counter is less than the # of elements in the array, execute the loop 
    pinMode(outputs[counter], OUTPUT); //here it sets each element in the array as an OUTPUT
  }
  pinMode(button, INPUT); 
  lcd.begin(16,2); 
  Serial.begin(9600); 
}

/* Quick note on const char* variablename 
as explained in version 1, we use const to insure that the value cannot be altered 
char* variablename essentially means "variablename is a pointer to the first character in a string"
*/

//We will call this function when we want our lights to blink on and off 
void blinky(const char* LED){
  digitalWrite(LED, HIGH); 
  tone(buzzer, 1000); 
  delay(100); 
  digitalWrite(LED, LOW); 
  noTone(buzzer);
  delay(100); 
}

//we will call this function when we want our lights to turn on and stay on
void lightsON(const char* LED, int c, const char* text, int sec) {
  digitalWrite(LED, HIGH);
  lcd.setCursor(0, c); 
  lcd.print(text); 
  tone(buzzer, 1000); 
  delay(1000); 
  noTone(buzzer); 
  delay(sec); 
  lcd.clear(); 
}

void loop() {
  if(digitalRead(button) == HIGH){ 
    delay(500);
    for(int blink = 0; blink < 4; blink++){ 
      if(blink == 0){ 
        lcd.setCursor(0,0);
        lcd.print("Ignition Seq.");
      }
      blinky(redLED); 
    }
  lightsON(redLED, 1, "Start", 2000); 
  lightsON(yellowLED, 0, "Level 2: Reached", 2000); 
  lightsON(greenLED, 0, "Level 3: Reached", 2000); 
  lightsON(blueLED, 0, "Max Level", 50); 
  lcd.print("Congratulations!"); 
  for(int blinkmore = 0; blinkmore <3; blinkmore++){
    blinky(RGBred); 
    blinky(RGBgreen);
    blinky(RGBblue); 
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