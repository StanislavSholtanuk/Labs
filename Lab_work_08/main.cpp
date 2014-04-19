#include <iostream>
using namespace std;
int main()
{
	int a, b, res;
	cin >> a >> b;
	__asm
	{
		mov eax, a
		add eax, b
		mov res, eax
	}
	cout << res;
	return 0;
}