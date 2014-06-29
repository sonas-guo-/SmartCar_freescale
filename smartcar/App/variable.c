#include "include.h"





PID pid;




float angle=0,gyro=0;//kalman滤波之后的角度及角速度

unsigned int zout;//ad输出值
unsigned int wout;
int leftMotorDeadDutyA=330,rightMotorDeadDutyA=590;//AB电机顺时针方向死区
int leftMotorDeadDutyB=530,rightMotorDeadDutyB=370;//AB电机逆时针方向死区
int leftSetDuty,rightSetDuty;


float set_theta=14;//目标theta
float theta1=0;//加速度计算出的theta
float theta2=0;//陀螺仪得出的theta

float GravityA=9.78;
float GravityD=830;
float wbase=1900;//基准角速度值
float wreal;//实际所得角速度
float zbase=2020;//小车竖直所得值
float dt=0.005;
char str1[5];




uint8 THRESHOLD=100;
uint8 V_Cnt=0;
uint8 Is_SendPhoto=0;
uint8 pixData[V][H]={0};
uint8 data01[V][H]={0};
byte imageBMP[V/8+1][H]={0};
uint8 leftEdge[V],rightEdge[V];