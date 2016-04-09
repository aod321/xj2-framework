#include "config.h"
//*****************s*外部变量引用********************************/
extern u8 time_counter;//timer0 计数
extern u8 line_counter;//黑线 计数
extern u8 time1_counter;//timer1 计数
extern bit update_flag;//timer0 计数标记
extern bit tl_flag;//0正常前行 1 turn left
extern bit over_flag; //
extern u8 g;//0为前车 1为后车
/*************************************************************/
//电机模块管脚
//将右电机信号线接P25 pwm0
//将左电机信号线接P26 pwm1
//将左反转信号线接P27	pwm2
/**************************************************************/
//压线标志位
bit L1=0;//最右侧标志位
bit L2=0;//最左侧标志位
//bit L3=0;
//bit L4=0;

u8 flag=0;

/*************************主函数***********************************/
void main()
{ 
	char dis_code[10]={"---cm"};
	Initialize_LCD();// init LCD1602
	PCA_Init();//pwm初始化
	Timer_config();
	EXTI_config();
	EA=1;

	check();//初始化检测前方小车
	forward(); //直行

	ClearLine(1);									//LCD删行
	ClearLine(2);

	//调试用 1-255
	delay_ms(200);
				PutString(1,1,"Line_counter:");				//LCD显示		

		WriteChar(1,7,line_counter);
		PutString(2,1,dis_code);
//		PutString(2,7,"mode:");
	while(1)
	{ 

		Inline();
	//	pwm_left(speed);
	//	pwm_right(0);

	 }
 }


