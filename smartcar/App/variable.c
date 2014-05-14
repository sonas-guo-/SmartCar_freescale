#include "include.h"

/*
三轴陀螺仪输出y，z，w;


*/
int zout;
int wout;
float theta1;//加速度计算出的theta
float theta2;//陀螺仪得出的theta
float GravityA=9.78;
int GravityD=800;
int zbase=1500;