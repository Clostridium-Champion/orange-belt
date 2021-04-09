#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

int N, M;
int temp;
std::vector<int> nums;
std::vector<int> output;
int currlong, currlongindex,currlongvalue;
int currvalue,length=1,currindex=0;


int temp1, temp2;
int main()
{
	std::cin >> N;
	std::cin >> M;

	for (int i = 0; i < N; i++)
	{
		std::cin >> temp;
		nums.push_back(temp);
	}
	currlongvalue = nums[0];
	currvalue = nums[0];
	for (int i = 1; i < N; i++)
	{
		if (length >= currlong)
		{
			currlong = length;
			currlongindex = currindex;
			currlongvalue = currvalue;
		}
		if (nums[i] == currvalue)
		{
			length += 1;
		}
		else
		{
			currindex = i;
			length = 1;
			currvalue = nums[i];
		}

	}
	if (length >= currlong)
	{
		currlong = length;
		currlongindex = currindex;
		currlongvalue = currvalue;
	}


	output.push_back(currlongindex);
	output.push_back(currlong);



	for (int j = 0; j < M; j++)
	{
		std::cin >> temp1;
		std::cin >> temp2;
		nums[temp1] = temp2;
		currlongvalue = nums[0];
		currvalue = nums[0];
		currindex = 0;
		currlongindex = 0;
		currlong = 0;
		length = 1;
		for (int i = 1; i < N; i++)
		{
			if (length >= currlong)
			{
				currlong = length;
				currlongindex = currindex;
				currlongvalue = currvalue;
			}
			if (nums[i] == currvalue)
			{
				length += 1;
			}
			else
			{
				currindex = i;
				length = 1;
				currvalue = nums[i];
			}

		}
		if (length >= currlong)
		{
			currlong = length;
			currlongindex = currindex;
			currlongvalue = currvalue;
		}
		output.push_back(currlongindex);
		output.push_back(currlong);

	}
	for (int i = 0; i < 2 * M + 2; i+=2)
	{
		std::cout << output[i] << ' ' << output[i + 1] << '\n';
	}
	

}