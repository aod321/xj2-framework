//******************����߼���ģ��********************************/
#include "config.h"
//******************�ⲿ��������********************************/
extern u8 time_counter;//timer0 ����
extern u8 line_counter;//���� ����
extern u8 time1_counter;//timer1 ����
extern bit update_flag;//timer0 �������
extern bit tl_flag;//0����ǰ�� 1 turn left
extern bit over_flag; //
extern u8 g;//0Ϊǰ�� 1Ϊ��
void Line_Count()						//����������
{
	if(update_flag==1)						//��ʱ1s��
		{
			update_flag=0;						//���λ���
//			if(line_counter <=1)				//�����ʱ����û�еڶ�����
//			{
				line_counter=0;						//�����������
				tl_flag=0;			
				TR0=0;										//�رռ�ʱ��
//			}
		}
		if(line_counter >=3)						//������־��
		{
			over_flag=1;//������־λ��1
			over_car();
		}
}