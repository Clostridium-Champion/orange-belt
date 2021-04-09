#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <queue>
#include <climits>

std::string a;

int n = a.size();

int main()
{
	std::cin >> a;
	std::getline(std::cin, a);

	for (int i = 0; i < (int)a.size(); i++)
	{
		if (a[i] == ':')
		{
			if (a[i + 1] == ')')
			{
				std::cout << i << '\n';
			}
			else if (a[i + 1] == '-')
			{
				if (a[i + 2] == ')')
				{
					std::cout << i << '\n';
				}
			}
		}
		else if (a[i] == ';')
		{
			if (a[i + 1] == ')')
			{
				std::cout << i << '\n';
			}
			else if (a[i + 1] == '-')
			{
				if (a[i + 2] == ')')
				{
					std::cout << i << '\n';
				}
			}
		}
	}


	return 0;
}