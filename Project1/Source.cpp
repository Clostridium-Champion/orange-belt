#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
int n, sum=0;

bool compare(std::pair<int, int>& v1, std::pair<int, int>& v2)
{
	return v1.second < v2.second;
}

int main()
{
	std::cin >> n;
	std::pair<int, int>* temp = new std::pair<int, int>[2*n];

	for (int i = 0; i < n*2; i++)
	{
		std::cin >> temp[i].second;
		temp[i].first = i+1;
	}
	std::sort(temp, temp + 2 * n, compare);




	for (int i = 0; i < n * 2; i += 2)
	{
		sum += abs(temp[i].second - temp[i + 1].second);
	}

	std::cout << sum << "\n";

	for (int i = 0; i < n * 2; i += 2)
	{
		std::cout << temp[i].first << " ";
	}

	std::cout << "\n";

	for (int i = 1; i < n * 2; i += 2)
	{
		std::cout << temp[i].first << " ";
	}
}