#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <cmath>

struct node
{
	size_t value;
	std::vector<size_t> connections;


	node()
	{
		connections = std::vector<size_t>();
	}

	node(size_t reserve, size_t value)
		: value(value)
	{
		connections = std::vector<size_t>();
		connections.reserve(reserve);
	}

};

size_t sendsTo(const std::vector<node>& routers, const size_t& r, const size_t& b)
{
	long long curr_min = std::abs(((long long)routers[routers[r].connections[0]].value) - ((long long)b));
	size_t curr_r = routers[r].connections[0];

	for (size_t i = 1; i < routers[r].connections.size(); i++)
	{
		long long temp = std::abs(((long long)routers[routers[r].connections[i]].value) - ((long long)b));

		if (temp < curr_min)
		{
			curr_min = temp;
			curr_r = routers[r].connections[i];
		}
		else if (temp == curr_min && routers[r].connections[i] < curr_r)
		{
			curr_r = routers[r].connections[i];
		}
	}
	return curr_r;
}



int main()
{
	size_t n, m, t;
	std::vector<node> routers;

	std::cin >> n;
	std::cin >> m;
	std::cin >> t;

	routers.reserve(n);

	t--;


	for (size_t i = 0; i < n; i++)
	{	
		size_t temp;
		std::cin >> temp;
		routers.push_back(node(m / n * 10ULL, temp));
	}
	for (size_t i = 0; i < m; i++)
	{
		size_t temp, temp1;
		std::cin >> temp;
		std::cin >> temp1;

		routers[temp - 1].connections.push_back(temp1 - 1);
		routers[temp1 - 1].connections.push_back(temp - 1);
	}

	int test=sendsTo(routers, 0, 0);

	}