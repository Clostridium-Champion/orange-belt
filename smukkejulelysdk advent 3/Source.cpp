#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>


int main()
{
	int n, m, counter = 0;
	std::string temp;

	std::cin >> n;
	std::cin >> m;
	std::cin >> temp;

	std::vector<std::vector<int>> buttonnum(m, std::vector<int>(n));

	std::string* button = new std::string[m];


	for (int i = 0; i < m; i++)
	{
		//std::cin >> button[i];
	}

	int* lights = new int[n];

	for (int i = 0; i < n; i++)
	{
		if (temp[i] == 'r')
		{
			lights[i] = 0;
		}
		else if (temp[i] == 'g')
		{
			lights[i] = 1;
		}
		else
		{
			lights[i] = 2;
		}
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//buttonnum[i][j] = (int)button[i][j] - 48;
		}
	}

		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				for (int c = 0; c < 3; c++)
				{
					for (int d = 0; d < 3; d++)
					{
						for (int e = 0; e < 3; e++)
						{
							for (int f = 0; f < 3; f++)
							{
								for (int g = 0; g < 3; g++)
								{

									for (int h = 0; h < 3; h++)
									{
										//test for equality
										for (int i = 0; i < n; i++)
										{
											if (i == n - 1)
											{
												std::cout << a+b+c+d+e+f+g+h;
												return 0;
											}
											if (lights[i] != lights[i + 1])
											{
												break;
											}

										}
										for (int i = 0; i < n; i++)
										{
											lights[i] = (lights[i] + buttonnum[0][i]) % 3;
										}

									}
									for (int i = 0; i < n; i++)
									{
										lights[i] = (lights[i] + buttonnum[1][i]) % 3;
									}
								}
								for (int i = 0; i < n; i++)
								{
									lights[i] = (lights[i] + buttonnum[2][i]) % 3;
								}
							}
							for (int i = 0; i < n; i++)
							{
								lights[i] = (lights[i] + buttonnum[3][i]) % 3;
							}
						}
						for (int i = 0; i < n; i++)
						{
							lights[i] = (lights[i] + buttonnum[4][i]) % 3;
						}
					}
					for (int i = 0; i < n; i++)
					{
						lights[i] = (lights[i] + buttonnum[5][i]) % 3;
					}
				}
				for (int i = 0; i < n; i++)
				{
					lights[i] = (lights[i] + buttonnum[6][i]) % 3;
				}
			}
			for (int i = 0; i < n; i++)
			{
				lights[i] = (lights[i] + buttonnum[7][i]) % 3;
			}
		}
	


}
