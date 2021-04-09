#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <algorithm>
#include <vector>


int n, m, counter;
std::string kodeord, tekst, duplicate;
std::vector<char> abc;
std::vector<char> newabc;
std::vector<char> reduced;
std::vector<char> FirstRow;
std::vector<char> SecondRow;
bool omegatemp;

bool searchDupe(int a);

int main()
{
	abc.vector::push_back('A');
	abc.vector::push_back('B');
	abc.vector::push_back('C');
	abc.vector::push_back('D');
	abc.vector::push_back('E');
	abc.vector::push_back('F');
	abc.vector::push_back('G');
	abc.vector::push_back('H');
	abc.vector::push_back('I');
	abc.vector::push_back('J');
	abc.vector::push_back('K');
	abc.vector::push_back('L');
	abc.vector::push_back('M');
	abc.vector::push_back('N');
	abc.vector::push_back('O');
	abc.vector::push_back('P');
	abc.vector::push_back('Q');
	abc.vector::push_back('R');
	abc.vector::push_back('S');
	abc.vector::push_back('T');
	abc.vector::push_back('U');
	abc.vector::push_back('V');
	abc.vector::push_back('W');
	abc.vector::push_back('X');
	abc.vector::push_back('Y');
	abc.vector::push_back('Z');


	std::cin >> n;
	std::cin >> m;
	if (n == 0)
	{
		n=std::cin.get();
		std::cin.ignore();
		std::getline(std::cin, tekst);

		for (int i = 0; i < 13; i++)
		{
			FirstRow.push_back(abc[i]);
		}
		for (int i = 13; i < 26; i++)
		{
			SecondRow.push_back(abc[i]);
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				if (tekst[i] == FirstRow[j])
				{
					tekst[i] = SecondRow[j];
				}
				else if (tekst[i] == SecondRow[j])
				{
					tekst[i] = FirstRow[j];
				}
				else if (tekst[i] - 32 == FirstRow[j])
				{
					tekst[i] = SecondRow[j] + 32;
				}
				else if (tekst[i] - 32 == SecondRow[j])
				{
					tekst[i] = FirstRow[j] + 32;
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
		std::cout << tekst[i];
		}
		return 0;
	}

	std::cin >> kodeord;



	std::cin.ignore();
	std::getline(std::cin, tekst);
	for (int i = 0; i < n; i++)
	{
		if (searchDupe(i)==true)
		{
			reduced.vector::push_back(kodeord[i]);
			//reduced[counter] = kodeord[i];
			counter++;
		}
	}


	if (counter > 13)
	{
		for (int i = 0; i < 13; i++)
		{
			FirstRow.push_back(reduced[i]);
		}

		for (int i = 0; i < counter - 13; i++)
		{
			SecondRow.push_back(reduced[13+i]);
		}

		//erase from abc vector
		for (int i = 0; i < abc.vector::size(); i++)
		{
			for (int j = 0; j < counter; j++)
			{
				if (abc[i] == reduced[j])
				{
					abc.vector::erase(abc.vector::begin() + i);
					i--;
					break;
				}

			}

		}
		//end of erase from abc vector

		//fill in rest of alphabet
		for (int i = 0; i < 26 - counter; i++)
		{
			SecondRow.push_back(abc[i]);
		}
		//end of fill in rest of alphabet

	}
	else 
	{
		for (int i = 0; i < counter; i++)
		{
			FirstRow.push_back(reduced[i]);
		}

		//erase from abc vector
		for (int i = 0; i < abc.vector::size(); i++)
		{
			for (int j = 0; j < counter; j++)
			{
				if (abc[i] == reduced[j])
				{
					abc.vector::erase(abc.vector::begin() + i);
					i--;
				}

			}

		}
		//end of erase from abc vector


		//fill in rest of alphabet
		for (int i = 0; i < 13 - counter; i++)
		{
			FirstRow.push_back(abc[i]);
		}
		for (int i = 0; i < 13; i++)
		{
			SecondRow.push_back(abc[i + 13 - counter]);
		}
		//end of fill in rest of alphabet
	}



	//actually do the swapping
	for (int i = 0; i < tekst.length(); i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (tekst[i] == FirstRow[j])
			{
				tekst[i] = SecondRow[j];
			}
			else if (tekst[i] == SecondRow[j])
			{
				tekst[i] = FirstRow[j];
			}
			else if (tekst[i] - 32 == FirstRow[j])
			{
				tekst[i] = SecondRow[j] + 32;
			}
			else if (tekst[i] - 32 == SecondRow[j])
			{
				tekst[i] = FirstRow[j] + 32;
			}
		}

	}
	//end of actually do the swapping

	//output
	for (int i = 0; i < tekst.length(); i++)
	{
		std::cout << tekst[i];
	}


	/*
	for (int i = 0; i < counter; i++)
	{
		std::cout << reduced[i];
	}
	std::cout << "\n" << tekst;
	*/

}






bool searchDupe(int a)
{
	for (int i = 0; i < counter; i++)
	{
		if (kodeord[a] == reduced[i])
		{
			return false;
		}
	}
	return true;
}
