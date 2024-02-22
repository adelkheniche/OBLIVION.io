#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN       13 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 15 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/* 
   BlinkLed.ino example file for yasm library.
   
   The purpose of this arduino sketch is to blink a led on pin 13.
   
   It creates a state machine with two states : ledOn, ledOff, 
   and illustrate the use of elapsed(delay_in_ms) timing function to trigger 
   state change.                                                              
*/


#include <yasm.h>	//include the yasm library

#define OnDelay		1000 //500ms led "On" state delay
#define OffDelay	3000 //750ms led "Off" state delay
#define DELAYVAL 5000 // Time (in milliseconds) to pause between pixels

#define LedPin 		6  	// Most Arduino boards have a pin connected to an on-board LED in series with a resistor. 
					// The constant LED_BUILTIN is the number of the pin to which the on-board LED is connected. 
					// Most boards have this LED connected to digital pin 13

YASM led; //declaration of the "led" state machine

void setup()
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.


	pinMode(LedPin, OUTPUT); //declare the led pin as output
	led.next(ledOn); //set the initial state of the led state machine
   pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}

void loop()
{
	led.run();  //update the state machine

}

//////////led state machine/////////////

void ledOn()
if(led.elapsed(OnDelay)) //check if the delay for the "on" state is elapsed
    led.next(ledOff); //if the delay is elapsed we switch to the "off" state
    }

{
   pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL); // Pause before next pass through loop

    
	

}

void ledOff()
{
     pixels.clear(); // Set all pixel colors to 'off' 
     if(led.elapsed(OffDelay)) //check if the delay for the "on" state is elapsed
    led.next(ledOn); //if the delay is elapsed we switch to the "on" state


	 // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=15; i<NUMPIXELS; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(100, 30, 25));

    pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL); // Pause before next pass through loop


    

}}
