#include "include.h"





/***********************

δת��֮ǰ�ı����˲�
***********************/
void blackFilter()
{
    unsigned char i;
  for(i=1;i<V-4;i++)
  {
    if(( leftEdge[i]<= leftEdge[i+1])&& ((leftEdge[i+2]< leftEdge[i+1])||(leftEdge[i+2]> leftEdge[i+3]))&& (leftEdge[i+1]<= leftEdge[i+3]))
    {
      leftEdge[i+2]=(leftEdge[i+3]+leftEdge[i+1])/2;
    }
    if(( leftEdge[i]>= leftEdge[i+1])&& ((leftEdge[i+2]> leftEdge[i+1])||(leftEdge[i+2]< leftEdge[i+3]))&& (leftEdge[i+1]>= leftEdge[i+3]))
    {
      leftEdge[i+2]=(leftEdge[i+3]+leftEdge[i+1])/2;
    }  
    if(( rightEdge[i]>= rightEdge[i+1])&& ((rightEdge[i+2]> rightEdge[i+1])||(rightEdge[i+2]< rightEdge[i+3]))&& (rightEdge[i+1]>= rightEdge[i+3]))
    {
      rightEdge[i+2]=(rightEdge[i+3]+rightEdge[i+1])/2;
    }
    if(( rightEdge[i]<= rightEdge[i+1])&& ((rightEdge[i+2]< rightEdge[i+1])||(rightEdge[i+2]> rightEdge[i+3]))&& (rightEdge[i+1]<= rightEdge[i+3]))
    {
      rightEdge[i+2]=(rightEdge[i+3]+rightEdge[i+1])/2;
    }  
  }
}     
/**********************
����a b��ֵ,a��bΪָ����� 
**********************/
void swap(uint8 *a,uint8 *b)
{
  *a=*a^*b;*b=*b^*a;*a=*a^*b;
}
uint8 middleNum(uint8 a,uint8 b,uint8 c)
{
  uint8 max,min;
  max=a;
  min=b;
  if(a<=b)
  {
    min=a;
    max=b;
  }//��������������
  if(c<min)
    return min;
  else if(c<=max)
    return c;
  else
    return max; 
}
void edgeTransposition()
{
  for (int i=0;i<V;i++)
  {
     swap(&leftEdge[i],&rightEdge[i]);
  }
}
void getMiddle()
{
   for (int i=0;i<validLine;i++)
   {
      if (leftEdge[i]==0)
          {     
               middle[i]=rightEdge[i]-lastPathWidth[i][1]/2;
          }else 
          if (rightEdge[i]==H-1)
          {     
               middle[i]=leftEdge[i]+lastPathWidth[i][0]/2;
          }
           else         
          {
                middle[i]=(leftEdge[i]+rightEdge[i])/2;
                lastPathWidth[i][0]=middle[i]-leftEdge[i];
                lastPathWidth[i][1]=rightEdge[i]-middle[i];
          }
   }
}

