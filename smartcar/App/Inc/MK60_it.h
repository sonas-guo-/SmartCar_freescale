/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,Ұ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�Ұ���ѧ��̳ http://www.chuxue123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����Ұ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��Ұ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_it.h
 * @brief      Ұ��K60 ƽ̨�жϸ�λ�ض���ͷ�ļ�
 * @author     Ұ��Ƽ�
 * @version    v5.0
 * @date       2013-06-26
 */


#ifndef __MK60_IT_H__
#define __MK60_IT_H__

/*                          ���¶����ж�������
 *  ��ȡ��Ĭ�ϵ��ж�����Ԫ�غ궨��        #undef  VECTOR_xxx
 *  �����¶��嵽�Լ���д���жϺ���      #define VECTOR_xxx    xxx_IRQHandler
 *  ���磺
 *       #undef  VECTOR_003                         ��ȡ��ӳ�䵽�ж�����������жϺ�����ַ�궨��
 *       #define VECTOR_003    HardFault_Handler    ���¶���Ӳ���Ϸ��жϷ�����
 */

#undef  VECTOR_020
#define VECTOR_020    DMA_CH4_Handler

#undef  VECTOR_084
#define VECTOR_084    PIT0_IRQHandler     //���¶���84���ж�ΪPIT0_IRQHandler�ж�

#undef  VECTOR_085
#define VECTOR_085    PIT1_IRQHandler     //���¶���84���ж�ΪPIT0_IRQHandler�ж�

/********************************************************************************/
#undef  VECTOR_103
#define VECTOR_103    PORTA_IRQHandler    //���¶���103���ж�ΪPORTA_IRQHandler�ж�

#undef  VECTOR_104
#define VECTOR_104    PORTB_IRQHandler    //���¶���104���ж�ΪPORTB_IRQHandler�ж�  

   
void PIT0_IRQHandler(void);
void PORTB_IRQHandler();
void DMA_CH4_Handler(void);
void PORTA_IRQHandler();

void PIT1_IRQHandler(void);



#endif  //__MK60_IT_H__
