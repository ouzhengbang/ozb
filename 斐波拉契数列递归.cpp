#include <iostream>
using namespace std;
int f(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 1;
	}
	return f(n - 1) + f(n - 2);
}
int main()
{
	int n;
	cout << "输入你想得到的第几个斐波拉契数列:";
	cin >> n;
	f(n);
	cout << endl;
	cout << "第" << n << "个斐波拉契数列值为:" << f(n) << endl;
	return 0;
}
