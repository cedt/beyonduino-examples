
#include <math.h>

void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  float val = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
  analogWrite(3, val);
}


/* The Arduino supports analog output using pulse-width modulation (PWM) mapped to integer values from 0 to 255. To recreate the breathing LED, 
this means manipulating the original equation f(x) = esin(x) such that the amplitude fits within the PWM range.

I took enough math in school to know that the minima and maxima of any equation occur at critical points in the equation, 
where the derivative of that equation is either 0 or its not differentiable. Beyond that, I left it to Wolfram Alpha to do the hard work. 
It turns out that the minimum of the wave occurs at 1 - e, and the maximum at e - 1/e.
Using this information to adjust the amplitude of the equation such that it fits within the 0 to 255 range gives the following:

(exp(sin(x))-1/e)*255/(e-1/e)

Swap x for the number of seconds that have elapsed, and map the above equation to PWM output on any supported Arduino pin, 
and you have the beginnings of a breathing pattern. The problem is that the frequency may be too high or low (depending on your preference),
and so the breathing will appear fast or slow. Easy enough: Multiply x by any value to adjust the frequency. I like π/2.

Finally, 1 - e, and 255/(e - 1/e) are constants, and can be pre-calcuated to reduce overhead.
