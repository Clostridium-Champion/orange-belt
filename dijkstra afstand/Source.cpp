#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <queue>
#include <climits>






int main()
{
    int n, m, u, v;
    std::vector<std::vector<std::pair<int, int>>> nodes;
    std::vector<int> d, p;
    std::priority_queue<std::pair<int, int>> queue;


    std::cin >> n; std::cin >> m; std::cin >> u; std::cin >> v;
    nodes.resize(n);
    d.resize(n);
    p.resize(n);
    u--;
    v--;

    for (auto& dr : d)
    {
        dr = INT_MAX;
    }

    d[u] = 0;

    for (std::vector<std::pair<int, int>>& no : nodes)
        no.reserve(m / n * 10);

    for (size_t i = 0; i < m; i++)
    {
        int a, b, w;
        std::cin >> a; std::cin >> b; a--; b--;
        std::cin >> w;

        nodes[a].push_back(std::pair<int, int>(b, w));
    }

    queue.push({ d[u], u });

    while (queue.size())
    {
        std::pair<int, int> curr = queue.top();
        queue.pop();

        if (d[curr.second] < curr.first)
            continue;

        for (size_t i = 0; i < nodes[curr.second].size(); i++)
        {
            int distance = d[curr.second] + nodes[curr.second][i].second;

            if (distance < d[nodes[curr.second][i].first])
            {
                d[nodes[curr.second][i].first] = distance;
                p[nodes[curr.second][i].first] = curr.second;
                queue.push({ -distance, nodes[curr.second][i].first });
            }

        }
    }

    if (d[v] == INT_MAX)
    {
        std::cout << -1;
        return 0;
    }

    std::cout << d[v];

    return 0;
}





/*


int n, m, u, v;
int temp1,temp2,temp3;




int main()
{
	std::cin >> n >> m >> u >> v;


	std::vector<std::vector<int>> paths;
	std::vector<int> d;
	std::vector<int> p;
	d.resize(100000);
	p.resize(100000);
	paths.resize(100000);
	for (int i = 0; i < m; i++)
	{
		std::cin >> temp1 >> temp2 >> temp3;
		paths[temp1].push_back(temp2);
		paths[temp1].push_back(temp3);
		for (int j = 0; j < paths[temp1].size; j++)
		{
			std::cout << paths[temp1][j];
		}
		std::cout << "\n";

	}
	



	std::priority_queue<std::pair<int, int>> queue;






}*/