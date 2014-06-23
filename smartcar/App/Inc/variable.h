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
extern int leftMotorDeadDutyA,rightMotorDeadDutyA;
extern int leftMotorDeadDutyB,rightMotorDeadDutyB;
extern int leftSetDuty,rightSetDuty;


extern float set_theta;
extern float theta1;
extern float theta2;
extern float theta;
extern float GravityA;//重力常数

extern float GravityD;
extern float zbase;
extern float wbase;
extern float wreal;
extern float dt;


extern float angle,gyro;
/*
extern float Q_angle,Q_gyro,R_angle;
extern float P[2][2];
extern float Pdot[4];
extern float C_0;
extern float q_bias, angle_err, PCt_0, PCt_1, E, K_0, K_1, t_0, t_1;
*/







#endif