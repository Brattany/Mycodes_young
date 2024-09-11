#include <iostream>
#include "_lk_stack.h"
#include "_help_fun.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Demonstration(void)
{
	cout<<"NOTICE!"<<endl<<"---------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"This is a simple calculator for integer and the operators are: + - * /."<<endl;
	cout<<"You must keep in mind that every integer should be input in a standard way and space input is inhibited."<<endl;
	cout<<"For a nefative number, we can't do multiplication or division, but for addition, you can do like this: 2+(-1) = 2 - 1."<<endl;
	cout<<"OK,Let's start it!(Input your formular below)"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}

int main() 
{
	LinkStack<int> opnd; 	     //opnd stack
	LinkStack<char> optr;	     //optr stack
	char ch = '0';				 //input to 'ch'
	char optrTop;
	int opndTop,Ic,Is,opnd_data;
	int a, b, result;
	bool flag = 1,button;
	
	Demonstration();
	
	while(flag)
	{
		cout<<"Start:"<<endl;
		optr.Push('=');//先将=入栈 
		cin>>ch;
		optr.Top(optrTop);
		while( optrTop != '=' || ch != '=')
		{
			//输入为数字字符
			if(ch >= '0' && ch <= '9') 
			{
				cin.putback(ch);
				cin>>opnd_data;
				cin>>ch;
				opnd.Push(opnd_data);
			}
		
			//输入为字符 
			//分别求Isp和Icp 
			Is = Isp(optrTop);
			Ic = Icp(ch);
			
			if(Is <= Ic && ch != ')')
			{
				//运算符入栈
				optr.Push(ch);
				cin>>ch;
			}
			
			else if(Is > Ic)
			{
				//从opnd栈退出 b和 a，从 optr栈退出top，形成运算指令(a)top(b) 
				opnd.Pop(b);
				optr.Pop(optrTop);
				opnd.Pop(a);
				
				//计算中间结果并将结果入栈 
				result = mid_result(a,optrTop,b);
				opnd.Push(result);        
			}
			
			else if(Is == Ic && ch == ')')
			{
				//将栈顶‘（’出栈，对消括号 
				optr.Pop();
				
				cin>>ch;
			}	
			
			//取出optr的栈顶optrTop 
			optr.Top(optrTop);
		}
		
			//最后的结果即为 opnd的栈顶值 
		opnd.Top(result);
		cout<<"The reult is:"<<result<<endl;
		optr.Clear();
		opnd.Clear();
		
		cout<<"Do you want to continue? press 1 to continue, press 0 to stop."<<endl;
		cin>>button;
		flag = button;
	}
	
	cout<<"Thank you for your using!"<<endl;
	return 0;
}
