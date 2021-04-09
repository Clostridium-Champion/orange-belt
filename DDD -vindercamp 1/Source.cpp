#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <queue>


int n, h,temp;
int output=1;
std::vector<int> x;
std::vector<int> y;
float hypertemp;
int curr=2;
int forwards=1;
float slope(float y2, float y1, float x2, float x1)
{
	return (y2 - y1) / (x2 - x1);
}
float intersect(float y2, float y1, float x2, float x1)
{
	//std::cout << (h - y2) / 1.0f / slope(y2, y1, x2, x1) << "\n";
	return (h - y2) /1.0f/ slope(y2, y1, x2, x1)+x2;
}
float tempslope;
int main()
{
	std::cin >> n;
	std::cin >> h;

	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		x.push_back(temp);
		std::cin >> temp;
		y.push_back(temp);
	}


	hypertemp = intersect(y[curr + 1], y[curr], x[curr + 1], x[curr]);
	for (int i = 2; i < n - 3; i += 2)
	{

		if (hypertemp == x[i + 2])
		{
			continue;
		}
		else if (hypertemp < x[i + 2])
		{
			if (slope(y[i + 2], h, x[i + 2], hypertemp) > slope(y[i + 2], y[i + 1], x[i + 2], x[i + 1]))
			{
				output++;
				i += 2;
				curr = i;
				hypertemp = intersect(y[curr + 1], y[curr], x[curr + 1], x[curr]);
			}

		}
		else
		{
			if (slope(h, y[i], hypertemp,x[i]) < slope(y[i + 1], y[i], x[i + 1], x[i]))
			{
				curr = i;
				hypertemp = intersect(y[curr], y[curr-1], x[curr], x[curr-1]);
			}
		}


	}
	std::cout << output;




}


