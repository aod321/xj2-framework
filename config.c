#include "config.h"
//***************全局变量定义**************************************/
extern u8 time_counter=0;//timer0 计数
extern u8 line_counter=0;//黑线 计数
extern u8 time1_counter=0;//timer1 计数
extern bit update_flag=0;//timer0 计数标记
extern bit tl_flag=0;//0正常前行 1 turn left
extern bit over_flag=0; //超车标志位
extern u8 g=0;//0为前车 1为后车