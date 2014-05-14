#include "init.h"

void _gpio_init()
{
    gpio_init (PTD11,GPO , 1);
    gpio_init (PTD12,GPO , 1);
    gpio_init (PTD13,GPO , 1);
    gpio_init (PTD14,GPO , 1);
}


void _display_init()
{
   LCD_Init(); 
}

void _init()
{
   _gpio_init(); 
   _display_init();
   adc_init(ADC0_SE16);//y
   adc_init(ADC1_DM0);//x
   adc_init(ADC1_DP0);//w
   adc_init(ADC0_SE17);//z
   adc_init(ADC0_SE18);//angle
}