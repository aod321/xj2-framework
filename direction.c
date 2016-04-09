#include "config.h"

/***************************向前走*****************************/
void forward() 
{
		pwm_left(speed);
		pwm_right(speed);
}
/*左转90度，自动恢复*/
void turn_left()
{
	//调试参数修改转弯模式
		pwm_left(0);
		pwm_right(speed);
	//调试参数，1-255
		delay_ms(2000);
		pwm_left(speed);
		pwm_right(speed);
}

/*右转90度，自动恢复*/
void turn_right()
{
	//调试参数修改转弯模式
		pwm_left(speed);
		pwm_right(0);
	//调试参数，0-65536
		delay_ms(2000);
		pwm_left(speed);
		pwm_right(speed);
}

void adjust_left()
{
	u8 temp=TLIN;
		pwm_left(0);
		pwm_right(speed);
	//????????
	//??????
	//??130 delay_ms(100)
	//??170 delay_ms(180) 1?150 too samll
	//
		delay_ms(220);
		//?????
		for(;temp!=0x00;temp=TLIN)//???????
		{
		}
		//??
		pwm_left(speed);
		pwm_right(0);
		//????
		delay_ms(200);
		//????
		pwm_left(speed);
		pwm_right(speed);
		return;
		
}
void adjust_right()
{
		u8 temp=TLIN;
		// 右转
		pwm_left(speed);
		pwm_right(0);
		
		delay_ms(200);

		for(;temp!=0x00;temp=TLIN)//
		{
	//		delay_ms(10);
		}

		pwm_left(0);
		pwm_right(speed);
		//
		delay_ms(150);
		//
		pwm_left(speed);
		pwm_right(speed);
		return;

}

/************************
//左转可调，自动恢复
//t1:保持左转状态时间 1-65536
//t2:回调时间 1-65536
*************************/
void turn_leftn(u16 t1,u16 t2)
{
	//调试参数修改转弯模式
		pwm_left(0);
		pwm_right(speed);
	//:保持左转状态时间
		delay_ms(t1);
		//回调
		//回调时pwm比需要计算、调试
		pwm_left(speed);
		pwm_right(0);
			//回调时间
		delay_ms(t2);
		//恢复前行
		pwm_left(speed);
		pwm_right(speed);
}

/************************
//右转可调，支持转弯后回调
//t1:保持右转状态时间 1-255
//t2:回调时间 1-255
*************************/
void turn_rightn(u16 t1,u16 t2)
{
	
	//调试参数修改转弯模式
		pwm_left(speed);
		pwm_right(0);
	//保持右转状态时间
		delay_ms(t1);
		
		//回调
		//回调时pwm比需要计算、调试
		pwm_left(0);
		pwm_right(speed);
			//回调时间
		delay_ms(t2);
		
		//恢复前行
		pwm_left(speed);
		pwm_right(speed);

}






	