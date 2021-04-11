#include"SqStack.h"
#include<string>
using namespace std;
bool FillReview(char& temp);

int main()
{
	string str1, str2;	//str1记录用户输入（中缀表达式）str2为后缀
	std::cout << "输入表达式" << endl;
	getline(cin, str1);
	std::cout << str1 << endl;
	Sh<char> str(str1.size());	//栈
	/*中缀转换为后缀*/
	int i;
	for (i = 0; i < str1.size(); i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')		//1数字，直接输出.
			str2.push_back(str1[i]);

		else if (str1[i] == '(')			//2左括号，直接入栈
			str.pushStack(str1[i]);
		else if (str1[i] == ')')
		{
			do								//3右括号，将栈顶的运算符出栈，出栈再出栈
			{
				str2.push_back(str.getTopStack());
				str.popStack();
			} while (str.getTopStack() != '(');	//直到左括号。括号不作输出
			str.popStack();						//清除左括号
		}
		else if (str1[i] == '+' || str1[i] == '-' || str1[i] == '*' || str1[i] == '/') //4运算符，
		{
			if (str.getTopStack() == '(' || str1[i] == '*' || str1[i] == '/')			//if (优先级大于栈顶运算符 ||栈顶为左括号)   入栈；
				str.pushStack(str1[i]);
			else								//else	栈顶的运算符出栈；继续比较新的栈顶运算符(一直递归下去) 
			{
				if (!(str.isEmptyStack()))					//若栈为空
				{
					while (!(str.isEmptyStack()))	//直到当前运算符大于栈顶运算符为止；!(str.isEmptyStack())
					{
						str2.push_back(str.getTopStack());
						str.popStack();
					}
					str.pushStack(str1[i]);			//最后将当前运算符入栈；
				}
				else							//若栈不为空,直接入栈
					str.pushStack(str1[i]);	
			}
		}
	}
	str.print();
	do				//5结束时把栈剩余数据出栈到空为止
	{
		str2.push_back(str.getTopStack());
		str.popStack();
	} while (!(str.isEmptyStack()));
	std::cout << "后缀表达式：" << endl;
	std::cout << str2 << endl;						//检查后缀表达式

	int temp1, temp2, temp3,len2;
	len2 = str2.length();
	Sh<int> temp(len2);						//后缀运算所用的栈
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
