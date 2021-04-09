#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>

long long int num;
int temp = 0;
int main()
{
	std::cin >> num;
	num++;
	for (int i = num; i > 1; i -= i / 2)
	{
		temp++;
	}
	//std::cout << temp;
	for (int i = temp; i > 0; i--)
	{
		int hypertemp = std::pow(2, i);
		if (num > 0)//(int)hypertemp - 1)
		{

			if (num % hypertemp < hypertemp / 2)
			{
				std::cout << 4;
			}
			else
			{
				std::cout << 7;
			}
		}
	}
}