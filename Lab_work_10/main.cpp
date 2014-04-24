// Task 10, variant 13

#include <iostream>

using namespace std;

int main()
{
	double s = 0;
	int n, m; double x, y = 0;
	cin >> m >> n >> x;

	// formulae for calculsting the s variable in C++:

	//for (int i = n; i >= 1; i--)
	//{
	//	s += 1. / (i * (2 * m + i + 1));
	//	s *= (i + 1) * (i + 1) / x;
	//}
	//s *= 2;

	_asm
	{
		mov ecx, n
			fld s
		calc:

		mov n, ecx;                  n = i
			fld1
			fidiv n;                 1 / i
			fild m
			fiadd m;                 m + m = 2 * m
			add n, 1;                n = i + 1
			fiadd n;                 2 * m + i + 1
			fdiv st(1), st(0);       1 / i / (2 * m + i + 1) = 1 / (i * (2 * m + i + 1))
			fstp y;                  deleting the register with the following expression : 2 * m + i + 1
			fadd st(1), st(0);       s += 1 / (i * (2 * m + i + 1))
			fstp y;                  deleting the register with the following expression : 1 / (i * (2 * m + i + 1))

			fild n;                  n = i + 1 (see the 33th line)
			fimul n;                 n * n = (i + 1) * (i + 1)
			fdiv x;                  (i + 1) * (i + 1) / x
			fmul st(1), st(0);       s *= (i + 1) * (i + 1) / x
			fstp y                   deleting the register with the following expression : (i + 1) * (i + 1) / x

			loop calc

			fadd st(0), st(0);       s + s = 2 * s
			fstp s;                  saving the s variable
	}
	cout << s;
	system("pause");
	return 0;
}