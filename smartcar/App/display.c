#include "include.h"
void menu0()
{
      LCD_Fill(0x00);  
      LCD_P6x8Str(80,option0,">");
      LCD_P6x8Str(85,0,"up");
      LCD_P6x8int(105,0,upFlag);
      LCD_P6x8Str(85,1,"run");
      LCD_P6x8int(105,1,runFlag);
      LCD_P6x8Str(85,2,"spd");
      LCD_P6x8int(105,2,setSpeed);
      LCD_P6x8Str(85,3,"sTh");
      LCD_P6x8int(105,3,setTheta);
      LCD_P6x8Str(85,4,"thP");
      LCD_P6x8int(105,4,anglePID.P);
      LCD_P6x8Str(85,5,"thD");
      LCD_P6x8int(105,5,anglePID.D);
      LCD_P6x8Str(85,6,"gear");
      LCD_P6x8int(105,6,gear);     
      LCD_P6x8Str(85,7,"img");
      if (!imgFlag) { dataToBMP();Draw_BMP(0, 0, 79, 6, imageBMP[0]);}else { dataToLine();Draw_BMP(0, 0, 79, 7, lineBMP[0]);}  
      if (key_press(KEY_B))
      { 
          option0++;
          if (option0>7) option0=0;
      }
      else if (option0==0)
            {
                  if (key_press(KEY_C))
                  {
                       upFlag=!upFlag; 
                       if (upFlag) 
                      {
                       count100ms=0;
                       runSpeed=0;
                       speedFlag=1;
                       runSpeed=0;
                       //setSpeed=0;
                       dirFlag=0;
                       runFlag=0;
                       enable_irq(PIT0_IRQn);
                      }else 
                      {
                       disable_irq(PIT0_IRQn);
                      }
                  }
                  
            }
            else if (option0==1)
            {
                  if (key_press(KEY_C))
                  {
                      runFlag=1;
                      dirFlag=1;        
                  }
                  
            }
            else if (option0==2)
            {
                  if (key_press(KEY_C))
                  {
                      setSpeed+=5;
                  }
                   if (key_press(KEY_D))
                  {
                      setSpeed-=5;
                  }
            }
            else if (option0==3)
            {
                  if (key_press(KEY_C))
                  {
                      setTheta+=1;
                  }
                   if (key_press(KEY_D))
                  {
                      setTheta-=1;
                  }
            }
             else if (option0==4)
            {
                  if (key_press(KEY_C))
                  {
                      anglePID.P+=5;
                  }
                   if (key_press(KEY_D))
                  {
                      anglePID.P-=2;
                  }
            }
             else if (option0==5)
            {
                  if (key_press(KEY_C))
                  {
                      anglePID.D+=5;
                  }
                   if (key_press(KEY_D))
                  {
                      anglePID.D-=2;
                  }
            }
            else if (option0==6)
            {
                /**************
                ÏÔÊ¾²¦ÂëÅÌµµÎ»
                **************/
            }
            else if (option0==7)
            {
                  if (key_press(KEY_C))
                  {
                      imgFlag=!imgFlag;
                  }
            }
}
void menu1()
{
      LCD_Fill(0x00);  
      LCD_P6x8Str(80,option1,">");
   
      LCD_P6x8Str(85,0,"spP");
      LCD_P6x8int(105,0,leftSpeedPID.P);
      LCD_P6x8Str(85,1,"spD");
      LCD_P6x8int(105,1,leftSpeedPID.D);
      LCD_P6x8Str(85,2,"kP");
      LCD_P6x8int(105,2,kPID.P);
      LCD_P6x8Str(85,3,"bP");
      LCD_P6x8int(105,3,bPID.P);
      LCD_P6x8Str(85,4,"TFl");
      LCD_P6x8int(105,4,threFlag);
      LCD_P6x8Str(85,5,"THRE");
      LCD_P6x8int(105,5,THRESHOLD);
      LCD_P6x8Str(85,6,"dFl");
      LCD_P6x8int(105,6,dirFlag);
      LCD_P6x8Str(85,7,"sFl");
      LCD_P6x8int(105,7,speedFlag);
      if (!imgFlag) { dataToBMP();Draw_BMP(0, 0, 79, 6, imageBMP[0]);}else { dataToLine();Draw_BMP(0, 0, 79, 7, lineBMP[0]);}  

      if (key_press(KEY_B))
      { 
          option1++;
          if (option1>7) option1=0;
      }
      else if (option1==0)
            {
                  if (key_press(KEY_C))
                  {     
                       leftSpeedPID.P+=5;
                       rightSpeedPID.P+=5;
                  }
                  if (key_press(KEY_D))
                  {     
                       leftSpeedPID.P-=1;
                       rightSpeedPID.P-=1;
                  }
            }
            else if (option1==1)
            {
                  if (key_press(KEY_C))
                  {     
                       leftSpeedPID.D+=5;
                       rightSpeedPID.D+=5;
                  }
                  if (key_press(KEY_D))
                  {     
                       leftSpeedPID.D-=1;
                       rightSpeedPID.D-=1;
                  } 
            }
            else if (option1==2)
            {
                  if (key_press(KEY_C))
                  {
                      kPID.P+=5;
                  }
                   if (key_press(KEY_D))
                  {
                      kPID.P-=2;
                  }
            }
            else if (option1==3)
            {
                  if (key_press(KEY_C))
                  {
                      bPID.P+=5;
                  }
                   if (key_press(KEY_D))
                  {
                      bPID.P-=2;
                  }
            }
             else if (option1==4)
            {
                   if (key_press(KEY_C))
                  {
                      threFlag=!threFlag;
                  }
            }
             else if (option1==5)
            {
                 if (key_press(KEY_C))
                  {
                      THRESHOLD+=5;
                  }
                   if (key_press(KEY_D))
                  {
                      THRESHOLD-=2;
                  }
            }
             else if (option1==6)
            {
                  if (key_press(KEY_C))
                  {
                      dirFlag=!dirFlag;
                  } 
            }
             else if (option1==7)
            {
                  if (key_press(KEY_C))
                  {
                      speedFlag=!speedFlag;
                  }
              
            }
}
void menuDisplay()
{
        if (key_press(KEY_A))
        {
           menu++;
           if (menu>1) menu=0;
        }
        switch (menu)
        {
           case 0:menu0();break;
           case 1:menu1();break;
           //case 2:menu2();break;
        }
        
       
     
       
 
}
void _display()
{
      LCD_Fill(0x00);      
      
      LCD_P6x8Str(10,2,"ZOUT:"); 
      zout=adc_mid(ADC0_SE17,ADC_12bit);
      LCD_P6x8int(50,2,zout);

      LCD_P6x8Str(10,4,"W:");
      wout=adc_mid(ADC1_DP0,ADC_12bit);
      LCD_P6x8int(50,4,wout);
      
      LCD_P6x8Str(10,5,"theta1:");
      LCD_P6x8int(50,5,theta1);
    
      //delay();

      LCD_CLS();
}