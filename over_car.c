//******************����ģ��********************************/

#include "config.h"
//******************�ⲿ��������********************************/
extern u8 time_counter;//timer0 ����
extern u8 line_counter;//���� ����
extern u8 time1_counter;//timer1 ����
extern bit update_flag;//timer0 �������
extern bit tl_flag;//0����ǰ�� 1 turn left
extern bit over_flag; //
extern u8 g;//0Ϊǰ�� 1Ϊ��

/**********************����������*******************************/
void over_car()
{
	switch (g)
	{
		//ǰ��
		case 0:
		{
				//����ǰ��ֱ����������
			while(TLIN != 0x01)	;
			pwm_leftback(speed);
			delay_ms(500);
			pwm_leftback(0);
			stop();
			while(k!=1);						//ǰ��δ��⵽��
			forward();							//�ָ�ǰ��
			
			
			break; 
		}
		//��		
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