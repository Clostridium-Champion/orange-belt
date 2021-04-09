#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>

int n, m;
char temp;
int main()
{
	int **height;
	int *width;

	std::cin >> n;
	std::cin >> m;

	height = new int*[n];
	width = new int[m];

		for (int i = 0; i < n; i++)
		{
			std::cin >> temp;
			if (temp == 'A')
			{
				width[i] = 0;

			}
			else if (temp == 'B')
			{
				width[i] = -2;

			}
			else if (temp == '#')
			{
				width[i] = -3;
			}
			else 
			{
				width[i] = -1;
			}
			height[i] = new int[width[i]];
			for (int j = 0; j < width[i]; j++)
				std::cin >> height[i][j];
		}


}