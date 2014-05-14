#include "include.h"




void _display()
{
      LCD_Fill(0x00);      
      
     /* LCD_P6x8Str(10,0,"XOUT:");
      xout=adc_mid(ADC1_DM0,ADC_12bit);
      LCD_P6x8int(50,0,xout);
      
      LCD_P6x8Str(10,1,"YOUT:");
      yout=adc_mid(ADC0_SE16,ADC_12bit);
      LCD_P6x8int(50,1,yout);*/
      
      LCD_P6x8Str(10,2,"ZOUT:"); 
      zout=adc_mid(ADC0_SE17,ADC_12bit);
      LCD_P6x8int(50,2,zout);
      
      /*LCD_P6x8Str(10,3,"ANGLE:"); 
      angleout=adc_mid(ADC0_SE18,ADC_12bit);
      LCD_P6x8int(50,3,angleout);*/

      LCD_P6x8Str(10,4,"W:");
      wout=adc_mid(ADC1_DP0,ADC_12bit);
      LCD_P6x8int(50,4,wout);
      
      calcAngle();
      LCD_P6x8Str(10,5,"theta1:");
      LCD_P6x8int(50,5,theta1);


      delayms(50);
      LCD_CLS();
}