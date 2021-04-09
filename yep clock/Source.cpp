#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>

int a, b, c, d, e, f, g, h, i;
int main()
{
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	std::cin >> e;
	std::cin >> f;
	std::cin >> g;
	std::cin >> h;
	std::cin >> i;

	for (int x = 0; x < (4 - 4 * i + g - 2 * d + c - 2 * b + 3 * h - 2 * e + a + 3 * f + 64) % 4; x++)
	{
		std::cout << 1;
		std::cout << " ";
	}
	for (int x = 0; x < -(-8 - 2 * i - 2 * g - d + 3 * c - b + 4 * h - e + 3 * a - f - 64) % 4; x++)
	{
		std::cout << 2;
		std::cout << " ";
	}
	for (int x = 0; x < (4 + i - 4 * g + 3 * d + c - 2 * b + 3 * h - 2 * e + a - 2 * f + 64) % 4; x++)
	{
		std::cout << 3;
		std::cout << " ";
	}
	for (int x = 0; x < -(-8 - 2 * i + 3 * g - d - 2 * c - b - h - e + 3 * a + 4 * f - 64) % 4; x++)
	{
		std::cout << 4;
		std::cout << " ";
	}
	for (int x = 0; x < (4 + i + g - 2 * d + c - 2 * b - 2 * h + 3 * e + a - 2 * f + 64) % 4; x++)
	{
		std::cout << 5;
		std::cout << " ";
	}
	for (int x = 0; x < (8 - 3 * i + 2 * g - 4 * d - 3 * c + b + h + e + 2 * a + f + 64) % 4; x++)
	{
		std::cout << 6;
		std::cout << " ";
	}
	for (int x = 0; x < (4 + i + g - 2 * d - 4 * c + 3 * b - 2 * h - 2 * e + a + 3 * f + 64) % 4; x++)
	{
		std::cout << 7;
		std::cout << " ";
	}
	for (int x = 0; x < (8 - 3 * i - 3 * g + d + 2 * c - 4 * b + h + e + 2 * a + f + 64) % 4; x++)
	{
		std::cout << 8;
		std::cout << " ";
	}
	for (int x = 0; x < -(-4 - i - g - 3 * d - c - 3 * b + 2 * h + 2 * e + 4 * a + 2 * f - 64) % 4; x++)
	{
		std::cout << 9;
		std::cout << " ";
	}

	
}