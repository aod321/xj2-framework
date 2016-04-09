//******************标记线计数模块********************************/
#include "config.h"
//******************外部变量引用********************************/
extern u8 time_counter;//timer0 计数
extern u8 line_counter;//黑线 计数
extern u8 time1_counter;//timer1 计数
extern bit update_flag;//timer0 计数标记
extern bit tl_flag;//0正常前行 1 turn left
extern bit over_flag; //
extern u8 g;//0为前车 1为后车
void Line_Count()						//检测黑线条数
{
	if(update_flag==1)						//定时1s到
		{
			update_flag=0;						//标记位清空
//			if(line_counter <=1)				//如果该时间内没有第二根线
//			{
				line_counter=0;						//黑线数量清空
				tl_flag=0;			
				TR0=0;										//关闭计时器
//			}
		}
		if(line_counter >=3)						//超车标志线
		{
			over_flag=1;//超车标志位置1
			over_car();
		}
}