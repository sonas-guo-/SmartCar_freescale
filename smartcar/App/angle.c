#include "include.h"
#include <math.h>
#define pi 3.1415

void calcAngle()
{
    int zNow=0;//当前的z值
    float angle;
    for (int i=0;i<10;i++)
    {
      zNow+=adc_mid(ADC0_SE17,ADC_12bit);
    }
      zNow/=10;

    if (zbase-zNow>GravityD)
    angle=800;
    else if (zbase-zNow<-GravityD)
         angle=-800;
         else angle=(float)(zbase-zNow)/GravityD;

    theta1=asin(angle)/pi*180;
    
}