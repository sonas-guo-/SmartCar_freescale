#include "include.h"




void _display()
{
      LCD_Fill(0x00);      
      
      LCD_P6x8Str(10,2,"ZOUT:"); 
      zout=adc_mid(ADC0_SE17,ADC_12bit);
      LCD_P6x8int(50,2,zout);

      LCD_P6x8Str(10,4,"W:");
      wout=adc_mid(ADC1_DP0,ADC_12bit);
      LCD_P6x8int(50,4,wout);
      
      calcAngle();
      LCD_P6x8Str(10,5,"theta1:");
      LCD_P6x8int(50,5,theta1);
      

      
      

      delayms(50);
      LCD_CLS();
}