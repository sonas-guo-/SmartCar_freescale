#include "include.h"

/*
全局参数

*/
PID pid;

float angle=0,gyro=0;//kalman滤波之后的角度及角速度

unsigned int zout;//ad输出值
unsigned int wout;
int leftMotorDeadDutyA=350,rightMotorDeadDutyA=550;
int leftMotorDeadDutyB=570,rightMotorDeadDutyB=360;
int leftSetDuty,rightSetDuty;


float set_theta=12.3;//目标theta
float theta1=0;//加速度计算出的theta
float theta2=0;//陀螺仪得出的theta
float theta;


float GravityA=9.78;
float GravityD=830;
float wbase=1900;//基准角速度值
float wreal;//实际所得角速度
float zbase=2020;//小车竖直所得值
float dt=0.005;


