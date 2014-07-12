#include "include.h"





PID anglePID,kPID,bPID,leftSpeedPID,rightSpeedPID;




float angle=0,gyro=0;//kalman滤波之后的角度及角速度

unsigned int zout;//ad输出值
unsigned int wout;
int leftMotorDeadDutyA=150,rightMotorDeadDutyA=250;//AB电机顺时针方向死区ch0 340 ch2 520
int leftMotorDeadDutyB=250,rightMotorDeadDutyB=150;//AB电机逆时针方向死区ch1 550 ch3 350
int leftSetDuty,rightSetDuty;


float setTheta=14;//目标theta 速度未闭环 7
float theta1=0;//加速度计算出的theta
float theta2=0;//陀螺仪得出的theta

float GravityA=9.78;
float GravityD=830;
float wbase=1907;//基准角速度值
float wreal;//实际所得角速度
float zbase=2020;//小车竖直所得值
float dt=0.005;


int setSpeed=0;
int runSpeed=0;
int leftDirSpeed;
int rightDirSpeed;

uint8 countPIT=0;
uint8 count100ms=0;

uint8 THRESHOLD=100;
uint8 V_Cnt=0;
uint8 Is_SendPhoto=0;
uint8 pixData[V][H]={0};
uint8 data01[V][H]={0};
byte imageBMP[V/8+1][H]={0};
byte lineBMP[V/8+1][H]={0};
uint8 leftEdge[
V],rightEdge[V];
uint8 middle[V];
uint8 validLine;
uint8 lastPathWidth[V][2];


float line_xi=0,line_yi=0,line_A=0,line_B=0,line_C=0,line_K=0;//最小二乘法用到的变量

//按键用到的变量
uint8 menu=0,gear=0;
uint8 option0=0,option1=0,option2=0;
uint8 imgFlag=0,upFlag=0,dirFlag=0,speedFlag=0,runFlag=0,stopFlag=0,stopLine;

