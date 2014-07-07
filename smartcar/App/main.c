#include "common.h"
#include "include.h"
int option=0;
void main()
{
    _gpio_init(); 
    ADC_init();
    _display_init();
    SCCB_init();  
    FTM_init();
    PIT_init();  
    //uart_init(UART3,115200);
    variable_init();
    setIRQPriority();
    EnableInterrupts;
    while(1)
    {
        LCD_Fill(0x00);  
        LCD_P6x8Str(0,option,">");
        LCD_P6x8Str(10,0,"anglePID.P");
        LCD_P6x8int(80,0,anglePID.P);
        LCD_P6x8Str(10,1,"anglePID.D");
        LCD_P6x8int(80,1,anglePID.D);
        LCD_P6x8Str(10,2,"speedP");
        LCD_P6x8int(80,2,leftSpeedPID.P);
        LCD_P6x8Str(10,3,"speedD");
        LCD_P6x8int(80,3,leftSpeedPID.D);
        LCD_P6x8Str(10,4,"kPID.P");
        LCD_P6x8int(80,4,kPID.P);
        LCD_P6x8Str(10,5,"bPID.P");
        LCD_P6x8int(80,5,bPID.P);
        LCD_P6x8Str(10,6,"setTheta");
        LCD_P6x8int(80,6,setTheta);
        LCD_P6x8Str(10,7,"setSpeed");
        LCD_P6x8int(80,7,setSpeed);
        if (key_press(KEY_A))
        {
             option++;
             if (option>7)
             option=0;
           
        }
        else  if (option==0)
              {
                  if (key_press(KEY_B))
                  {
                        anglePID.P-=10;
                  }
                  if (key_press(KEY_C))
                  {
                        anglePID.P+=10;
                  }
                   if (key_press(KEY_D))
                  {
                        anglePID.P-=1;
                  }
                  if (key_press(KEY_E))
                  {
                        anglePID.P+=1;
                  }
              }
        else  if (option==1)
              {
                  if (key_press(KEY_B))
                  {
                        anglePID.D-=10;
                  }
                  if (key_press(KEY_C))
                  {
                        anglePID.D+=10;
                  }
                   if (key_press(KEY_D))
                  {
                        anglePID.D-=1;
                  }
                  if (key_press(KEY_E))
                  {
                        anglePID.D+=1;
                  }
              }
        else  if (option==2)
              {
                  if (key_press(KEY_B))
                  {
                       leftSpeedPID.P-=10;
                       rightSpeedPID.P-=10;
                  }
                  if (key_press(KEY_C))
                  {
                       leftSpeedPID.P+=10;
                       rightSpeedPID.P+=10;
                  }
                   if (key_press(KEY_D))
                  {
                        leftSpeedPID.P-=1;
                        rightSpeedPID.P-=1;
                  }
                  if (key_press(KEY_E))
                  {
                        leftSpeedPID.P+=1;
                        rightSpeedPID.P+=1;
                  }
              }
         else if (option==3)
              {
                  if (key_press(KEY_B))
                  {
                       leftSpeedPID.D-=10;
                       rightSpeedPID.D-=10;
                  }
                  if (key_press(KEY_C))
                  {
                       leftSpeedPID.D+=10;
                       rightSpeedPID.D+=10;
                  }
                   if (key_press(KEY_D))
                  {
                        leftSpeedPID.D-=1;
                        rightSpeedPID.D-=1;
                  }
                  if (key_press(KEY_E))
                  {
                        leftSpeedPID.D+=1;
                        rightSpeedPID.D+=1;
                  }
               
              }
          else if (option==4)
              {
                  if (key_press(KEY_B))
                  {
                       kPID.P-=10;
                  }
                  if (key_press(KEY_C))
                  {
                       kPID.P+=10;
                  }
                   if (key_press(KEY_D))
                  {
                        kPID.P-=1;
                  }
                  if (key_press(KEY_E))
                  {
                        kPID.P+=1;
                  }
              }
        else if (option==5)
              {
                  if (key_press(KEY_B))
                  {
                       bPID.P-=10;
                  }
                  if (key_press(KEY_C))
                  {
                       bPID.P+=10;
                  }
                   if (key_press(KEY_D))
                  {
                        bPID.P-=1;
                  }
                  if (key_press(KEY_E))
                  {
                        bPID.P+=1;
                  }
              }
        else if (option==6)
              {
                  if (key_press(KEY_B))
                  {
                       setTheta-=1;
                  }
                  if (key_press(KEY_C))
                  {
                       setTheta+=1;
                  }
                   if (key_press(KEY_D))
                  {
                        setTheta-=0.1;
                  }
                  if (key_press(KEY_E))
                  {
                  }
              }
        else if (option==7)
              {
                  if (key_press(KEY_B))
                  {
                       setSpeed-=10;
                  }
                  if (key_press(KEY_C))
                  {
                       setSpeed+=10;
                  }
                   if (key_press(KEY_D))
                  {
                        setSpeed-=1;
                  }
                  if (key_press(KEY_E))
                  {
                  }
              }
        //Draw_BMP(0, 0, 79, 6, imageBMP[0]);       
        //Draw_BMP(0, 0, 80, 7, lineBMP[0]);
        LCD_CLS();
    }
}