#ifndef _HELP_FUN_h
#define _HELP_FUN_H
#include<math.h>

int Isp(char e)//�ж�ջ������������ȼ�
{
	switch(e)
	{
		case '=':
			return 0;
		case '(':
			return 1;
		case '*':case'/':
			return 5;
		case '+':case'-':
			return 3;
		case ')':
			return 6;
		default:		//	ȱʡ��� 
			return -1;
	}
} 

int Icp(char e)//�ж�ջ������������ȼ�
{
		switch(e)
	{
		case '=':
			return 0;
		case '(':
			return 6;
		case '*':case'/':
			return 4;
		case '+':case'-':
			return 3;
		case ')':
			return 1;
		default:		//	ȱʡ��� 
			return -1;
	}
}

int mid_result(int a, char ch, int b)//�����м�ֵ
{
	switch(ch)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return 0;
	}
} 

#endif
