#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
    int n, m, p, largestIday = 0, largestI = 0;

    std::vector<std::vector<int>> connections;
    std::vector<int> d;
    std::queue<size_t> queue;

    std::cin >> n;
    std::cin >> m;
    std::cin >> p;
    p--;

    connections.resize(n);
    d.resize(n);
    for (size_t i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a;
        std::cin >> b;

        connections[a - 1].push_back(b - 1);
        connections[b - 1].push_back(a - 1);
    }

    // Init distance map
    for (int& di : d)
        di = -1;

    d[p] = 0;
    queue.push(p);

    int day = 1;
    int currInfectedToday = 0;
    int currDist = 1;
    while (queue.size())
    {
        size_t curr = queue.front();

        for (size_t i = 0; i < connections[curr].size(); i++)
        {
            if (d[connections[curr][i]] == -1)
            {
                queue.push(connections[curr][i]);
                d[connections[curr][i]] = d[curr] + 1;

                if (d[connections[curr][i]] != currDist)
                {
                    currDist = d[connections[curr][i]];
                    currInfectedToday = 0;
                    day++;
                }

                currInfectedToday++;
            }
        }

        if (currInfectedToday > largestI)
        {
            largestIday = day;
            largestI = currInfectedToday;
        }

        queue.pop();
    }

    std::cout << largestI << ' ' << largestIday;

}