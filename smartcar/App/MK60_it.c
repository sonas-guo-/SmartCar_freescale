/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       MK60_it.c
 * @brief      野火K60 平台中断复位函数
 * @author     野火科技
 * @version    v5.0
 * @date       2013-06-26
 */

#include    "MK60_it.h"
#include    "include.h"

//场中断处理函数
void PORTB_IRQHandler()
{
    if(PORTB_ISFR & (1<<0))//PTB0触发中断,场中断
    {
      PORTB_ISFR |= (1<<0);//写1清中断标志位   
      DMA_PORTx2BUFF_Init (DMA_CH4, (void *)&PTD_B0_IN, pixData, PTC0, DMA_BYTE1, H, DMA_rising_keepon);
 //DMA通道4初始化，PTC0上升沿触发DMA传输，源地址为PTD_BYTE0_IN，目的地址为：pixData ，每次传输1Byte，传输H次后停止传输，目的地址保持不变，关闭通道CHn 硬件请求

      Is_SendPhoto =0;
      V_Cnt=0;       //行采集计数清零
      enable_irq(PORTA_IRQn);//使能行中断
    }
}




void DMA_CH4_Handler(void)
{
    DMA_IRQ_CLEAN(DMA_CH4);//清除通道传输中断标志位    (这样才能再次进入中断)
    DMA_DIS(DMA_CH4);//采集完H个数据后进入这个DMA中断，停止DMA传输。行中断中打开DMA传输

}



//行中断处理函数
void PORTA_IRQHandler()
{
    if((PORTA_ISFR & (1<<29)))                              //PTA29触发中断,行中断
    {
      PORTA_ISFR |= (1<<29);                                //写1清中断标志位
/**************用户任务**************************************************/
        
            V_Cnt++;
      
            if(V_Cnt%4== 1)//判断该行数据是否需要,根据自己需要的行数自己设定判别条件
            {
              DMA_EN(DMA_CH4);//使能通道CHn 硬件请求
            }  
/*****************************

  二值化及杂点滤波
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

  边线提取
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
              //disable_irq(PORTA_IRQn);//关闭行中断
              enable_irq(PORTB_IRQn);//开启场中断
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
   PIT_Flag_Clear(PIT0);       //清中断标志位
}
void  setIRQPriority()
{
   set_irq_priority(PORTA_IRQn,0);
   set_irq_priority(PORTB_IRQn,1);
   set_irq_priority(DMA4_VECTORn,2);
   set_irq_priority(PIT0_VECTORn,3);
  // set_irq_priority(PIT1_VECTORn,4);

}

