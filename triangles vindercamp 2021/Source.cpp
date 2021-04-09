#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>

int n;


int main()
{
	std::cin >> n;
	int** triangle = new int* [n];
	for (int i = 0; i < n; i++)
		triangle[i] = new int[n];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			std::cin >> triangle[i][j];
		}

	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n-i; j++)
		{
			triangle[n - 1 - i][j] += std::max(triangle[n - i][j], triangle[n - i][j + 1]);

		}
	}
	std::cout << triangle[0][0];
}

