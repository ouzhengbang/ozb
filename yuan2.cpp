#include <iostream>
using namespace std;

//long Factorial(long n) {
// if (n==1)
// {
//  return 1;
// }
// else
// {
//  return n * (n - 1);
// }
//}
//int main(){
// long n;
// cout << "请输入n的值：" << endl;
// cin >> n;
// cout <<"n的阶乘为：" << Factorial(n) << endl;
// return 0;
//}

long Factorial(long n) {
	long a = 1;

	for (long i = 1; i <= n; i++)
	{
		a *= i;

	}
	return a;
}
int main() {
	long n;
	cin >> n;
	cout << Factorial(n) << endl;
	return 0;
}