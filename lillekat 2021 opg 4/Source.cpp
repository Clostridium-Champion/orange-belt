#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <queue>
#include <climits>
#include <vector>

int n;
std::vector<int> happiness;

std::vector<int> sums;
int max;
int temp;

int output;

int main()
{
	std::cin >> n;
	if (n == 1)
	{
		std::cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		if (temp == 0)
		{
			i--;
			n--;
			continue;
		}
		happiness.push_back(temp);
	}

	sums.push_back(happiness[0]);
	for (int i = 1; i < n; i++)
	{
		sums.push_back(sums[i - 1] + happiness[i]);


	}

	for (int i = 1; i < n+1; i++)
	{
		output += happiness[i - 1] * i;
	}
	max = sums[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (sums[n-1] - sums[i] > max)
		{
			max = sums[n-1] - sums[i];
		}
	}



	std::cout << output+max;
}