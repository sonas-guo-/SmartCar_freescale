/******************** (C) COPYRIGHT 2012-2013 �Ĭ�Ƽ� DEMOK*********
 * �ļ���         �� sccb.h
 * ����           �� OV����ͷSCCB����ͷ�ļ�
 *
 * ʵ��ƽ̨       �� �Ĭ�Ƽ�DEMOK Kinetis������
 * ����           �� �Ĭ�Ƽ�DEMOK Kinetis����С��

 * �Ա�����       �� http://shop60443799.taobao.com/
 * ������������   �� 1030923155@qq.com 
 * ��������QQȺ   �� 103360642

 * ����޶�ʱ��    ��2012-11-12
 * �޶�����        ����
**********************************************************************************/
#ifndef __SCCB_H__
#define __SCCB_H__

#include "common.h"
#include "MK60_gpio.h"


//--- Ĭ��SCL��PA10   SDA��PA11------//
void sccb_init(void);                           //��ʼ��SCCB�˿�ΪGPIO
void sccb_wait(void);                           //SCCBʱ����ʱ
void sccb_start(void);                          //��ʼ��־
void sccb_stop(void);                           //ֹͣ��־
uint8 sccb_sendByte(uint8 data);
void sccb_regWrite(uint8 device,uint8 address,uint8 data);

//--GPIO_DDR_1bit(PORTx,n,ddr)--//
#define SCL_OUT   GPIO_DDR(PTA10,1)      //SCL-PA0����Ϊ����˿�
#define SDA_OUT   GPIO_DDR(PTA11,1)      //SDA-PA1����Ϊ����˿�
#define SDA_IN    GPIO_DDR(PTA11,0)      //SDA-PA1����Ϊ����˿�

//--GPIO_SET_1bit(FFPORTx,n,data)--//
#define SCL_HIGH  GPIO_SET(PTA10,1)
#define SCL_LOW   GPIO_SET(PTA10,0)
#define SDA_HIGH  GPIO_SET(PTA11,1)
#define SDA_LOW   GPIO_SET(PTA11,0)
#define SDA_DATA  GPIO_GET(PTA11) 



#endif