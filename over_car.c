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
			while(TLIN != 0x01)	;
			pwm_leftback(speed);
			delay_ms(500);
			pwm_leftback(0);
			stop();
			while(k!=1);						//前方未检测到后车
			forward();							//恢复前进
			
			
			break; 
		}
		//后车		
		case 1:	
		{
			while(TLIN != 0x02)
			{
				pwm_left(0);
			}
			adjust_right();
			
			delay_ms(1000);
			while(TLIN != 0x02)
			{
				pwm_left(0);
			}
			
			
			break;
		}
	}
}