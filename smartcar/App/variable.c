#include "include.h"





PID pid;




float angle=0,gyro=0;//kalman�˲�֮��ĽǶȼ����ٶ�

unsigned int zout;//ad���ֵ
unsigned int wout;
int leftMotorDeadDutyA=330,rightMotorDeadDutyA=590;//AB���˳ʱ�뷽������
int leftMotorDeadDutyB=530,rightMotorDeadDutyB=370;//AB�����ʱ�뷽������
int leftSetDuty,rightSetDuty;


float set_theta=14;//Ŀ��theta
float theta1=0;//���ٶȼ������theta
float theta2=0;//�����ǵó���theta

float GravityA=9.78;
float GravityD=830;
float wbase=1900;//��׼���ٶ�ֵ
float wreal;//ʵ�����ý��ٶ�
float zbase=2020;//С����ֱ����ֵ
float dt=0.005;
char str1[5];




uint8 THRESHOLD=100;
uint8 V_Cnt=0;
uint8 Is_SendPhoto=0;
uint8 pixData[V][H]={0};
uint8 data01[V][H]={0};
byte imageBMP[V/8+1][H]={0};
uint8 leftEdge[V],rightEdge[V];