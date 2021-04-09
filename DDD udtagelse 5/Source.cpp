#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>


long long n,temp,temp2;
int allsame=1;
std::vector<long long> price;
//2*a*b+2*a*n+2*b*n+n^2-prices

std::vector<long long> sums;


long long value(long long start, long long stop, long long size);

int main()
{
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		price.push_back(temp);
	}
	sums.push_back(price[0]);
	for (int i = 1; i < n; i++)
	{
		sums.push_back(sums[i - 1] + price[i]);
	}

	for (int i = 1; i < n; i++)
	{
		if (price[i] != price[i - 1])
		{
			allsame = 0;
			break;
		}
	}



	if (allsame == 1)
	{
		if (price[0] > n)
		{
			std::cout << 0;
			return 0;
		}
		else
		{
			std::cout << n * n - price[0] * n;
		}
		return 0;
	}

	std::cout << value(0, n - 1, n);

}


long long value(long long start, long long stop, long long size)
{
	if (size > stop - start+1)
		size = stop - start+1;
/*	if (size == 1)
	{
		for (long long i = size; i > 0; i--)
		{

			for (long long j = 0; j < size-i; j++)
			{
				if (i * i > sums[i + j] - sums[start + j] + price[start + j])
				{
					long long output = (i) * (i)-sums[i+j] + sums[start+j] - price[start+j];
					return output;
				}
			}
		}
	}*/

	for (long long i = size; i > 0; i--)
	{

		for (long long j = 0; j < size-i+1; j++)
		{
			if (i * i > sums[i+j-1+start] - sums[start+j] + price[start+j])
			{
				long long output = (i) * (i)-sums[i+j-1+start] + sums[start+j] - price[start+j];
				if (i != 1)
				{
					return output + value(i + j, stop, i) + value(start, start + j - 1, i);
				}
				return output;
			}

		}

	}
	return 0;

}