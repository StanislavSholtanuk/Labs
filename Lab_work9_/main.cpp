#include <iostream>
using namespace std;

const int s = 1000000000;

int main()
{
	int a, b, res;
	cin >> a >> b;
	_asm
	{
		cmp b, 0
		je one;     if b = 0, then the program needs no calculations, because in this case res = a ^ 0 = 1
		mov eax, a
		mov ecx, b
		dec ecx
		jz noth;  if b = 1, then the program needs no calculations, because in this case res = a^1 = a
			
    multip:
		mul a
		div s
		mov eax, edx
		loop multip
	noth:
		mov res, eax
			jmp end_
	one:
		mov res, 1
	end_:
	}
	cout << res;
	return 0;
}