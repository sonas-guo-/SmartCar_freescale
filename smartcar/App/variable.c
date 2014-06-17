#include "include.h"

/*
全局参数

*/
PID pid;


int zout;//ad输出值
int wout;
int delta_duty=0;


float set_theta=0;//目标theta
float theta1=0;//加速度计算出的theta
float theta2=0;//陀螺仪得出的theta

float GravityA=9.78;
float GravityD=800;
float wbase=100;//基准角速度值
float wreal;//实际所得角速度
float zbase=1300;