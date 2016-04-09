//*****************循迹模块********************************/

#include "config.h"
extern bit update_flag;//timer0 计数标记
extern bit tl_flag;//0正常前行 1 turn left
extern bit over_flag; //
u16 timer1_reg=65536UL - (MAIN_Fosc/40UL);

void Inline()		//检测黑线信号，检测到黑线时变为高电平，平时低电平
{
	Line_Count();
	if(tl_flag)
	{
		//左转，定时器1控制左转时间
		pwm_left(0);
		pwm_right(speed);
		
		TR1=0;
		TH1 = (u8)(timer1_reg>> 8);
		TL1 = (u8)timer1_reg;
		TR1=1;
		tl_flag=0;
	}
	
	switch(TLIN)
	{
		//没检测到黑线时，直行
		case 0x00:    forward(); 									break;
		
		//右边检测到黑线时,左转
		case 0x01:  adjust_left(); 								break;
		
		//左边检测到黑线时，右转
		case 0x02: 		adjust_right(); 						break;
				
		//不可能
		case 0x03: 		 forward(); 								break;
		
//
		default:  break;
	}

}