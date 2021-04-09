#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>


int n;

int main()
{
	std::vector<int> a
	std::cin >> n;

}



std::string a;
int counter;
int main()
{
	std::cin >> a;
	for (int i = 0; i < a.length; i++)
	{
		if (a[i] == '(')
		{
			counter++;
		}
		else
			counter--;

		if (counter < 0)
		{
			std::cout << "ja";
			return 0;
		}

	}
	std::cout << "nej";
}

