#include "include.h"
void menuDisplay()
{
        /* LCD_Fill(0x00);
        LCD_P6x8Str(10,0,"Angle");
        LCD_P6x8float(70,0,angle);

        LCD_P6x8Str(10,1,"ZOUT");
        LCD_P6x8int(70,1,zout);

        LCD_P6x8Str(10,2,"ZOUT_zero");
        LCD_P6x8int(70,2,zbase);

        LCD_P6x8Str(10,3,"setTheta");
        LCD_P6x8float(70,3,set_theta);

        LCD_P6x8Str(10,4,"angle_P");
        LCD_P6x8float(70,4,pid.P);

        LCD_P6x8Str(10,5,"angle_D");
        LCD_P6x8float(70,5,pid.D);*/

}
void _display()
{
      LCD_Fill(0x00);      
      
      LCD_P6x8Str(10,2,"ZOUT:"); 
      zout=adc_mid(ADC0_SE17,ADC_12bit);
      LCD_P6x8int(50,2,zout);

      LCD_P6x8Str(10,4,"W:");
      wout=adc_mid(ADC1_DP0,ADC_12bit);
      LCD_P6x8int(50,4,wout);
      
      LCD_P6x8Str(10,5,"theta1:");
      LCD_P6x8int(50,5,theta1);
    
      //delay();

      LCD_CLS();
}