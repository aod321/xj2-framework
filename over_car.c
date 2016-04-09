//******************超车模块********************************/

#include "config.h"
//******************外部变量引用********************************/
extern u8 time_counter;//timer0 计数
extern u8 line_counter;//黑线 计数
extern u8 time1_counter;//timer1 计数
extern bit update_flag;//timer0 计数标记
extern bit tl_flag;//0正常前行 1 turn left
extern bit over_flag; //
extern u8 g;//0为前车 1为后车

/**********************超车处理函数*******************************/
void over_car()
{
	switch (g)
	{
		//前车
		case 0:
		{
				//继续前进直至碰到右线
			while(TLIN != 0x01) ;
			pwm_leftback(speed);					//反转左轮，原地调整角度
			delay_ms(500);		
			pwm_left(speed);							//左轮停止反转							
			stop();												//车头调直以后停车
			while(k!=1);						//未检测到前方有车
			
			forward();							//恢复前进
			over_flag=0;						//超车模式结束
			
			
			break; 
		}
		//后车		
		case 1:	
		{
				forward();
				pwm_left(speed);						//调试得出该速度可以转进超车区
				delay_ms(2000);							//时间待调试
				forward();	
				while(TLIN != 0x01)							//右边未压线
				{
					pwm_right(speed-28);			//右转			待调试得出一个撞线的适合角度
				}
				over_flag=0;										//超车模式结束
				
//				forward();										//停止反转恢复前行
//			delay_ms(400);									//前进400毫秒后
////			pwm_
			
			
			
			
			break;
		}
	}
}