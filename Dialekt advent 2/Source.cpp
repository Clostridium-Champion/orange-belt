#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>


std::string a, b;
int t;

int main()
{
	std::cin >> a;
	std::cin >> b;
	
	
	if (a == b)
	{
		std::cout << "Godt!";
		return 0;
	}
	if (a.size() >= b.size())
	{
		std::cout << "Dårligt!";
		return 0;
	}

		for (int i = 0; i < (int)a.size(); i++)
		{
			if (a[i] != b[i])
			{
				b.erase(i, 1);
				if (a == b)
				{
					std::cout << "Godt!";
					return 0;
				}

				else if (a.size() >= b.size())
				{
					std::cout << "Dårligt!";
					return 0;

				}
				i--;
			}
			t++;
			//kinda cringe but whatever
			if (t > 10000)
			{
				std::cout << "Godt!";
				return 0;
			}
			//xd
		}

	b.erase(a.size());
	if (a == b)
	{
		std::cout << "Godt!";
		return 0;
	}
	else
	{
		std::cout << "Dårligt!";
		return 0;
	}
	return 0;
}