#include "include.h"





PID anglePID,kPID,bPID,leftSpeedPID,rightSpeedPID;




float angle=0,gyro=0;//kalman�˲�֮��ĽǶȼ����ٶ�

unsigned int zout;//ad���ֵ
unsigned int wout;
int leftMotorDeadDutyA=380,rightMotorDeadDutyA=530;//AB���˳ʱ�뷽������ch0 ch2
int leftMotorDeadDutyB=600,rightMotorDeadDutyB=370;//AB�����ʱ�뷽������ch1 ch3
int leftSetDuty,rightSetDuty;


float setTheta=11;//Ŀ��theta �ٶ�δ����14
float theta1=0;//���ٶȼ������theta
float theta2=0;//�����ǵó���theta

float GravityA=9.78;
float GravityD=830;
float wbase=1900;//��׼���ٶ�ֵ
float wreal;//ʵ�����ý��ٶ�
float zbase=2020;//С����ֱ����ֵ
float dt=0.005;


int setSpeed=0;
int leftDirSpeed;
int rightDirSpeed;




uint8 THRESHOLD=100;
uint8 V_Cnt=0;
uint8 Is_SendPhoto=0;
uint8 pixData[V][H]={0};
uint8 data01[V][H]={0};
byte imageBMP[V/8+1][H]={0};
byte lineBMP[V/8+1][H]={0};
uint8 leftEdge[V],rightEdge[V];
uint8 middle[V];
uint8 validLine;
uint8 lastPathWidth;


float line_xi=0,line_yi=0,line_A=0,line_B=0,line_C=0,line_K=0;
