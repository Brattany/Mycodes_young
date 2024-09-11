#ifndef _HELP_FUN_h
#define _HELP_FUN_H
#include<math.h>

int Isp(char e)//判断栈内运算符的优先级
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
		default:		//	缺省情况 
			return -1;
	}
} 

int Icp(char e)//判断栈外运算符的优先级
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
		default:		//	缺省情况 
			return -1;
	}
}

int mid_result(int a, char ch, int b)//计算中间值
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
