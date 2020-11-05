#include <iostream>
using namespace std;

//fun array of 100 parties (0-100)
int fun[101];
//fee array of 100 parties (0-100)
int fee[101];

//2-D array that holds all parties and all bugets at that time (0-100 parties), (0-500 francs)
int allParties[101][501];

int bestCourse(int party, int francsLeft)
{
	//base case for exact use of money
	if(francsLeft == 0)
	{
		return 0;
	//checks to see if too much money has been used
	}else if(francsLeft < 0){
		return 0;
	}

	//checks parties to see if there are more than 0 left
	if(party < 0)
	{
		return 0;
	} 

	//makes sure 2-D array is valid
	if(allParties[party][francsLeft] != -1) {
		return allParties[party][francsLeft];
	}

	//2 temp variables to check one party against the next
	int party1 = 0;
	int party2 = 0;

	//checks party 1 and finds its value only if money is left for it
	if(francsLeft - fee[party] >= 0)
	{
		party1 = fun[party] + bestCourse(party - 1, francsLeft - fee[party]);
	}

	//checks party 2 and its value
	party2 = bestCourse(party - 1, francsLeft);

	//check to see which party is better
	int best = 0;
	if(party1 < party2)
	{
		best = party2;
	}else if(party2 < party1)
	{
		best = party1;
	}

	return allParties[party][francsLeft] = best;

}

int main()
{
	int budget;
	int parties;
	//user inputs for total cash and amount of parties
	cout << "Total Budget";
	cin >> budget;
	cout << "Number of Parties";
	cin >> parties;

	while(budget != 0 || parties != 0)
	{	
		//search whole 2-D array
		for(int i = 0; i < 101; i++)
		{
			for (int j = 0; j < 501; j++) 
			{
				allParties[i][j] = -1;
			}
		}

		//user set for all fun and fees
		for(int i = 0; i < parties; i++)
		{
			cin >> fun[i];
			cin >> fee[i];
		}

		for(int i = 0; i < 501; i++)
		{
			bestCourse(parties - 1, i);
		}

		int complete = bestCourse(parties - 1, budget);

		int minimum = 0;
		for(int i = 0; i < 501; i++)
		{
			if(allParties[parties - 1][i] == complete)
			{
				minimum = i;
			}
		}

		cout << minimum << " " << complete;
	}

	return 0;
}