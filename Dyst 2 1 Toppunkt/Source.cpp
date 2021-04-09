#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>

int n, largestvalue = 0, largestvalueindex = -1, largestvalueindex2 = -1, largestvalueindexindex, largestvalueindexindex2, temp, supertemp;

int main()
{
	std::vector<int> list;
	std::vector<int> peakpoints;

	std::cin >> n;

	list.reserve(n);
	peakpoints.reserve(n / 2);

	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		list.push_back(temp);
	}

	//delete duplicates on either side
	for (int i = 0; i < list.size() / 2 + 1; i++)
	{
		temp = 0;

		if (list[i] == list[i + 1])
		{
			list[i + 1] = list[i + 1] + 1;
			temp = 1;
		}
		if (list[list.size() - 1 - i] == list[list.size() - 2 - i])
		{
			list[list.size() - 2 - i] = list[list.size() - 2 - i] + 1;
			temp = 1;
		}

		if (temp == 0)
		{
			break;
		}
	}
	//end of delete duplicates on either side

	//find peakpoints
	if (list[0] > list[1])
	{
		peakpoints.push_back(0);

		if (list[0] > largestvalue)
		{
			largestvalue = list[0];
			largestvalueindex = 0;
			largestvalueindexindex = peakpoints.size() - 1;
		}
	}

	for (int i = 1; i < n - 1; i++)
	{
		if (list[i] >= list[i - 1] && list[i] >= list[i + 1])
		{
			peakpoints.push_back(i);

			if (list[i] > largestvalue)
			{
				largestvalue = list[i];
				largestvalueindex = i;
				largestvalueindexindex = peakpoints.size() - 1;
				largestvalueindex2 = -1;
				largestvalueindexindex2 = -1;
			}
			else if (list[i] == largestvalue)
			{
				largestvalueindex2 = list[i];
				largestvalueindexindex2 = peakpoints.size() - 1;
			}
		}
	}

	if (list[n - 1] > list[n - 2])
	{
		peakpoints.push_back(n - 1);

		if (list[n - 1] > largestvalue)
		{
			largestvalue = list[n - 1];
			largestvalueindex = n - 1;
			largestvalueindexindex = peakpoints.size() - 1;
			largestvalueindex2 = -1;
		}
		else if (list[n - 1] == largestvalue)
		{
			largestvalueindex2 = list[n - 1];
			largestvalueindexindex2 = peakpoints.size() - 1;
		}
	}
	//end of find peakpoints


	//fix multiple toppoints
	if (largestvalueindex2 > -1)
	{
		list[largestvalueindex + 1] = INT32_MAX;
		peakpoints[largestvalueindexindex] = largestvalueindex + 1;

		largestvalueindex += 1;
		largestvalue = INT32_MAX;
		largestvalueindex2 = -1;
	}
	//end of fix multiple toppoints

	//test climbable
	bool climbableright = true, climbableleft = true;

	for (int i = peakpoints.size() - 1; i > largestvalueindexindex; i--)
	{
		if (peakpoints[i] - largestvalueindex > list[largestvalueindex] - list[peakpoints[i]])
		{
			climbableright = false;
			break;
		}
	}

	for (int i = 0; i < largestvalueindexindex; i++)
	{
		if (largestvalueindex - peakpoints[i] > list[largestvalueindex] - list[peakpoints[i]])
		{
			climbableleft = false;
			break;
		}
	}
	//end of test climbable


	//make climbable
	if (climbableleft == false)
	{
		if (climbableright == false)
		{
			list[largestvalueindex] = INT32_MAX;
		}
		else
		{
			list[largestvalueindex - 1] = INT32_MAX;
			peakpoints[largestvalueindexindex] = largestvalueindex - 1;
			largestvalueindex -= 1;
			largestvalue = INT32_MAX;
		}
	}
	else if (climbableright == false)
	{
		list[largestvalueindex + 1] = INT32_MAX;
		peakpoints[largestvalueindexindex] = largestvalueindex + 1;
		largestvalueindex += 1;
		largestvalue = INT32_MAX;
	}
	//end of make climbable



	//get rid of duplicates
	for (int i = 0; i < largestvalueindex; i++)
	{
		if (list[i] == list[i + 1])
		{
			int j = 1;
			while (list[i] == list[i + j])
			{
				list[i + j] += j;
				j++;
			}

			i = j;
		}
	}
	//end of get rid of duplicates

	peakpoints.clear();
	peakpoints.reserve(n / 2);
	largestvalue = 0;
	largestvalueindex = -1;
	largestvalueindex2 = -1;
	largestvalueindexindex = 0;
	largestvalueindexindex2 = 0;

	//find peakpoints again
	if (list[0] > list[1])
	{
		peakpoints.push_back(0);

		if (list[0] > largestvalue)
		{
			largestvalue = list[0];
			largestvalueindex = 0;
			largestvalueindexindex = peakpoints.size() - 1;
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (list[i] >= list[i - 1] && list[i] >= list[i + 1])
		{
			peakpoints.push_back(i);

			if (list[i] > largestvalue)
			{
				largestvalue = list[i];
				largestvalueindex = i;
				largestvalueindexindex = peakpoints.size() - 1;
				largestvalueindex2 = -1;
				largestvalueindexindex2 = -1;
			}
			else if (list[i] == largestvalue)
			{
				largestvalueindex2 = list[i];
				largestvalueindexindex2 = peakpoints.size() - 1;
			}
		}
	}
	if (list[n - 1] > list[n - 2])
	{
		peakpoints.push_back(n - 1);

		if (list[n - 1] > largestvalue)
		{
			largestvalue = list[n - 1];
			largestvalueindex = n - 1;
			largestvalueindexindex = peakpoints.size() - 1;
			largestvalueindex2 = -1;
		}
		else if (list[n - 1] == largestvalue)
		{
			largestvalueindex2 = list[n - 1];
			largestvalueindexindex2 = peakpoints.size() - 1;
		}
	}
	//end of find peakpoints again

	//fix unclimbable peakpoints
	temp = 0;
	for (int i = temp + 1; i < largestvalueindexindex; i++)
	{
		if (peakpoints[i] - peakpoints[temp] > list[peakpoints[i]] - list[peakpoints[temp]])
		{
			peakpoints.erase(peakpoints.begin() + i);
			largestvalueindexindex--;
			i--;
		}
		else
		{
			temp = i;
		}
	}

	temp = peakpoints.size() - 1;
	if (temp > 0)
	{
		for (int i = temp - 1; i > largestvalueindexindex; i--)
		{
			if (peakpoints[temp] - peakpoints[i] > list[peakpoints[i]] - list[peakpoints[temp]])
			{
				peakpoints.erase(peakpoints.begin() + i);
				temp--;
			}
			else
			{
				temp = i;
			}
		}
	}
	//end of fix unclimbable peakpoints


	//do the climb
	for (int i = largestvalueindexindex; i > 0; i--)
	{
		if (peakpoints[i] < peakpoints[i - 1])
		{
			for (int j = peakpoints[i] + 1; j < peakpoints[i - 1]; j++)
			{
				if (peakpoints[i - 1] - j > list[j] - list[peakpoints[i - 1]])
				{
					list[j] = list[j - 1] - 1;
				}
			}
		}
		else
		{
			for (int j = peakpoints[i] - 1; j > peakpoints[i - 1]; j--)
			{
				if (j - peakpoints[i - 1] > list[j] - list[peakpoints[i - 1]])
				{
					list[j] = list[j + 1] - 1;
				}
			}
		}
	}

	for (int i = largestvalueindexindex; i < peakpoints.size() - 1; i++)
	{

		if (peakpoints[i] < peakpoints[i + 1])
		{
			for (int j = peakpoints[i] + 1; j < peakpoints[i + 1]; j++)
			{
				if (peakpoints[i + 1] - j > list[j] - list[peakpoints[i + 1]])
				{
					list[j] = list[j - 1] - 1;
				}
			}
		}
		else
		{
			for (int j = peakpoints[i] - 1; j > peakpoints[i + 1]; j--)
			{
				if (j - peakpoints[i + 1] > list[j] - list[peakpoints[i + 1]])
				{
					list[j] = list[j + 1] - 1;
				}
			}
		}
	}
	//end of do the climb

	//output
	for (int i = 0; i < n; i++)
	{
		std::cout << list[i] << " ";
	}
	//end of output
}