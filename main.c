#include "config.h"
//*****************s*�ⲿ��������********************************/
extern u8 time_counter;//timer0 ����
extern u8 line_counter;//���� ����
extern u8 time1_counter;//timer1 ����
extern bit update_flag;//timer0 �������
extern bit tl_flag;//0����ǰ�� 1 turn left
extern bit over_flag; //
extern u8 g;//0Ϊǰ�� 1Ϊ��
/*************************************************************/
//���ģ��ܽ�
//���ҵ���ź��߽�P25 pwm0
//�������ź��߽�P26 pwm1
//����ת�ź��߽�P27	pwm2
/**************************************************************/
//ѹ�߱�־λ
bit L1=0;//���Ҳ��־λ
bit L2=0;//������־λ
//bit L3=0;
//bit L4=0;

u8 flag=0;

/*************************������***********************************/
void main()
{ 
	char dis_code[10]={"---cm"};
	Initialize_LCD();// init LCD1602
	PCA_Init();//pwm��ʼ��
	Timer_config();
	EXTI_config();
	EA=1;

	check();//��ʼ�����ǰ��С��
	forward(); //ֱ��

	ClearLine(1);									//LCDɾ��
	ClearLine(2);

	//������ 1-255
	delay_ms(200);
				PutString(1,1,"Line_counter:");				//LCD��ʾ		

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


