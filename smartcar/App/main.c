#include "common.h"
#include "include.h"

void main()
{
    _gpio_init(); 
    ADC_init();
   _display_init();
    SCCB_init();
    variable_init();
    FTM_init();
    PIT_init();   
    EnableInterrupts;

    while(1)
    {
        LCD_Fill(0x00);
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
        LCD_P6x8float(70,5,pid.D);






      //Draw_BMP(0, 0, 80, 7, imageBMP[0]);

              
    }
}