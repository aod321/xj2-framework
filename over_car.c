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
			while(TLIN != 0x01) ;
			pwm_leftback(speed);					//��ת���֣�ԭ�ص����Ƕ�
			delay_ms(500);		
			pwm_left(speed);							//����ֹͣ��ת							
			stop();												//��ͷ��ֱ�Ժ�ͣ��
			while(k!=1);						//δ��⵽ǰ���г�
			
			forward();							//�ָ�ǰ��
			over_flag=0;						//����ģʽ����
			
			
			break; 
		}
		//��		
		case 1:	
		{
				forward();
				pwm_left(speed);						//���Եó����ٶȿ���ת��������
				delay_ms(2000);							//ʱ�������
				forward();	
				while(TLIN != 0x01)							//�ұ�δѹ��
				{
					pwm_right(speed-28);			//��ת			�����Եó�һ��ײ�ߵ��ʺϽǶ�
				}
				over_flag=0;										//����ģʽ����
				
//				forward();										//ֹͣ��ת�ָ�ǰ��
//			delay_ms(400);									//ǰ��400�����
////			pwm_
			
			
			
			
			break;
		}
	}
}