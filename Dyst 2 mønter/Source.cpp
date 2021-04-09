#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>

long long a, b, c, n;
long long temp;
int main()
{
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a > 4)
	{
		if (a % 2 == 0)
		{
			temp = a / 2 - 2;
			b += temp;
			a = a % 2 + 4;
		}
		else 
		{
			temp = a / 2 - 1;
			b += temp;
			a = a % 2 + 2;
		}

	}




	if (b > 4)
	{
		if (b % 2 == 0)
		{
			temp = b / 2 - 2;
			c += temp;
			b = b % 2 + 4;
		}
		else
		{
			temp = b / 2 - 1;
			c += temp;
			b = b % 2 + 2;
		}

	}


	n = c/3;
	n = n * 20;
	c = c % 3;

	if (c == 2)
	{
		if (b > 1)
		{
			b = b - 2;
			n += 20;
			if (b == 2)
			{
				if (a > 1)
				{
					n += 10;
					std::cout << n;
					return 0;
				}
				else
				{
					std::cout << n;
					return 0;
				}
			}
			else if (b == 1)
			{
				if (a == 4)
				{
					n += 10;
					std::cout << n;
					return 0;
				}
				else if (a == 3)
				{
					n += 5;
					std::cout << n;
					return 0;
				}
				else
				{
					std::cout << n;
					return 0;
				}
			}
			else if (b == 0)
			{
				if (a > 2)
				{
					n += 5;
					std::cout << n;
					return 0;
				}
				else
				{
					std::cout << n;
					return 0;
				}
			}
		}
		else if (b == 1)
		{
			if (a > 1)
			{
				n += 20;
				std::cout << n;
				return 0;
			}
			else
			{
				std::cout << n;
				return 0;
			}
		}
		else if (b == 0)
		{
			if (a > 2)
			{
				n += 5;
				std::cout << n;
				return 0;
			}
		}

	}

	else if (c == 1)
	{
		if (b == 4)
		{
			b = 0;
			n += 20;
			if (a > 2)
			{
				n += 5;
				std::cout << n;
				return 0;
			}
			else
			{
				std::cout << n;
				return 0;
			}
		}
		else if (b == 3)
		{
			if (a > 1)
			{
				a = a - 2;
				b = 0;
				n += 20;
				std::cout << n;
				return 0;
			}
			else if (a < 2)
			{
				n += 10;
				std::cout << n;
				return 0;
			}

		}
		else if (b == 2)
		{
			if (a == 4)
			{
				n += 20;
				std::cout << n;
				return 0;
			}
			else if (a > 1)
			{
				n += 10;
				std::cout << n;
				return 0;
			}
			else
			{
				std::cout << n;
				return 0;
			}
		}
		else if (b == 1)
		{
			if (a == 4)
			{
				n += 10;
				std::cout << n;
				return 0;
			}
			else if (a == 3)
			{
				n += 5;
				std::cout << n;
				return 0;
			}
			else
			{
				std::cout << n;
				return 0;
			}
		}
	}

	else if (c == 0)
	{
		if (b > 2)
		{
			n += 10;
			b = b - 3;
			if (b == 1)
			{
				if (a == 4)
				{
					n += 10;
					std::cout << n;
					return 0;
				}
				else if (a == 3)
				{
					n += 5;
					std::cout << n;
					return 0;
				}
				else
				{
					std::cout << n;
					return 0;
				}
			}
			else if (b == 0)
			{
				if (a > 2)
				{
					n += 5;
					std::cout << n;
					return 0;
				}
			}
		}
		else if (b == 2)
		{
			if (a > 1)
			{
				n += 10;
				std::cout << n;
				return 0;
			}
			else
			{
				std::cout << n;
				return 0;
			}
		}
		else if (b == 1)
		{
			if (a == 4)
			{
				n += 10;
				std::cout << n;
				return 0;
			}
			else if (a == 3)
			{
				n += 5;
				std::cout << n;
				return 0;
			}
			else
			{
				std::cout << n;
				return 0;
			}
		}
		else if (b == 0)
		{
			if (a > 2)
			{
				n += 5;
				std::cout << n;
				return 0;
			}
		}
	}




	std::cout << n;
	return 0;
}