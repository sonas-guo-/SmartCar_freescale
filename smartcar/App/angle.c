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
    angle=800;
    else if (zbase-zNow<-GravityD)
         angle=-800;
         else angle=(float)(zbase-zNow)/GravityD;

    theta1=asin(angle)/pi*180;
    
}
/**************************************/
/***********************


gyro omega

************************/
void calcAngleByW()//
{
      wreal=0;
      for (int i=0;i<10;i++)
      {
        wreal+=adc_mid(ADC1_DP0,ADC_12bit);
      }
        wreal/=10;
        
      wreal-=wbase;
      wreal*=0.67;  
}



void upright()
{
    calcPID();
    delta_duty=(int)(pid.adjust/200*15);
    if (delta_duty>15)
    {
        delta_duty=15;
    }else if (delta_duty<-15)
    {
        delta_duty=-15;
    }
    if (pid.err>3)
    {
      FTM_PWM_Duty(FTM0, FTM_CH0,15); 
      FTM_PWM_Duty(FTM0, FTM_CH1,0); 
      FTM_PWM_Duty(FTM0, FTM_CH2,15); 
      FTM_PWM_Duty(FTM0, FTM_CH3,0);   
    }else if (pid.err<-3)
    {
      FTM_PWM_Duty(FTM0, FTM_CH0,0); 
      FTM_PWM_Duty(FTM0, FTM_CH1,20); 
      FTM_PWM_Duty(FTM0, FTM_CH2,0); 
      FTM_PWM_Duty(FTM0, FTM_CH3,20);   
    }else 
    if (delta_duty>=0)
    {
      FTM_PWM_Duty(FTM0, FTM_CH0,delta_duty); 
      FTM_PWM_Duty(FTM0, FTM_CH1,0); 
      FTM_PWM_Duty(FTM0, FTM_CH2,delta_duty); 
      FTM_PWM_Duty(FTM0, FTM_CH3,0); 
    }
    else if (delta_duty<0)
    {
      FTM_PWM_Duty(FTM0, FTM_CH0,0); 
      FTM_PWM_Duty(FTM0, FTM_CH1,-delta_duty); 
      FTM_PWM_Duty(FTM0, FTM_CH2,0); 
      FTM_PWM_Duty(FTM0, FTM_CH3,-delta_duty); 
    }
}
void calcPID()
{
    pid.err=theta1-set_theta;
    if (fabs(pid.err)<0.5)
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