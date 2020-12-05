#include <iostream>
#include <algorithm>
using namespace std;

int Result(int monster, int *coins)
{
	//logic for what to do if no monsters are found
	if(monster < 0)
	{
		return 0;
	}

	int maximum = max(coins[monster] + Result(monster - 2, coins), Result(monster - 1, coins));

	return maximum;

}

int main()
{
	//delaration for coin array
	int monsterCoins[1];

	//declaration and logic for running tests
	int test;
	cout << "how many tests would you like to run?";
	cin >> test;
	while(test--)
	{
		//declaration and logic for number of monsters
		int monsters = 0;
		cout << "how many monsters are on the way to the castle?";
		cin >> monsters;

		//logic for assigning coins to monsters
		for(int i = 0; i < monsters; i++)
		{
			cout << "how many coins does this monster have?";
			cin >> monsterCoins[i];
		}

		int maxCoins = Result(monsters - 1, monsterCoins);

		cout << "Case " << test << ": " << maxCoins << "\n";
	}
	
}