/*************************************
/��С���˷�����ڲ�����    
/int x1 x2      ��Ҫ�������С�е������       //���뱣֤x2��x1
*************************************/
void calcSlope(int x1, int x2)
{
      //float line_xi=0,line_yi=0,line_A=0,line_B=0,line_C=0,line_K=0;
//�ֱ��ʾx�ۼӺͣ�y�ۼӺͣ��ۼӺ͵ĳ˻����˻����ۼӺͣ�x�ۼӺ͵�ƽ����xƽ�����ۼӺ�
      int i;
      int n=x2-x1+1;
      int temp[60];
        line_xi=0;line_yi=0;line_A=0;line_B=0;line_C=0;line_K=0; 
        for(i=x1;i<=x2;i++)
          temp[i]=((leftEdge[i]+rightEdge[i])/2-39.5)*80/(80-i)+39.5;//ͼ����� 75
	for(i=x1;i<=x2;i++) //�ȶ������е�����λ����λ����ͼ�����������x�ᣬˮƽ����Ϊ��y��
	{
               line_xi+=i;           //x���ۼӺ�
               line_yi+=temp[i];     //y���ۼӺ�
               line_B+=i*temp[i];    //�˻����ۼӺ�
               line_K+=i*i;          //xƽ�����ۼӺ�
	}
	line_A=line_xi*line_yi;           //�ۼӺ͵ĳ˻�
	line_C=line_xi*line_xi;           //x�ۼӺ͵�ƽ��
    if (line_C-n*line_K!=0)
    {	kPID.err1=kPID.err;
	bPID.err1=bPID.err;
	kPID.err=((line_A-n*line_B)/(line_C-n*line_K)*100);
	bPID.err=((line_yi-kPID.err/100*line_xi)/n-39.5);
    }
	//Mid_err=Get_average(x1,x2);
      /*  static float xy=0,xx=0,x=0,y=0;//xy�ۼӺͣ�x2�ۼӺͣ�x�ۼӺͣ�y�ۼӺ�
        int n=x2-x1+1;
        xy=0;xx=0;x=0;y=0;
        for (int i=x1;i<=x2;i++)
        {
             x+=i;   
             xx+=i*i;
             xy+=i*middle[i];
             y+=middle[i];
        }
        kPID.err=(xy-x*y/n)/(xx-x*x/n)/100;
        bPID.err=((y-kPID.err*x)/n-39.5)/100;*/
        

}
/************************
�ɼ�����ͼ��ת��ΪBMP��ʽ���
*************************/
void dataToBMP()
{
    for (int i=0;i<V;i++)
        for (int j=0;j<H;j++)
          if (data01[i][j]==1) imageBMP[i/8][j]&=~(1<<(i%8));
          else  imageBMP[i/8][j]|=(1<<(i%8));
    
   /* for (int i=0;i<V;i++)
    {
        imageBMP[i/8][middle[i]]|=(1<<(i%8));
    }*/
}       
/************************
����ת��ΪBMP��ʽ���
*************************/
void dataToLine()
{
      memset(lineBMP,0,sizeof(lineBMP));
      for (int i=0;i<V;i++)
      {
          lineBMP[i/8][leftEdge[i]]|=(1<<(i%8));
          lineBMP[i/8][middle[i]]|=(1<<(i%8));
          lineBMP[i/8][rightEdge[i]]|=(1<<(i%8));
      }
      for (int i=0;i<H;i++)
      {
          lineBMP[validLine/8][i]|=(1<<(validLine%8)); 
          
      }
}
/************************

�õ���Ч��

*************************/
uint8 getValidRow1()
{
   /* uint8 i,j;
   uint8 Mid[V];
  
  for(i=10;i<V;i++)
  {      
     if(((leftEdge[i] - leftEdge[i+1]) > 3)||((rightEdge[i+1] - rightEdge[i]) > 3))
       if(((leftEdge[i] - leftEdge[i+2]) > 5)||((rightEdge[i+2] - rightEdge[i]) > 5))
         if(((leftEdge[i] - leftEdge[i+3]) > 8)||((rightEdge[i+3] - rightEdge[i]) > 8))
         {
          j=i;
          break;
          }
     j=0;
  }
 

  for(i=j+1;i<V-1;i++)
  {      
      Mid[i] = middleNum(middle[i-1],middle[i],middle[i+1]);
  }
  
  for(i=j+1;i<V-1;i++)
  {
      if(Mid[i]<5 || Mid[i]>75||rightEdge[i]-leftEdge[i]<10)   
      {
        break;
      }
  }
  if (i==V-1) i=0;
  if(i<15)
    i=15;
  return i;*/
  
	uint8 i,j;
	int Mid[V];
	  
	for(i=0;i<45;i++)
	{      
	if(((leftEdge[i] - leftEdge[i+1]) > 5)||((rightEdge[i+1] - rightEdge[i]) > 5))
		if(((leftEdge[i] - leftEdge[i+2]) > 5)||((rightEdge[i+2] - rightEdge[i]) > 5))
			if(((leftEdge[i] - leftEdge[i+3]) > 5)||((rightEdge[i+3] - rightEdge[i]) > 5))
	  break;
	}
	j=i;
	  
	for(i=0;i<j;i++)
	{      
		Mid[i] = (leftEdge[i]+rightEdge[i])/2;
	} 
	for(i=1;i<j-1;i++)
	{      
		Mid[i] = middleNum(Mid[i-1],Mid[i],Mid[i+1]);
	}
	for(i=10;i<j-1;i++)
	{
		if(Mid[i]<10 || Mid[i]>70||fabs(rightEdge[i]-leftEdge[i])<10) break;
	}
	if(i>45) i=45;
	return i;
       
}
/*************************
��Ч��

************************/
uint8 getValidRow2(uint8 x)
{
     int i,j;
     for(i=x;i<V;i++)
	{      
	if(((leftEdge[i+1] - leftEdge[i]) > 3)||((rightEdge[i] - rightEdge[i+1]) > 3))
		if(((leftEdge[i+2] - leftEdge[i]) > 5)||((rightEdge[i] - rightEdge[i+2]) > 5))
			if(((leftEdge[i+3] - leftEdge[i]) > 8)||((rightEdge[i] - rightEdge[i+3]) > 8))
	  break;
	}
	j=i;
        int mid;
        for(i=x;i<j;i++)
        {
                mid=(leftEdge[i]+rightEdge[i])/2;
                if(mid<10 || mid>70||abs(rightEdge[i]-leftEdge[i])<10) break;
	}
	if(i>45) i=45;
	return i;
}
void dynamicThreshold(void)
{
	unsigned char T_target_error=5,T_error=0,T_last;
	long int S_target=0,S_background=0;//Ŀ��ͱ����ĻҶȺ�
	int N_target=0,N_background=0;//Ŀ��ͱ����ĵ������
	unsigned char E_target=0,E_background=0;
	unsigned int i,j;
	do
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<H;j+=1)
			{
				if(pixData[i][j]<THRESHOLD)
				{
					S_target+=pixData[i][j];
					N_target++;
				}
				else 
				{
					S_background+=pixData[i][j];
					N_background++;
				}
			}
		}
		if((N_target==0)||(N_background==0)) break;
		E_target=(unsigned char)(S_target/N_target);
		E_background=(unsigned char)(S_background/N_background);
		T_last=THRESHOLD;
		THRESHOLD=fabs((E_target+E_background)/2);
		T_error=fabs(THRESHOLD-T_last);
	}while(T_error>T_target_error);
}
/*******************************
//���������
********************************/
char Start_detect()
{
	int i,j,temp[80],Left_Start=0,Left_End=0,Right_Start=0,Right_End=0;
	for(i=0;i<80;i++)
	{
		for(j=0;j<60;j++)
		{
			if(data01[j][i]==0)
			{
				temp[i]=j;
				break;
			}
		}
	}
	if(fabs(kPID.err)>30) return 0;
	for(i=middle[0];i<60;i++)
	{
		if(temp[i]<10)
		{
			Right_Start=i;
			for(i=Right_Start;i<80;i++)
			{
				if(temp[i]>10)
				{
					break;
				}
				Right_End=i;
			}
			break;
		}
	}
	for(i=middle[0];i>20;i--)
	{
		if(temp[i]<10)
		{
			Left_Start=i;
			for(i=Left_Start;i>=0;i--)
			{
				if(temp[i]>10)
				{
					break;
				}
				Left_End=i;
			}
			break;
		}
	}
	if((((Right_End-Right_Start)>10)&&((Right_End-Right_Start)<25))&&(((Left_Start-Left_End)>10)&&((Left_Start-Left_End)<25)))
		return 1;
	else return 0;
}

/*******************************

SCCB ��ʼ��
******************************/
void SCCB_init()
{
    gpio_init (PTA10,GPI,0);
    gpio_init (PTA11,GPI,0);
    sccb_init();
    sccb_regWrite(0x42,0x11,0x00);//
    sccb_wait();  
    sccb_regWrite(0x42,0x14,0x24);//��ַ0X24-QVGA(320*120)
    sccb_wait(); 
    exti_init(PTA,29,rising_down);//���жϣ�PORTA29 �˿��ⲿ�жϳ�ʼ�� �������ش����жϣ��ڲ�����  
    //port_init_NoALT(PTA29,PULLDOWN);
    //port_init_NoALT(PTB0,PULLDOWN);
    port_init_NoALT(PTC0,PULLDOWN);
    //disable_irq(PORTA_IRQn);                             //���жϹر�    
    exti_init(PTB,0,falling_down);//���жϣ�PORTB0 �˿��ⲿ�жϳ�ʼ�� ���½��ش����жϣ��ڲ�����  
    //uart_init(UART3,115200);
   //enable_irq(PORTA_IRQn);
}