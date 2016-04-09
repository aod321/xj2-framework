
#ifndef		__CONFIG_H
#define		__CONFIG_H

/*********************************************************/
#ifndef MAIN_Fosc
#define MAIN_Fosc		22118400L	//定义主时钟
#endif
//#define MAIN_Fosc		12000000L	//定义主时钟
//#define MAIN_Fosc		11059200L	//定义主时钟
//#define MAIN_Fosc		 5529600L	//定义主时钟
//#define MAIN_Fosc		24000000L	//定义主时钟

/*********************************************************/
#include	"STC15F2K60S2.H"
#include "timer.h"
#include "Exti.h"
#include "Lcd.h"
#include "pwm.h"
#include "intrins.h"
#include "line_count.h"
#include "over_car.h"

//*********************函数声明***********************************/
void forward();
void Inline();
void check();
void adjust_right();
void forward();
void turn_left();
void turn_right();
void adjust_left();
void adjust_right();
void turn_leftn(u16 t1,u16 t2);
void turn_rightn(u16 t1,u16 t2);


sbit k =P1^6;//定义红外开关输入端口

 //**********************************************************/
 #ifndef speed
#define speed 120//正常行驶速度 0-255
#endif

#ifndef u8
#define u8 unsigned char
#endif
#ifndef u16
#define u16 unsigned int
#endif
#ifndef u32
#define u32 unsigned long
#endif
#ifndef TLIN
#define TLIN P0&0x03//红外信号线（3路）取P0的低2位 P00最右
#endif

#endif
