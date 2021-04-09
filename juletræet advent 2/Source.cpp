#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>


int n;

int main()
{
	std::cin >> n;

	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 1; j < (n + 1) / 2 - i; j++)
		{
			std::cout << ' ';
		}
		for (int k = 0; k < 1 + i * 2; k++)
		{
			std::cout << '#';
		}
		std::cout << "\n";
	}
}