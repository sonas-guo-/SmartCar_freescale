#ifndef  _VARIABLE_H_
#define  _VARIABLE_H_

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


extern PID pid;

extern unsigned int zout;
extern unsigned int wout;
extern int motorDeadDuty;
extern int setDuty;

extern float set_theta;
extern float theta1;
extern float theta2;
extern float GravityA;//重力常数

extern float GravityD;
extern float zbase;
extern float wbase;
extern float wreal;










#endif