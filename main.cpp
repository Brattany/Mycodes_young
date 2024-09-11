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
		optr.Push('=');//�Ƚ�=��ջ 
		cin>>ch;
		optr.Top(optrTop);
		while( optrTop != '=' || ch != '=')
		{
			//����Ϊ�����ַ�
			if(ch >= '0' && ch <= '9') 
			{
				cin.putback(ch);
				cin>>opnd_data;
				cin>>ch;
				opnd.Push(opnd_data);
			}
		
			//����Ϊ�ַ� 
			//�ֱ���Isp��Icp 
			Is = Isp(optrTop);
			Ic = Icp(ch);
			
			if(Is <= Ic && ch != ')')
			{
				//�������ջ
				optr.Push(ch);
				cin>>ch;
			}
			
			else if(Is > Ic)
			{
				//��opndջ�˳� b�� a���� optrջ�˳�top���γ�����ָ��(a)top(b) 
				opnd.Pop(b);
				optr.Pop(optrTop);
				opnd.Pop(a);
				
				//�����м������������ջ 
				result = mid_result(a,optrTop,b);
				opnd.Push(result);        
			}
			
			else if(Is == Ic && ch == ')')
			{
				//��ջ����������ջ���������� 
				optr.Pop();
				
				cin>>ch;
			}	
			
			//ȡ��optr��ջ��optrTop 
			optr.Top(optrTop);
		}
		
			//���Ľ����Ϊ opnd��ջ��ֵ 
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
