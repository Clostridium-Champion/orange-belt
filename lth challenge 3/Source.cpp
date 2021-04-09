#include <iostream>
#include <unordered_map>
#include <string>


int main()
{
    bool b = false;
    std::unordered_map<std::string, char> status;
    std::unordered_map<std::string, std::string> looking;
    int N, L;

    std::cin >> N;
    std::cin >> L;

    status.reserve(N);
    looking.reserve(L);

    for (size_t i = 0; i < N; i++)
    {
        std::string name; char s;
        std::cin >> name;
        std::cin >> s;

        status.insert({ name, s });
    }

    for (size_t i = 0; i < L; i++)
    {
        std::string name1, name2, trash;
        std::cin >> name1;
        std::cin >> trash;
        std::cin >> name2;

        looking.insert({ name1,name2 });
    }

    for (auto n : status)
    {
        if (n.second != 'm')
            continue;

        auto start = n.first;
        auto name = n.first;

        while (true)
        {
            if (looking.find(name) != looking.end())
            {
                name = looking[name];

                if (status[name] == 'u')
                {
                    std::cout << 1;
                    return 0;
                }
                if (status[name] == '?')
                {
                    b = true;
                }
                if (name == start)
                    break;


            }
            else
                break;
        }
    }

    if (b)
    {
        std::cout << '?';
        return 0;
    }

    for (auto n : status)
    {
        if (n.second != '?')
            continue;

        if (status[looking[n.first]] != 'm')
        {
            std::cout << '?';
            return 0;
        }
    }

    std::cout << 0;

    return 0;
}