#include "include.h"


void dirControl()
{
	kPID.adjust=kPID.P*kPID.err+kPID.D*(kPID.err-kPID.err1);
	bPID.adjust=bPID.P*bPID.err;
	leftDirSpeed=(kPID.adjust+bPID.adjust);
	rightDirSpeed=-(kPID.adjust+bPID.adjust);
}

void calcSpeedPID()
{
    static int leftCount,rightCount,aveCount;
    static int leftCountLast,rightCountLast,leftCountNew,rightCountNew;
    
    leftCountNew=FTM_QUAD_get(FTM1);
    leftCount=leftCountNew*1+leftCountLast*0;//0.6  0.4
    leftCountLast=leftCountNew;


    rightCountNew=-FTM_QUAD_get(FTM2);
    rightCount=rightCountNew*1+rightCountLast*0;//0.6  0.4
    rightCountLast=rightCountNew;

    aveCount=(leftCount+rightCount)/20;
    leftSpeedPID.err=runSpeed-aveCount;
    leftSpeedPID.adjust=leftSpeedPID.P*leftSpeedPID.err+leftSpeedPID.D*(leftSpeedPID.err-leftSpeedPID.err1);
    leftSpeedPID.err2=leftSpeedPID.err1;
    leftSpeedPID.err1=leftSpeedPID.err;

    rightSpeedPID.err=runSpeed-aveCount;
    rightSpeedPID.adjust=rightSpeedPID.P*rightSpeedPID.err+rightSpeedPID.D*(rightSpeedPID.err-rightSpeedPID.err1);
    rightSpeedPID.err2=rightSpeedPID.err1;
    rightSpeedPID.err1=rightSpeedPID.err;
    
    FTM_QUAD_clean(FTM1);
    FTM_QUAD_clean(FTM2);
}