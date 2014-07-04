#ifndef  _VARIABLE_H_
#define  _VARIABLE_H_
#define V 60
#define H 80

typedef struct PID
{
   float P;//proportion
   float I;//integral   
   float D;//derivative
   float err;//err[0]
   float err1;//err[-1]
   float err2;//err[-2]
   float adjust;
}PID;

extern PID anglePID,kPID,bPID,leftSpeedPID,rightSpeedPID;


extern unsigned int zout;
extern unsigned int wout;
extern int leftMotorDeadDutyA,rightMotorDeadDutyA;
extern int leftMotorDeadDutyB,rightMotorDeadDutyB;
extern int leftSetDuty,rightSetDuty;


extern float setTheta;
extern float theta1;
extern float theta2;
extern float theta;
extern float GravityA;//重力常数

extern float GravityD;
extern float zbase;
extern float wbase;
extern float wreal;
extern float dt;



extern int setSpeed;



extern float angle,gyro;

extern uint8 THRESHOLD;//阈值
extern uint8 V_Cnt;
extern uint8 Is_SendPhoto;
extern uint8 pixData[V][H];
extern uint8 data01[V][H];
extern uint8 leftEdge[V],rightEdge[V];
extern byte imageBMP[V/8+1][H];
extern byte lineBMP[V/8+1][H];
extern uint8 middle[V];
extern uint8 validLine;
extern uint8 lastPathWidth;



#endif