#ifndef _CAMERA_H_
#define _CAMERA_H_

 
void dataToBMP();
void SCCB_init();
void dataToLine();
void blackFilter();
void swap(uint8 *a,uint8 *b);
void edgeTransposition();
void Black_rectify();
void getMiddle();
uint8 getValidRow1();
uint8 getValidRow2(uint8 x);
uint8 middleNum(uint8 a,uint8 b,uint8 c);
void calcSlope(int x1, int x2);
void dynamicThreshold(void);


















#endif