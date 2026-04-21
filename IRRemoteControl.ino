
// Project 50 - Creating an IR Remote Control Arduino

#include <IRremote.h>
int receiverpin = 2;
IRrecv irrecv(receiverpin);
decode_results results;




void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  for (int z = 3; z < 8; z++)
  {
    pinMode (z, OUTPUT);
  }
}



void translateIR()
{
  switch (results.value)
{
  case 1: pinOn(3); break; //button 1
  case 2: pinOn(4); break; // button 2
  case 3: pinOn(5); break; // button 3
  case 4: pinOn(6); break; // button 4
  case 5: pinOn(7); break; // button 5
}
Serial.println(results.value);
}



void pinOn (int pin)
{
  digitalWrite (pin, HIGH);
  delay (1000);
  digitalWrite (pin, LOW);
}



void loop() 
{
  if (irrecv.decode(&results))
  {
    translateIR();
    for (int z = 0; z < 2; z++)
    {
      irrecv.resume();
    }
  }
}
