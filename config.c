#include "config.h"
//***************ȫ�ֱ�������**************************************/
extern u8 time_counter=0;//timer0 ����
extern u8 line_counter=0;//���� ����
extern u8 time1_counter=0;//timer1 ����
extern bit update_flag=0;//timer0 �������
extern bit tl_flag=0;//0����ǰ�� 1 turn left
extern bit over_flag=0; //������־λ
extern u8 g=0;//0Ϊǰ�� 1Ϊ��