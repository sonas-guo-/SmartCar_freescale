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
    //uart_init(UART3,115200);
    key_init(KEY_A);
    key_init(KEY_B);
    //key_init(KEY_C);
    //key_init(KEY_D);
    while(1)
    {
        //LCD_Fill(0x00);      
        LCD_P6x8Str(10,2,"speed");
        LCD_P6x8int(70,2,setSpeed);
        //LCD_P6x8Str(10,4,"seTheta");
        //LCD_P6x8float(70,4,setTheta);
        if (key_check(KEY_A))
        {
           while(key_check(KEY_A)); 
           setSpeed+=5;
        }
        if (key_check(KEY_B))
        {
           while(key_check(KEY_B));
           setSpeed-=5;
        }
 
       
        LCD_CLS();
        //Draw_BMP(0, 0, 80, 7, lineBMP[0]);
        //Draw_BMP(0, 0, 79, 6, imageBMP[0]);

              
    }
}