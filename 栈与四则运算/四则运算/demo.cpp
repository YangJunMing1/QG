#include"SqStack.h"
#include<string>
using namespace std;
bool FillReview(char& temp);

int main()
{
	string str1, str2;	//str1��¼�û����루��׺���ʽ��str2Ϊ��׺
	std::cout << "������ʽ" << endl;
	getline(cin, str1);
	std::cout << str1 << endl;
	Sh<char> str(str1.size());	//ջ
	/*��׺ת��Ϊ��׺*/
	int i;
	for (i = 0; i < str1.size(); i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')		//1���֣�ֱ�����.
			str2.push_back(str1[i]);

		else if (str1[i] == '(')			//2�����ţ�ֱ����ջ
			str.pushStack(str1[i]);
		else if (str1[i] == ')')
		{
			do								//3�����ţ���ջ�����������ջ����ջ�ٳ�ջ
			{
				str2.push_back(str.getTopStack());
				str.popStack();
			} while (str.getTopStack() != '(');	//ֱ�������š����Ų������
			str.popStack();						//���������
		}
		else if (str1[i] == '+' || str1[i] == '-' || str1[i] == '*' || str1[i] == '/') //4�������
		{
			if (str.getTopStack() == '(' || str1[i] == '*' || str1[i] == '/')			//if (���ȼ�����ջ������� ||ջ��Ϊ������)   ��ջ��
				str.pushStack(str1[i]);
			else								//else	ջ�����������ջ�������Ƚ��µ�ջ�������(һֱ�ݹ���ȥ) 
			{
				if (!(str.isEmptyStack()))					//��ջΪ��
				{
					while (!(str.isEmptyStack()))	//ֱ����ǰ���������ջ�������Ϊֹ��!(str.isEmptyStack())
					{
						str2.push_back(str.getTopStack());
						str.popStack();
					}
					str.pushStack(str1[i]);			//��󽫵�ǰ�������ջ��
				}
				else							//��ջ��Ϊ��,ֱ����ջ
					str.pushStack(str1[i]);	
			}
		}
	}
	str.print();
	do				//5����ʱ��ջʣ�����ݳ�ջ����Ϊֹ
	{
		str2.push_back(str.getTopStack());
		str.popStack();
	} while (!(str.isEmptyStack()));
	std::cout << "��׺���ʽ��" << endl;
	std::cout << str2 << endl;						//����׺���ʽ

	int temp1, temp2, temp3,len2;
	len2 = str2.length();
	Sh<int> temp(len2);						//��׺�������õ�ջ
	for (i = 0; i < len2; i++) {
		if (str2[i] >= '0' && str2[i] <= '9') {
			int t = str2[i] - 48;
			temp.pushStack(t);
		}
		else {
			temp1 = temp.getTopStack();
			temp.popStack();
			temp2 = temp.getTopStack();
			temp.popStack();
			if (str2[i] == '+') {
				temp3 = temp2 + temp1;
			}
			else if (str2[i] == '-') {
				temp3 = temp2 - temp1;
			}
			else if (str2[i] == '*') {
				temp3 = temp2 * temp1;
			}
			else if (str2[i] == '/') {
				temp3 = temp2 / temp1;
			}
			temp.pushStack(temp3);
		}
	}
	cout << temp.getTopStack() << endl;
}



bool FillReview(char& temp)
{
	if (temp == '=')
		return false;
	else
		return true;
}
