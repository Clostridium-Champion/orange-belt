#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>


int N, J;
std::string path;

int curr=1;
int counter;

int main()
{
	std::cin >> N;
	std::cin >> J;
	std::cin >> path;

	while (true)
	{
		for (int i = J; i > -1; i--)
		{
			if (curr + J >= path.size())
			{

				std::cout << counter+1;
				return 0;
			}
			else if (i == 0)
			{
				std::cout << "UMULIGT";
				return 0;
			}
			else if (path[i + curr-1] == '#')
			{
				curr += i;
				counter++;
				break;
			}
		}
	}


}