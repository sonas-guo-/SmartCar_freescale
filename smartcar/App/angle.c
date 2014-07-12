#include "include.h"
#include <math.h>
#define pi 3.1415


/*****************************/
/********************
加速度计omega
*******************/
void calcAngle()//
{
    //static int tem;
    int zNow=0;//
    float temp;
    for (int i=0;i<10;i++)
    {
      zNow+=adc_mid(ADC0_SE17,ADC_12bit);
    }
      zNow/=10;
    if (zbase-zNow>GravityD)
    temp=GravityD;
    else if (zbase-zNow<-GravityD)
         temp=-GravityD;
         else temp=zbase-zNow;

    theta1=asinf(temp/GravityD)*57.2957;//*57.2957;
    
}
/**************************************/
/***********************


gyro omega

************************/
void calcAngleByW()//
{
    //static int tem1;
    int temp=0;
    for (int i=0;i<10;i++)
    {
        temp+=adc_mid(ADC1_DP0,ADC_12bit);
    }
        temp/=10;
    wreal=(wbase-temp)*0.2208;//0.2208 0.45
    theta2+=wreal*0.005;
}
void kalmanFilter()
{
  	static float Q_angle=0.001, Q_gyro=0.003, R_angle=0.5;//注意：dt的取值为kalman滤波器采样时间;
	static float Pk[2][2] = { {1, 0 }, {0, 1 }};
	static float Pdot[4] ={0,0,0,0};
	static const float C_0 = 1;
	static float q_bias = 0, angle_err = 0, PCt_0, PCt_1, E, K_0, K_1, t_0, t_1;
	angle+=(wreal-q_bias) * dt;
	Pdot[0]=Q_angle - Pk[0][1] - Pk[1][0];
	Pdot[1]=- Pk[1][1];
	Pdot[2]=- Pk[1][1];
	Pdot[3]=Q_gyro;

	Pk[0][0] += Pdot[0] * dt;
	Pk[0][1] += Pdot[1] * dt;
	Pk[1][0] += Pdot[2] * dt;
	Pk[1][1] += Pdot[3] * dt;


	angle_err = theta1 - angle;


	PCt_0 = C_0 * Pk[0][0];
	PCt_1 = C_0 * Pk[1][0];

	E = R_angle + C_0 * PCt_0;

	K_0 = PCt_0*1.0/ E;
	K_1 = PCt_1*1.0/ E;

	t_0 = PCt_0;
	t_1 = C_0 * Pk[0][1];

	Pk[0][0] -= K_0 * t_0;
	Pk[0][1] -= K_0 * t_1;
	Pk[1][0] -= K_1 * t_0;
	Pk[1][1] -= K_1 * t_1;
	angle+= K_0 * angle_err;
	q_bias+= K_1 * angle_err;
	gyro = wreal-q_bias;//滤波后的角速度
}
void upright()
{
     calcAnglePID();
     leftSetDuty=(int)anglePID.adjust+leftSpeedPID.adjust+leftDirSpeed;
     rightSetDuty=(int)anglePID.adjust+rightSpeedPID.adjust+rightDirSpeed;
    
     if (leftSetDuty>5000)  leftSetDuty=5000;
     if (rightSetDuty>5000) rightSetDuty=5000;
     if (leftSetDuty<-5000) leftSetDuty=-5000;
     if (rightSetDuty<-5000) rightSetDuty=-5000;
          
      
     if (angle>35||angle<-35)
     {
         leftSetDuty=0;rightSetDuty=0;
     }
  
     if (0<=leftSetDuty&&leftSetDuty<=5000)
     {
         leftSetDuty+=leftMotorDeadDutyA;
         if (leftSetDuty>5000) leftSetDuty=5000;
         FTM_PWM_Duty(FTM0,FTM_CH0,leftSetDuty);
         FTM_PWM_Duty(FTM0,FTM_CH1,0);
     }else 
     if (0>=leftSetDuty&&leftSetDuty>=-5000)
     {
         leftSetDuty-=leftMotorDeadDutyB;
         if (leftSetDuty<-5000) leftSetDuty=-5000;
         FTM_PWM_Duty(FTM0,FTM_CH0,0);
         FTM_PWM_Duty(FTM0,FTM_CH1,-leftSetDuty);
     }
     if (0<=rightSetDuty&&rightSetDuty<=5000)
     {
         rightSetDuty+=rightMotorDeadDutyA;
         if (rightSetDuty>5000) rightSetDuty=5000;
         FTM_PWM_Duty(FTM0,FTM_CH2,rightSetDuty);
         FTM_PWM_Duty(FTM0,FTM_CH3,0);
     }else
     if (0>=rightSetDuty&&rightSetDuty>=-5000)
     {
         rightSetDuty-=rightMotorDeadDutyB;
         if (rightSetDuty<-5000) rightSetDuty=-5000;
         FTM_PWM_Duty(FTM0,FTM_CH2,0);
         FTM_PWM_Duty(FTM0,FTM_CH3,-rightSetDuty);
     }
}
void calcAnglePID()
{
        anglePID.err=angle-setTheta;
        anglePID.adjust=anglePID.P*anglePID.err+anglePID.D*gyro;
        anglePID.err2=anglePID.err1;
        anglePID.err1=anglePID.err;

}