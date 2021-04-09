
#include <iostream>
#include <vector>
#include <stdexcept>
int output;

struct cell
{
	enum class CellType
	{
		S = -1,
		H = 0,
		E = 1
	};

	CellType T;
	int d = 0;

	cell(CellType T)
		: T(T)
	{}

	cell()
		: T(CellType::E)
	{}

};

std::pair<int, int> fillDistanceMap(std::vector<std::vector<cell>>& grid, const int& Si, const int& Sj)
{
	std::pair<int, int> retval = { 0, 0 };

	std::vector<std::pair<int, int>> queue;
	queue.reserve(50);

	queue.push_back({ Si, Sj });

	if (!(int)grid[Si][Sj].T)
		queue.clear();


	size_t counter = 1;
	while (!queue.empty())
	{
		std::vector<std::pair<int, int>> temp = queue;


		queue.clear();
		queue.reserve(50);

		for (auto p : temp)
		{
			if (grid[p.first][p.second].T == cell::CellType::H)
			{
				retval.second = retval.first;
				retval.first = grid[p.first][p.second].d;

				continue;
			}

			if (p.first + 1 < grid.size())
			{
				if (!grid[p.first + 1ULL][p.second].d)
				{
					grid[p.first + 1ULL][p.second].d = counter;
					queue.push_back({ p.first + 1ULL, p.second });
				}
			}
			if (p.first - 1 >= 0)
			{
				if (!grid[p.first - 1ULL][p.second].d)
				{
					grid[p.first - 1ULL][p.second].d = counter;
					queue.push_back({ p.first - 1ULL, p.second });
				}
			}
			if (p.second + 1 < grid[0].size())
			{
				if (!grid[p.first][p.second + 1ULL].d)
				{
					grid[p.first][p.second + 1ULL].d = counter;
					queue.push_back({ p.first, p.second + 1ULL });
				}
			}
			if (p.second - 1 >= 0)
			{
				if (!grid[p.first][p.second - 1ULL].d)
				{
					grid[p.first][p.second - 1ULL].d = counter;
					queue.push_back({ p.first, p.second - 1ULL });
				}
			}
		}

		counter++;
	}


	for (auto& r : grid)
		for (auto& c : r)
			if (c.d == 0)
			{
				c.d = -1;
				output++;
			}

	grid[Si][Sj].d = 0;

	return retval;
}



int main()
{
	int N, M;
	int Si, Sj, houseN = 0;

	std::vector<std::vector<cell>> grid;
	std::vector<std::vector<cell>> grid2;

	std::cin >> N;
	std::cin >> M;

	grid.resize(N);
	grid2.resize(N);

	for (std::vector<cell>& r : grid)
		r.resize(M);
	for (std::vector<cell>& r : grid2)
		r.resize(M);


	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			char temp;
			std::cin >> temp;
			grid[i][j] = cell((temp == 'S' ? cell::CellType::S : temp == 'H' ? cell::CellType::H : cell::CellType::E));
			grid2[i][j] = grid[i][j];


			if (temp == 'S')
			{
				Si = i;
				Sj = j;
			}

			if (temp == 'H')
				houseN++;
		}
	}

	if (houseN == 1)
	{
		fillDistanceMap(grid2, 0, 0);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (grid2[i][j].T == cell::CellType::H)
				{
					std::cout << grid2[i][j].d;
					return 0;
				}
			}
		}
	}

	auto furthestDisance = fillDistanceMap(grid, Si, Sj);
	fillDistanceMap(grid2, 0, 0);

	std::pair<int, int> currHouse;


	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (!((int)grid[i][j].T))
			{
				currHouse = { i, j };
				i = N;
				j = M;
			}
		}
	}

	for (size_t i = currHouse.first; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (!((int)grid[i][j].T))
			{
				if (grid2[i][j].d == -1)
					continue;

				int jhsA = grid[currHouse.first][currHouse.second].d + grid2[currHouse.first][currHouse.second].d;
				int jhsB = grid[i][j].d + grid2[i][j].d;

				int shA = grid[i][j].d == furthestDisance.first ? furthestDisance.second : grid[i][j].d;
				int shB = grid[currHouse.first][currHouse.second].d == furthestDisance.first ? furthestDisance.second : grid[currHouse.first][currHouse.second].d;

				int shFA = grid[currHouse.first][currHouse.second].d == furthestDisance.first ? furthestDisance.second : furthestDisance.first;
				int shFB = grid[i][j].d == furthestDisance.first ? furthestDisance.second : furthestDisance.first;

				if (jhsA + 2 * shA + shFA > jhsB + 2 * shB + shFB)
				{
					currHouse.first = i;
					currHouse.second = j;
				}
			}
		}
	}

	int sum = 0;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (!((int)grid[i][j].T))
			{
				sum += grid[i][j].d * 2;
			}
		}
	}

	int secondSum = sum;
	secondSum -= grid[currHouse.first][currHouse.second].d;
	secondSum += grid2[currHouse.first][currHouse.second].d;
	secondSum -= grid[currHouse.first][currHouse.second].d == furthestDisance.first ? furthestDisance.second : furthestDisance.first;


	std::cout << secondSum;
	return 0;
}

