//*****************ѭ��ģ��********************************/

#include "config.h"
extern bit update_flag;//timer0 �������
extern bit tl_flag;//0����ǰ�� 1 turn left
extern bit over_flag; //
u16 timer1_reg=65536UL - (MAIN_Fosc/40UL);

void Inline()		//�������źţ���⵽����ʱ��Ϊ�ߵ�ƽ��ƽʱ�͵�ƽ
{
	Line_Count();
	if(tl_flag)
	{
		//��ת����ʱ��1������תʱ��
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
		//û��⵽����ʱ��ֱ��
		case 0x00:    forward(); 									break;
		
		//�ұ߼�⵽����ʱ,��ת
		case 0x01:  adjust_left(); 								break;
		
		//��߼�⵽����ʱ����ת
		case 0x02: 		adjust_right(); 						break;
				
		//������
		case 0x03: 		 forward(); 								break;
		
//
		default:  break;
	}

}