#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
int n, l;
int main()
{
	std::cin >> n;
	std::cin >> l;
	int* position = new int[n];
	int* speed = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> position[i];
		std::cin >> speed[i];
	}
	for (int i = 0; i < l; i++)
	{


		for (int j = 0; j < n; j++)
		{
			if (j == n-1)
			{
				std::cout << i;
				return 0;
			}
			if (position[j] != position[j + 1])
			{
				break;
			}

		}
		for (int j = 0; j < n; j++)
		{
			position[j] = (position[j]+speed[j])%l;
		}
	}
	std::cout << "ALDRIG";
}

