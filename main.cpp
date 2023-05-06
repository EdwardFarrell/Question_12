/* The mbed application board has a 3-axis accelerometer with an I2C interface. An accelerometer
measures the acceleration on its own body. The angle of the accelerometer in any of the axes can be measured.
This experiment changes the LED Red, Green and Blue based on change in X, Y and Z direction*/
#include "mbed.h"
#include "MMA7660.h" // header file I2C

MMA7660 MMA(p28, p27); //I2C Accelerometer
PwmOut r (p23);
PwmOut g (p24);
PwmOut b (p25);




int main() 
{
       
     while(1)
      {
                 
         float x= MMA.x(); // acceleration along x axis
         float y= MMA.y(); // acceleration along y axis
         float z= MMA.z(); // acceleration along z axis
         //Based on the values of x, y and z, LED's R,G and B colour intensity varies
         r = 1.0 - ((x < 1.0) ? 1.0 - x : (x > 2.0) ? x - 2.0 : 0.0);
            g = 1.0 - ((y < 1.0) ? y : (y > 2.0) ? 0.0 : 2.0 - y);
            b = 1.0 - ((z < 1.0) ? 0.0 : (z > 2.0) ? 3.0 - z : z - 1.0);
         

      }
}
