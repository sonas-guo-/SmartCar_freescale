/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,Ұ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�Ұ���ѧ��̳ http://www.chuxue123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����Ұ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��Ұ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_it.c
 * @brief      Ұ��K60 ƽ̨�жϸ�λ����
 * @author     Ұ��Ƽ�
 * @version    v5.0
 * @date       2013-06-26
 */

#include    "MK60_it.h"
#include    "include.h"

//���жϴ�����
void PORTB_IRQHandler()
{
    if(PORTB_ISFR & (1<<0))//PTB0�����ж�,���ж�
    {
      PORTB_ISFR |= (1<<0);//д1���жϱ�־λ   
      DMA_PORTx2BUFF_Init (DMA_CH4, (void *)&PTD_B0_IN, pixData, PTC0, DMA_BYTE1, H, DMA_rising_keepon);
 //DMAͨ��4��ʼ����PTC0�����ش���DMA���䣬Դ��ַΪPTD_BYTE0_IN��Ŀ�ĵ�ַΪ��pixData ��ÿ�δ���1Byte������H�κ�ֹͣ���䣬Ŀ�ĵ�ַ���ֲ��䣬�ر�ͨ��CHn Ӳ������

      Is_SendPhoto =0;
      V_Cnt=0;       //�вɼ���������
      enable_irq(PORTA_IRQn);//ʹ�����ж�
    }
}




void DMA_CH4_Handler(void)
{
    DMA_IRQ_CLEAN(DMA_CH4);//���ͨ�������жϱ�־λ    (���������ٴν����ж�)
    DMA_DIS(DMA_CH4);//�ɼ���H�����ݺ�������DMA�жϣ�ֹͣDMA���䡣���ж��д�DMA����

}



//���жϴ�����
void PORTA_IRQHandler()
{
    if((PORTA_ISFR & (1<<29)))                              //PTA29�����ж�,���ж�
    {
      PORTA_ISFR |= (1<<29);                                //д1���жϱ�־λ
/**************�û�����**************************************************/
        
            V_Cnt++;
      
            if(V_Cnt%4== 1)//�жϸ��������Ƿ���Ҫ,�����Լ���Ҫ�������Լ��趨�б�����
            {
              DMA_EN(DMA_CH4);//ʹ��ͨ��CHn Ӳ������
            }  
/*****************************

  ��ֵ�����ӵ��˲�
***************************/
            if (V_Cnt%4==2)
            {
                
                for (int i=0;i<H;i++)
                {
                    if (pixData[V_Cnt/4][i]>THRESHOLD-20)
                        data01[V_Cnt/4][i]=1;else data01[V_Cnt/4][i]=0;
 
                } 
                for (int i=1;i<H-1;i++)
                {
                      if (data01[V_Cnt/4][i-1]==1&&data01[V_Cnt/4][i+1]==1)
                          data01[V_Cnt/4][i]=1;
                }
                

            }
/*****************************

  ������ȡ
***************************/
            if (V_Cnt%4==3)
            {
                int i,tempMiddle;
                if (V_Cnt==3)
                    tempMiddle=40;
                else 
                {
                    tempMiddle=(leftEdge[V_Cnt/4-1]+rightEdge[V_Cnt/4-1])/2;
                }
                for (i=tempMiddle-1;i>0;i--)
                    if (data01[V_Cnt/4][i-1]==0)
                        break;
                leftEdge[V_Cnt/4]=i;
                for (i=tempMiddle+1;i<H-1;i++)
                    if (data01[V_Cnt/4][i+1]==0)
                        break;
                rightEdge[V_Cnt/4]=i;
          
            }
       //printf("%d\n",V_Cnt);
         if (V_Cnt==V*4-1)
         {
              
              Is_SendPhoto=1;
              //disable_irq(PORTA_IRQn);//�ر����ж�
              enable_irq(PORTB_IRQn);//�������ж�
         }
          
    }
}


void PIT0_IRQHandler(void)
{
   countPIT++;
   calcAngle();
   calcAngleByW();
   kalmanFilter(); 
   upright();
   if (countPIT%5==0)
   {
     if (dirFlag) dirControl();
   }
   if (countPIT==20)
   {    
       if (runFlag==1&&count100ms<100) count100ms++;
       if (count100ms>=30&&runFlag==1&&runSpeed>setSpeed)
       {
           runSpeed-=3;
       }
       if (speedFlag)calcSpeedPID();
       countPIT=0;
   }
   PIT_Flag_Clear(PIT0);       //���жϱ�־λ
}
void  setIRQPriority()
{
   set_irq_priority(PORTA_IRQn,0);
   set_irq_priority(PORTB_IRQn,1);
   set_irq_priority(DMA4_VECTORn,2);
   set_irq_priority(PIT0_VECTORn,3);
  // set_irq_priority(PIT1_VECTORn,4);

}

