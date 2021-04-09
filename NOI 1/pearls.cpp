#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

int La, Lb, k, q;


std::string A;
std::string B;

std::vector<std::pair<char,char>> ugly;
char temp;
char temp2;
int temp3;
int b;

std::vector<char> solution;
std::vector<int> output;

int main()
{
	std::cin >> La;
	std::cin >> Lb;
	std::cin >> k;
	std::cin >> q;
	std::cin >> A;
	std::cin >> B;
	ugly.resize(k);

	if (k == 0)
	{
		for (int i = 0; i < q; i++)
		{
			std::cin >> temp3;
			output.push_back(temp3);
		}

		for (int i = 0; i < q; i++)
		{



			int omegatemp1 = output[i]/(2*B.size());
			int omegatemp2 = output[i]%(2*B.size());

			if (omegatemp2 % 2 == 0)
			{
				std::cout << A[omegatemp1] << '\n';
			}
			else
			{
				std::cout << B[omegatemp2 / 2] << '\n';
			}

		}
		return 0;

	}




	for (int i = 0; i < k; i++)
	{
		std::cin >> temp;
		std::cin >> temp2;
		ugly[i].first = temp;
		ugly[i].second = temp2;
	}

	for (int i = 0; i < q; i++)
	{
		std::cin >> temp3;
		output.push_back(temp3);
	}


	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			b = 0;
			for (int t = 0; t < k; t++)
			{
				if (A[i] == ugly[t].first)
				{
					if (B[j] == ugly[t].second)
					{
						b = 1;
						break;
					}
				}
			}
			if (b != 1)
			{
				solution.push_back(A[i]);
				solution.push_back(B[j]);
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		std::cout << solution[output[i]] << '\n';
	}

}