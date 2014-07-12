#include "common.h"
#include "include.h"
int leftCount,rightCount,aveCount;
void main()
{
    _gpio_init(); 
    ADC_init();
    _display_init();
    SCCB_init();  
    FTM_init();
    PIT_init();  
    //uart_init(UART3,57600);
    variable_init();
    setIRQPriority();
    selectDial();
  

    while(1) 
    {
      dynamicThreshold();
      menuDisplay();
      blackFilter();//�����˲�
      edgeTransposition();//����ת��
      validLine=getValidRow2(5);
      getMiddle();      
      calcSlope(0,validLine);
    }
}