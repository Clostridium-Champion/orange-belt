#include <iostream>


int main()
{
	for (int n = 2; n < 9; n++)
	{
		double a = sqrt(4 * n + 1);
		double b = sqrt(n - 1);
		std::cout << a / b << "\n";
		//std::cout << a << " : " << b << "\n";
	}

}