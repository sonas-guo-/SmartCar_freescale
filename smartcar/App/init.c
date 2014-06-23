#include "init.h"
#include "include.h"


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

void variable_init()
{
    memset(&pid,NULL,sizeof(pid));
    pid.P=130;
    pid.D=4;
    
    
    calcAngle();
    theta2=theta1;
    angle=theta1;

}

void _init()
{   
    _gpio_init(); 
    _display_init();
    
    FTM_PWM_init(FTM0,FTM_CH0,20*1000,0);//leftMotorDeadDutyA:350
    FTM_PWM_init(FTM0,FTM_CH1,20*1000,0);//leftMotorDeadDutyB:570
    FTM_PWM_init(FTM0,FTM_CH2,20*1000,0);//rightMotorDeadDutyA:550
    FTM_PWM_init(FTM0,FTM_CH3,20*1000,0);//rightMotorDeadDutyB:360
    
    gpio_init(PTB1,GPO,1);
    gpio_init(PTB2,GPO,1);
  
  
   // FTM_QUAD_Init(FTM1);
   // FTM_QUAD_Init(FTM2);
    
    pit_init_ms(PIT0,5);
    set_vector_handler(PIT0_VECTORn,PIT0_IRQHandler);
    enable_irq(PIT0_IRQn);



    adc_init(ADC1_DP0);//w
    adc_init(ADC0_SE17);//z



    variable_init();
}