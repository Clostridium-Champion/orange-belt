#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <queue>

int n, m;

std::vector<std::string> ord1;
std::vector<std::string> ord2;
std::vector<std::string> duplicates;
std::vector<int> duplicateindex1;
std::vector<int> duplicateindex2;
std::string trash;

int curr1, curr2;
int max, mintemp;
int counter;
int temporary;
int skipper;
int main()
{
	std::cin >> n;
	std::cin >> m;

	for (int i = 0; i < n; i++)
	{
		std::cin >> trash;
		ord1.push_back(trash);
	}
	std::cin >> trash;
	for (int i = 0; i < m; i++)
	{
		std::cin >> trash;
		ord2.push_back(trash);
	}
	std::cin >> trash;

	for (int k = 0; k < std::min(n, m); k++)
	{
		skipper = k;
		max = std::max(max, counter);
		counter = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = temporary; j < m; j++)
			{
				if (skipper == 0)
				{
					if (ord1[i] == ord2[j])
					{
						temporary = j + 1;
						i++;
						counter++;

					}
				}
				else 
				{
					skipper--;
				}

			}
		}

		max = std::max(max, counter);
		counter = 0;
		skipper = k;

		for (int i = 0; i < n; i++)
		{
			for (int j = temporary; j < m; j++)
			{
				if (skipper == 0)
				{
					if (ord1[j] == ord2[i])
					{
						temporary = j + 1;
						i++;
						counter++;

					}
				}
				else
				{
					skipper--;
				}

			}
		}
	}

	std::cout << ord1.size() + ord2.size() - max;





}