#include "include.h"

/*
ȫ�ֲ���

*/
PID pid;


int zout;//ad���ֵ
int wout;
int delta_duty=0;


float set_theta=0;//Ŀ��theta
float theta1=0;//���ٶȼ������theta
float theta2=0;//�����ǵó���theta

float GravityA=9.78;
float GravityD=800;
float wbase=100;//��׼���ٶ�ֵ
float wreal;//ʵ�����ý��ٶ�
float zbase=1300;