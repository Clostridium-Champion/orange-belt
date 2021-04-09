#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

int n, m;
std::vector<std::vector<long long>> fish;

std::vector<std::vector<std::vector<std::vector<long long>>>> known;
long long maxSum=0;
long long temp;

long long totalsum(int day, int a, int b, int c);

int main()
{

	std::cin >> n;
	std::cin >> m;
	fish.resize(m);
	known.resize(30);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> temp;
			fish[i].push_back(temp);
		}
	}


	if (n < 4)
	{
		if (n == 1)
		{
			for (int i = 0; i < m; i++)
				maxSum += fish[i][0];
		}
		else if (n == 2)
		{
			for (int i = 0; i < m; i++)
				maxSum += fish[i][0]+fish[i][1];
		}
		else
		{
			for (int i = 0; i < m; i++)
				maxSum += fish[i][0] + fish[i][1]+fish[i][2];
		}


	}

	for (int i = 0; i < m; i++)
	{
		known[i].resize(30);
		for (int j = 0; j < n; j++)
		{
			known[i][j].resize(30);
			for (int k = 0; k < n; k++)
			{
				known[i][j][k].resize(30);

			}
		}
	}

	for (int i = 0; i < n-2; i++)
	{
		for (int j = i+1; j < n-1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				temp = totalsum(m-1, i, j, k);
				if (temp > maxSum)
					maxSum = temp;
			}
		}
	}

	std::cout << maxSum;


}




long long totalsum(int day, int a, int b, int c)
{
	if (a == b || b == c || a == c)
		return 0;

	if (day != 0)
	{
		long long tempmaxsum=0;
		long long output = fish[day][a] + fish[day][b] + fish[day][c];




		for (int i = 0; i < n; i++)
		{
			if (known[day-1][a][b][i] == 0)
			{
				known[day - 1][a][b][i] = totalsum(day - 1, a, b, i);

			}
			if (known[day - 1][a][b][i] > tempmaxsum)
				tempmaxsum = known[day - 1][a][b][i];

		}
		for (int i = 0; i < n; i++)
		{
			if (known[day - 1][a][i][c] == 0)
			{
				known[day - 1][a][i][c] = totalsum(day - 1, a, i, c);

			}
			if (known[day - 1][a][i][c] > tempmaxsum)
				tempmaxsum = known[day - 1][a][i][c];

		}
		for (int i = 0; i < n; i++)
		{
			if (known[day - 1][i][b][c] == 0)
			{
				known[day - 1][i][b][c] = totalsum(day - 1, i, b, c);

			}
			if (known[day - 1][i][b][c] > tempmaxsum)
				tempmaxsum = known[day - 1][i][b][c];

		}

		return output + tempmaxsum;
	}
	else
	{
		return fish[day][a] + fish[day][b] + fish[day][c];
	}

}