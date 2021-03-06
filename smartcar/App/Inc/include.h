#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include  "common.h"

/*
 * Include 用户自定义的头文件
 */
#include  "MK60_wdog.h"
#include  "MK60_gpio.h"     //IO口操作
#include  "MK60_uart.h"     //串口
#include  "MK60_SysTick.h"
#include  "MK60_lptmr.h"    //低功耗定时器(延时)
#include  "MK60_i2c.h"      //I2C
#include  "MK60_spi.h"      //SPI
#include  "MK60_ftm.h"      //FTM
#include  "MK60_pit.h"      //PIT
#include  "MK60_rtc.h"      //RTC
#include  "MK60_adc.h"      //ADC
#include  "MK60_FLASH.h"    //FLASH
#include  "MK60_it.h"       //中断
#include  "exti.h"



#include  "FIRE_LED.H"          //LED
#include  "FIRE_KEY.H"          //KEY
#include  "FIRE_MMA7455.h"      //三轴加速度MMA7455
#include  "FIRE_NRF24L0.h"      //无线模块NRF24L01+
#include  "FIRE_RTC_count.h"    //RTC 时间转换
#include  "oled12864.h"         //oled12864的驱动
#include  "sccb.h"              //sccb的驱动
#include  "DMA_OV7620.h"        //


#include "display.h"
#include "init.h"
#include "delay.h"
#include "variable.h"
#include "angle.h"
#include "camera.h" 
#include "motor.h"

#endif  //__INCLUDE_H__
