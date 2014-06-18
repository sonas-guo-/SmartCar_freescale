#include "include.h"
#include <math.h>
#define pi 3.1415


/*****************************/
/********************
加速度计omega
*******************/
void calcAngle()//
{
    int zNow=0;//
    float angle;
    for (int i=0;i<10;i++)
    {
      zNow+=adc_mid(ADC0_SE17,ADC_12bit);
    }
      zNow/=10;

    if (zbase-zNow>GravityD)
    angle=GravityD;
    else if (zbase-zNow<-GravityD)
         angle=-GravityD;
         else angle=(float)(zbase-zNow)/GravityD;

    theta1=asin(angle)*57.2957;
    
}
/**************************************/
/***********************


gyro omega

************************/
void calcAngleByW()//
{
     
}
void upright()
{
     calcPID();
     if (pid.adjust>5000) setDuty=5000;
     if (pid.adjust<-5000) setDuty=-5000;
     if (pid.adjust>=0&&pid.adjust<5000)
     {
         setDuty=pid.adjust+motorDeadDuty;
         if (setDuty>5000) setDuty=5000;
         FTM_PWM_Duty(FTM0,FTM_CH0,setDuty);
         FTM_PWM_Duty(FTM0,FTM_CH1,0);
         FTM_PWM_Duty(FTM0,FTM_CH2,setDuty);
         FTM_PWM_Duty(FTM0,FTM_CH3,0);
     }
     if (pid.adjust<=0&&pid.adjust>-5000)
     {
         setDuty=motorDeadDuty-pid.adjust;
         if (setDuty<-5000) setDuty=-5000;
         FTM_PWM_Duty(FTM0,FTM_CH0,0);
         FTM_PWM_Duty(FTM0,FTM_CH1,setDuty);
         FTM_PWM_Duty(FTM0,FTM_CH2,0);
         FTM_PWM_Duty(FTM0,FTM_CH3,setDuty);
     }
}
void calcPID()
{
    pid.err=theta1-set_theta;
    if (fabs(pid.err)<0.1)
    {
        pid.adjust=0;
    }
    else
    {
        pid.adjust=pid.P*pid.err+pid.I*pid.err1+pid.D*pid.err2;
        pid.err2=pid.err1;
        pid.err1=pid.err;
    }

}