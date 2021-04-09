#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>

unsigned long long N, L, P, output;

int main()
{
	std::cin >> N;
	std::cin >> L;
	std::cin >> P;
	/*while (N > 1)
	{

		L = (L) / 2-1;
		output++;
		if (L < 1)
		{
			std::cout << output;
			return 0;
		}
		N--;
	}
	output += L / P;

	if (output > 10000)
	{
		std::cout << "hopeless";
		return 0;
	}
	std::cout << output;*/
	output= (int)(L / (pow(2, N - 1)) / P);
	if (output > 10000)
	{
		std::cout << "hopeless";
		return 0;
	}
	std::cout << output;
}