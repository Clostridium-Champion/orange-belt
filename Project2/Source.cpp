#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>


int longest(int* start, int* end);
int longest(int* start, int* end, int length);



int longest(int* start, int* end)
{
	int length = 1;
	int highest = 0;
	int index = 0;
	int* current = start;


	while (current != end)
	{
		if (*current > highest)
		{
			highest = *current;
			index = current - start;
		}

		current++;
	}

	int path1 = longest(start, start + index, length);
	int path2 = longest(start + index + 1, end, length);

	return path1 > path2 ? path1 : path2;
}


int longest(int* start, int* end, int length)
{
	if (start == end)
		return length;

	int highest = 0;
	int index = 0;
	int* current = start;
	length++;


	while (current != end)
	{
		if (*current > highest)
		{
			highest = *current;
			index = current - start;
		}

		current++;
	}

	int path1 = longest(start, start + index, length);
	int path2 = longest(start + index + 1, end, length);

	return path1 > path2 ? path1 : path2;
}


int main()
{
	int n;
	int* height;

	std::cin >> n;

	height = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> height[i];
	}


	std::cout << longest(height, height + n);

}