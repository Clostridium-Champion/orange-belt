#include <iostream>
#include <math.h>
#include <array>
#include <vector>


int n, r;
int currsum;
int maxsum;
int maxsumindex;
int temp;
std::vector<int> fish;
std::vector<int> sums;
int main()
{
	std::cin >> n;
	std::cin >> r;
	fish.reserve(200000);
	sums.reserve(200000);
	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		fish.push_back(temp);
	}
	sums.push_back(fish[0]);
	for (int i = 1; i < n; i++)
	{
		sums.push_back(fish[i] + sums[i - 1]);
	}
	if (r == 0)
	{
		std::cout << 0;
		return 0;
	}

	if (r > n / 2)
	{

		std::cout << sums[n-1];
		return 0;
	}

	if (r == n / 2)
	{
		if (n % 2 == 0)
		{
			std::cout << sums[n - 1];
			return 0;
		}
		else
		{
			temp = std::max(sums[n - 1] - fish[0], sums[n - 2]);
			std::cout << temp;
			return 0;
		}
	}



	for (int i = r+1; i < n - r + 1; i++)
	{
		currsum = sums[i + r-1] - sums[i - r-1];

		if (currsum > maxsum)
		{
			maxsum = currsum;
		}
	}

	std::cout << maxsum;

}