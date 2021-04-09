#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <queue>
#include <unordered_set>
std::string text;
std::vector<int> output;

std::unordered_set <char> seen;
int Q;

int New;

int one;
int two;
int three;
char four;


int main()
{
	std::cin >> text;
	std::cin >> Q;

	output.reserve(10000);
	seen.reserve(10000);


	for (int i = 0; i < Q; i++)
	{
		std::cin >> one;
		std::cin >> two;


		if (one == 1)
		{
			std::cin >> four;
			text[two-1] = four;
		}
		else
		{
			std::cin >> three;
			for (int j = 0; j < three - two+1; j++)
			{
				seen.insert(text[two - 1 + j]);
			}
			output.push_back(seen.size());
			seen.clear();
			seen.reserve(10000);

				
		}
	}
	for (int i = 0; i < output.size(); i++)
	{
		std::cout << output[i] << '\n';
	}

}