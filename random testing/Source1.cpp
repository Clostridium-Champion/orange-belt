#include <iostream>




int main()
{
	int N, M;

	std::cin >> N;

	M = N % 24;

	if (M > 20)
		std::cout << 9 + (N - M) / 2;
	else if (M > 16)
		std::cout << 8 + (N - M) / 2;
	else if (M > 13)
		std::cout << 6 + (N - M) / 2;
	else if (M > 9)
		std::cout << 4 + (N - M) / 2;
	else if (M > 6)
		std::cout << 3 + (N - M) / 2;
	else
		std::cout << (N - M) / 2;


	return 0;
}