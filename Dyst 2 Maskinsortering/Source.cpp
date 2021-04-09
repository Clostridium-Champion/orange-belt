#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>

int n, currSizeA=0, currSizeB=0, currSizeS, currSizeOut=0, operations=0;

int hypertemp;

std::vector<int> A;
std::vector<int> B;
std::vector<int> S;
std::vector<std::string> output;
int sortedlist[800];


void testExisting();


int main()
{
	std::cin >> n;
	currSizeS = n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> hypertemp;
		S.vector::push_back(hypertemp);
		sortedlist[i] = S[i];
	}


	currSizeS = n;

	std::sort(sortedlist, sortedlist + n);

	for (int i = 0; i < n; i++)
	{
		if (S[i] == sortedlist[currSizeOut])
		{
			output.vector::push_back("next A\n");
			operations++;
			output.vector::push_back("out A\n");
			operations++;
			currSizeOut++;
			testExisting();
		}
		else
		{
			if (A.vector::size() == 0)
			{
				if (B.vector::size() == 0)
				{
					A.vector::push_back(S[i]);
					output.vector::push_back("next A\n");
					operations++;
				}
				else if(S[i]<B[B.vector::size()-1])
				{
					B.vector::push_back(S[i]);
					output.vector::push_back("next B\n");
					operations++;
				}
				else
				{
					A.vector::push_back(S[i]);
					output.vector::push_back("next A\n");
					operations++;
				}

			}
			else if (B.vector::size() == 0)
			{
				if (S[i] < A[A.vector::size() - 1])
				{
					A.vector::push_back(S[i]);
					output.vector::push_back("next A\n");
					operations++;
				}
				else
				{
					B.vector::push_back(S[i]);
					output.vector::push_back("next B\n");
					operations++;
				}
			}
			else
			{
				if (S[i] > A[A.vector::size() - 1])
				{
					if (S[i] > B[B.vector::size() - 1])
					{
						if (B[B.vector::size() - 1] > A[A.vector::size() - 1])
						{
							B.vector::push_back(S[i]);
							output.vector::push_back("next B\n");
							operations++;
						}
						else
						{
							A.vector::push_back(S[i]);
							output.vector::push_back("next A\n");
							operations++;
						}
					}
					else
					{
						B.vector::push_back(S[i]);
						output.vector::push_back("next B\n");
						operations++;
					}
				}
				else
				{
					if (S[i] > B[B.vector::size() - 1])
					{
						B.vector::push_back(S[i]);
						output.vector::push_back("next B\n");
						operations++;
					}
					else
					{
						if (B[B.vector::size() - 1] < A[A.vector::size() - 1])
						{
							B.vector::push_back(S[i]);
							output.vector::push_back("next B\n");
							operations++;
						}
						else
						{
							A.vector::push_back(S[i]);
							output.vector::push_back("next A\n");
							operations++;
						}
					}
				}
			}

		}
	}

	std::cout << operations << "\n";

	for (int i = 0; i < operations; i++)
	{
		std::cout << output[i];
	}

}


void testExisting()
{
	for (int i = 0; i < A.vector::size(); i++)
	{
		if (A[i] == sortedlist[currSizeOut])
		{
			for (int j = 0; j < A.vector::size() - i - 1; j++)
			{
				output.vector::push_back("move_to B\n");
				operations++;
				B.vector::push_back(A[A.vector::size() - 1]);
				A.vector::pop_back();
				j--;
			}
			output.vector::push_back("out A\n");
			operations++;
			A.vector::pop_back();
			currSizeOut++;
			testExisting();
		}
	}
	for (int i = 0; i < B.vector::size(); i++)
	{
		if (B[i] == sortedlist[currSizeOut])
		{
			for (int j = 0; j < B.vector::size() - i - 1; j++)
			{
				output.vector::push_back("move_to A\n");
				operations++;
				A.vector::push_back(B[B.vector::size() - 1]);
				B.vector::pop_back();
				j--;
			}
			output.vector::push_back("out B\n");
			operations++;
			B.vector::pop_back();
			currSizeOut++;
			testExisting();
		}
	}
}