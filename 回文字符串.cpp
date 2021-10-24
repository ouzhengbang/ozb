#include <stdio.h>
#include <iostream>
using namespace std;
void f(char* str)
{
	int len = 0, temp;
	while (str[len] != '\0')
	{
		len++;
	}
	temp = len;
	for (int i = 0; i < temp; i++, len--)
	{
		if (str[i] == str[len - 1])
		{
			continue;
		}
		else
		{
			cout << str << " " << "is not a palindrome" << endl;
			return;
		}
	}
	cout << str << " " << "is a palindrome" << endl;
}
int main()
{
	char str[100];
	printf("请输入一段字符:\n");
	scanf_s("%s", &str, sizeof(&str));
	f(str);
	return 0;
}
