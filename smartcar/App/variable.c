#include "include.h"

/*
ȫ�ֲ���

*/
PID pid;

float angle=0,gyro=0;//kalman�˲�֮��ĽǶȼ����ٶ�

unsigned int zout;//ad���ֵ
unsigned int wout;
int leftMotorDeadDutyA=350,rightMotorDeadDutyA=550;
int leftMotorDeadDutyB=570,rightMotorDeadDutyB=360;
int leftSetDuty,rightSetDuty;


float set_theta=12.3;//Ŀ��theta
float theta1=0;//���ٶȼ������theta
float theta2=0;//�����ǵó���theta
float theta;


float GravityA=9.78;
float GravityD=830;
float wbase=1900;//��׼���ٶ�ֵ
float wreal;//ʵ�����ý��ٶ�
float zbase=2020;//С����ֱ����ֵ
float dt=0.005;


