#include "init.h"
#include "include.h"


/*****************************
//初始化gpio
*****************************/
void _gpio_init()
{
//oled所用到的port
    gpio_init (PTD11,GPO , 0);
    gpio_init (PTD12,GPO , 0);
    gpio_init (PTD13,GPO , 0);
    gpio_init (PTD14,GPO , 0);
//电机的使能port
    gpio_init(PTB1,GPO,1);
    gpio_init(PTB2,GPO,1);

//初始化按键
    gpio_init(PTB4,GPI,0);
    gpio_init(PTB5,GPI,0);
    gpio_init(PTB6,GPI,0);
    gpio_init(PTB7,GPI,0);
    gpio_init(PTB8,GPI,0);


//摄像头输入口
    gpio_init(PTD0,GPI,0);
    gpio_init(PTD1,GPI,0);
    gpio_init(PTD2,GPI,0);
    gpio_init(PTD3,GPI,0);
    gpio_init(PTD4,GPI,0);
    gpio_init(PTD5,GPI,0);
    gpio_init(PTD6,GPI,0);
    gpio_init(PTD7,GPI,0);


//拨码盘初始化
    gpio_init(PTC7,GPI,0);
    gpio_init(PTC8,GPI,0);
    gpio_init(PTC9,GPI,0);
    gpio_init(PTC10,GPI,0);
    gpio_init(PTC11,GPI,0);
    gpio_init(PTC12,GPI,0);
    gpio_init(PTC13,GPI,0);
    gpio_init(PTC14,GPI,0);
}
/*****************************
//初始化显示
*****************************/
void _display_init()
{
   LCD_Init(); 
}
/*****************************
//选择拨码盘
*****************************/
void selectDial()
{
    if(gpio_get(PTC14))
    {
        gear=1; 
        setSpeed=-55;
        

        
     }
     else if (gpio_get(PTC13))
     {
        gear=2;
        setSpeed=-50;
        

     }else if (gpio_get(PTC12))
     {
        gear=3;
        setSpeed=-60;
        kPID.P=10;
        leftSpeedPID.D=12;
        rightSpeedPID.D=12;

     }else if (gpio_get(PTC11))
     {
        gear=4; 
     }
     else if (gpio_get(PTC10))
     {
        gear=5; 
     }
     else if (gpio_get(PTC9))
     {
        gear=6; 
     }


}
/*****************************
//初始化变量，一些全局变量已经被初始化
*****************************/
void variable_init()
{
    memset(&anglePID,NULL,sizeof(PID));
    memset(&kPID,NULL,sizeof(PID));
    memset(&bPID,NULL,sizeof(PID));
    memset(&leftSpeedPID,NULL,sizeof(PID));
    memset(&rightSpeedPID,NULL,sizeof(PID));

    anglePID.P=600;//
    anglePID.D=6;   //
    
    leftSpeedPID.P=100;//
    rightSpeedPID.P=100;
    leftSpeedPID.I=0;//
    rightSpeedPID.I=0;
    leftSpeedPID.D=10;//
    rightSpeedPID.D=10;
    

    kPID.P=10;//10
    kPID.D=0;
    bPID.P=32;
    bPID.D=0;



    setSpeed=0;
    calcAngle();
    theta2=theta1;
    angle=theta1;

}
void PIT_init()
{

 
    pit_init_ms(PIT0,5);
    set_vector_handler(PIT0_VECTORn,PIT0_IRQHandler);
    //enable_irq(PIT0_IRQn);


    //pit_init_ms(PIT1,100);
    //set_vector_handler(PIT1_VECTORn,PIT1_IRQHandler);
}
void ADC_init()
{
    adc_init(ADC1_DP0);//w
    adc_init(ADC0_SE17);//z
}

void FTM_init()
{   
    FTM_QUAD_Init(FTM1);
    FTM_QUAD_Init(FTM2);

    FTM_PWM_init(FTM0,FTM_CH0,20*1000,0);//leftMotorDeadDutyA:340
    FTM_PWM_init(FTM0,FTM_CH1,20*1000,0);//leftMotorDeadDutyB:590
    FTM_PWM_init(FTM0,FTM_CH2,20*1000,0);//rightMotorDeadDutyA:530
    FTM_PWM_init(FTM0,FTM_CH3,20*1000,0);//rightMotorDeadDutyB:380

}