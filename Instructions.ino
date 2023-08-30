/* INSTRUCTIONS FOR THIS PROJECT BELOW! 

Materials needed: 
*most of these will be available in an arduino kit you can purchase from amazon!
- Arduino (I used an arduino MEGA)
- breadboard 
- electrical wires 
- LED lights (for this project, I used 4 and 1 rgb LED, but you can use as many as you'd like) 
- 220 ohm resistors (one for each regular LED light)
- 330 ohm resistors (one for each RGB pin + one for the buzzer)
- 1k ohm resistor (for the LCD)
- LCD (liquid crystal display)
- potentiometer (controls the brightness of the lcd)
- buzzer 
- button 

Instructions
Step 1: Set up the breadboard 
- plug in a wire (I recommend you colour code these as it will make the process much easier) into the negative rail of the breadboard (this is usually blue)
- now plug that wire into the ground port of your arduino (it will say GND)
- take another wire and plug that into the positive rail of the breadboard (usuall red)
- plug that wire into the 5V port on your arduino
*now the breadboard is connected to a ground port and a power source, so we don't have to plug in anymore wires into a ground or power port

Step 2: Attach LiquidCrystal Display 
- take your LCD and plug it into the breadboard, it doesn't really matter where, just make sure there is enough room on the rest of the breadboard
- plug in your potentiometer into the breadboard as well 
- grab a wire and attach it to the same coloumn as the GND pin on the LCD, and plug this wire into the negative railing (the same one as the first ground wire we put in)
- grab another wire and plug it into the column next to the GND pin called VDD. Plug this wire into the positive railing to supply power 
*moving along the pins of the LCD
- plug another wire into VO of the LCD, and this wire will be plugged into the same column as the middle pin of the potentiometer 
- plug a wire into the same column as RS and plug this into port 12 on the arduino
- plug a wire into the same column as RW and plug this into the negative railing 
- plug a wire into the same column as E and plug this into port 11 
*skip 4 pins over 
- plug a wire into the same column as D4 and plug this into port 5 
- plug a wire into the same column as D5 and plug this into port 4 
- plug a wire into the same column as D6 and plug this into port 3 
- plug a wire into the same column as D7 and plug this into port 2
- grab a 1k ohm resistor and plug it into the same column as BLA and plug this into the positive railing 
- plug a wire into the same column as BLK and plug this into the negative railing 
Next for the potentiometer 
- plug a wire into on the sides of the potentiometer that contains a pin, and plug this into the negative railing 
- do the same on the remaining pin but to the positive railing

Step 3: The buzzer 
*please note that the longer pin of the buzzer is the positive end
- plug the buzzer anywhere on the breadbord, keep track of which pin is positive/negative 
- grab a 330 ohm resistor and plug this into the same column as the positive pin **if you use a resistor less than 330 ohm, it will be really loud
- plug the other end of that resistor somewhere on the breadboard 
- plug a wire into the same column as that^ end of the resistor and plug it into port 38 on the arduino 
- plug another wire into the negative pin column and plug that into the negative railing

Step 4: The button 
- place the buzzer split between the 2 sides of the breadboard (2 pins on each side)
- plug one wire in the same column as one of the pins and plug it into the positive railing 
- plug another wire in the same column as the other pin and plig it into port 22 on the arduino 
- place a 220 ohm resistor in the same column as the previous wire and connect it to the negative railing 

Step 5: The LED lights
**please not that the longer pin of the LED is the positive one 
- plug in your LED lights into your breaboard anywhere you'd like (keep track of the negative and positive ends) 
- connect a 220 ohm resistor from the negative pin of each LED to the negative railing of the breadboard (do this for each LED)
- then connect a wire from the same column as the positive pin to a port on the arduino 
**for red I used port 24, yellow 26, green 28, blue 30
FOR THE RGB LED 
**if you take a look at the RGB LED you will see it has 4 pins. The longest pin is the ground pin, the one to the left is red, and the two to the right are green & blue
- connect a wire from the ground pin to the negative railing 
- connect a 330 ohm resistor to each pin of the RGB LED and connect each of those somewhere on the breadboard 
- lastly connect a wire to each of those resistors and plug them into a port in the arduino 
**For red I used port 32, green, 34, blue, 36

Please have a look at the code I have provided and make any changes to it to fit your board
Plug in your USB, upload the code & done! 

*/
