#include<iostream>
using namespace std;
class Hanoi {
public:
	int f(int num);
	void move(int num, char a, char b, char c);
};
int Hanoi::f(int num) {
	if (num == 1) {
		return 1;
	}
	if (num == 2) {
		return 2;
	}
	return f(num - 1) + f(num - 2);
}
void Hanoi::move(int num, char a, char b, char c)
{
	if (num == 1)
	{
		cout << "第1步：" << a << "-->" << c << endl;
	}
	else
	{
		move(num - 1, a, c, b);
		cout << "第" << num << "步" << ":" << a << "-->" << c;
		cout << endl;
		move(num - 1, b, a, c);
		cout << "第" << num << "步" << ":" << b << "-->" << c;
		cout << endl;
	}
}
int main() {
	Hanoi h;
	int num = 0;
	cout << "圆盘个数：" << endl;
	cin >> num;
	cout << "移动的步骤：" << endl;
	h.move(num, 'a', 'b', 'c');
	cout << endl;
	cout << "移动的次数：" << h.f(num) << endl;
	return 0;
}
