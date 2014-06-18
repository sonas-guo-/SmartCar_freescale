#include "include.h"

/*
全局参数

*/
PID pid;


unsigned int zout;//ad输出值
unsigned int wout;
int motorDeadDuty=350;//电机死区占空比7%，调整精度的话数值需要改
int setDuty=0;

 
float set_theta=5.5;//目标theta
float theta1=0;//加速度计算出的theta
float theta2=0;//陀螺仪得出的theta

float GravityA=9.78;
float GravityD=835;
float wbase=100;//基准角速度值
float wreal;//实际所得角速度
float zbase=1427;