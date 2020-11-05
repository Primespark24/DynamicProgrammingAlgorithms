#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//declaration of monst array and max coins allowed
	int monst[1];
	int maxCoins = 0;
	
	//logic to run number of tests user would like
	int test = 0;
	cout << "how many tests would you like to run?";
	cin >> test;

	while(test--)
	{
		//logic for number of monsters
		int monsters = 0;
		cout << "how many monsters are on the way to the castle?";
		cin >> monsters;

		//logic for assiging coins to monsters
		for(int i = 0; i < monsters; i++)
		{
			cout << "how many coins does this monster have?";
			cin >> monst[i];
		}

		//check to see if monster at position zero or one has more coins to decide where to start
		monst[1] = max(monst[0], monst[1]);
		//loop through every other monster to get their coins
		for (int i = 2; i < monsters; i++) 
		{
			int sum1 = monst[i - 2] + monst[i];
			int sum2 = monst[i - 1];
			monst[i] = max(sum1, sum2);
		}

		maxCoins = monst[monsters - 1];

		cout << "Case " << test << ": " << maxCoins;
	}
}