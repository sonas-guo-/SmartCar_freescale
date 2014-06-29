#include "init.h"
#include "include.h"


/*****************************
//初始化gpio
*****************************/
void _gpio_init()
{
//oled所用到的port
    gpio_init (PTD11,GPO , 1);
    gpio_init (PTD12,GPO , 1);
    gpio_init (PTD13,GPO , 1);
    gpio_init (PTD14,GPO , 1);
//电机的使能port
    gpio_init(PTB1,GPO,1);
    gpio_init(PTB2,GPO,1);
}
/*****************************
//初始化显示
*****************************/
void _display_init()
{
   LCD_Init(); 
}
/*****************************
//初始化变量，一些全局变量已经被初始化
*****************************/
void variable_init()
{
    memset(&pid,NULL,sizeof(pid));
    pid.P=360;//240
    pid.D=7;
    

    calcAngle();
    theta2=theta1;
    angle=theta1;

}
void PIT_init()
{
  

    //FTM1,FTM2正交解码用
    // FTM_QUAD_Init(FTM1);
    // FTM_QUAD_Init(FTM2);
    pit_init_ms(PIT0,5);
    set_vector_handler(PIT0_VECTORn,PIT0_IRQHandler);
    enable_irq(PIT0_IRQn);

}
void ADC_init()
{
    adc_init(ADC1_DP0);//w
    adc_init(ADC0_SE17);//z
}

void FTM_init()
{   
    

    FTM_PWM_init(FTM0,FTM_CH0,20*1000,0);//leftMotorDeadDutyA:330
    FTM_PWM_init(FTM0,FTM_CH1,20*1000,0);//leftMotorDeadDutyB:590
    FTM_PWM_init(FTM0,FTM_CH2,20*1000,0);//rightMotorDeadDutyA:530
    FTM_PWM_init(FTM0,FTM_CH3,20*1000,0);//rightMotorDeadDutyB:370

}