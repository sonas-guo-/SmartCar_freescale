#include "include.h"

/*
ȫ�ֲ���

*/
PID pid;


unsigned int zout;//ad���ֵ
unsigned int wout;
int motorDeadDuty=350;//�������ռ�ձ�7%���������ȵĻ���ֵ��Ҫ��
int setDuty=0;

 
float set_theta=5.5;//Ŀ��theta
float theta1=0;//���ٶȼ������theta
float theta2=0;//�����ǵó���theta

float GravityA=9.78;
float GravityD=835;
float wbase=100;//��׼���ٶ�ֵ
float wreal;//ʵ�����ý��ٶ�
float zbase=1427;