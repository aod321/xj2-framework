#include "config.h"

/***************************��ǰ��*****************************/
void forward() 
{
		pwm_left(speed);
		pwm_right(speed);
}
/*��ת90�ȣ��Զ��ָ�*/
void turn_left()
{
	//���Բ����޸�ת��ģʽ
		pwm_left(0);
		pwm_right(speed);
	//���Բ�����1-255
		delay_ms(2000);
		pwm_left(speed);
		pwm_right(speed);
}

/*��ת90�ȣ��Զ��ָ�*/
void turn_right()
{
	//���Բ����޸�ת��ģʽ
		pwm_left(speed);
		pwm_right(0);
	//���Բ�����0-65536
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
		// ��ת
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
//��ת�ɵ����Զ��ָ�
//t1:������ת״̬ʱ�� 1-65536
//t2:�ص�ʱ�� 1-65536
*************************/
void turn_leftn(u16 t1,u16 t2)
{
	//���Բ����޸�ת��ģʽ
		pwm_left(0);
		pwm_right(speed);
	//:������ת״̬ʱ��
		delay_ms(t1);
		//�ص�
		//�ص�ʱpwm����Ҫ���㡢����
		pwm_left(speed);
		pwm_right(0);
			//�ص�ʱ��
		delay_ms(t2);
		//�ָ�ǰ��
		pwm_left(speed);
		pwm_right(speed);
}

/************************
//��ת�ɵ���֧��ת���ص�
//t1:������ת״̬ʱ�� 1-255
//t2:�ص�ʱ�� 1-255
*************************/
void turn_rightn(u16 t1,u16 t2)
{
	
	//���Բ����޸�ת��ģʽ
		pwm_left(speed);
		pwm_right(0);
	//������ת״̬ʱ��
		delay_ms(t1);
		
		//�ص�
		//�ص�ʱpwm����Ҫ���㡢����
		pwm_left(0);
		pwm_right(speed);
			//�ص�ʱ��
		delay_ms(t2);
		
		//�ָ�ǰ��
		pwm_left(speed);
		pwm_right(speed);

}






	