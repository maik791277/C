#include <iostream>;
using namespace std;

//Вариант 11

//     1     3     2    6     4    5    12    7   9   8   11  10
//  a    b     c    d      e    f    g      h   i   j   k   l    m
// (37 - 9) / (28 - 9) / ((28 - 9) / 6 ) - (3 * 2)/(2 + 3)*(12 / 5)

int main()
{
	int a = 37, b = 9, c = 28, d = 9, e = 28, f = 9,
		g = 6, h = 3, i = 2, j = 2, k = 3, l = 12, m = 5;

	int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0, d10 = 0, d11 = 0, d12 = 0;

	_asm
	{
		// 37 - 9 = 28
		mov eax, a
		mov d1, eax
		mov eax, b
		sub d1, eax

		//28 - 9 = 19
		mov eax, c
		mov d2, eax
		mov eax, d
		sub d2, eax

		//28 / 19 = 1
		mov edx, 0
		mov eax, d1
		div d2
		mov d3, eax

		//28 - 9 = 19
		mov eax, e
		mov d4, eax
		mov eax, f
		sub d4, eax

		//19 / 6 = 3
		mov edx, 0
		mov eax, d4
		div g
		mov d5, eax

		//1 / 3 = 0
		mov edx, 0
		mov eax, d3
		div d5
		mov d6, eax

		//3 * 2 = 6
		mov eax, h
		mul i
		mov d7, eax

		//2 + 3 = 5
		mov eax, j
		mov d8, eax
		mov eax, k
		add d8, eax

		//6 / 5 = 1
		mov edx, 0
		mov eax, d7
		div d8
		mov d9, eax

		//12 / 5 = 2
		mov edx, 0
		mov eax, l
		div m
		mov d10, eax

		//1 * 2 = 2
		mov eax, d9
		mul d10
		mov d11, eax

		// 0 - 2 = -2
		mov eax, d6
		mov d12, eax
		mov eax, d11
		sub d12, eax
	}

	cout << d12 << endl;

	return 0;
}