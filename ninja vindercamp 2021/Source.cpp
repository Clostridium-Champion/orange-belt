#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>


int amount=0;
int temp=0;
int main()
{
	std::vector<int> primes;
	primes.resize(8363);
	for (int i = 10001; i < 99999; i+=2)
	{
		for (int j = 3; j < sqrt(i)+1; j+=2)
		{
			if (i % j == 0)
			{
				temp = 1;
				break;
			}
			temp = 0;

		}
		if (temp == 0)
		{
			primes[amount] = i;;
			amount++;

		}

	}
	amount--;
	for (int i = 0; i < amount; i++)
	{
		std::cout << primes[i] << "\n";
	}
	temp = primes[amount];
	std::cout << amount << "\n";
	std::cout << temp;
}