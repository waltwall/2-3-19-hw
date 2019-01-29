#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "Begin Search for target" << endl;

	// Declares that 64 is the highest number in the grid.
	int searchPersonGridHighNumber = 64;
	int searchLineGridHighNumber = 64;
	// Declares that 1 is the lowest number in the grid.
	int searchPersonGridLowNumber = 1;
	int searchLineGridLowNumber = 1;
	// Randomize the enemy location.
	int targetLoc = rand() % 64 + 1;
	int targetLineLocationPrediction = 1;
	// This block of code displays the initializtion of the program.
	cout << "Skynet HK-Aerial Starting Search..." << endl;
	int targetPersonLocationPredictionCounter = 0;
	int targetLineLocationPredictionCounter = 0;
	bool targetFoundPerson = false;
	bool targetFoundLine = false;

	// A while statement running until the target is found.
	while (targetFoundPerson == false)
	{
		// code used to find the target through binary search.
		int targetPersonLocationPrediction = 0;
		cout << "Please enter a guess for the target location on a grid value between " << searchPersonGridLowNumber << " & " << searchPersonGridHighNumber << "." << endl;
		cout << ">";
		cin >> targetPersonLocationPrediction;
		targetPersonLocationPredictionCounter++;
		// Dividing line to make screen easy to read
		cout << "=======================================================================================" << endl;
		// Stating that a ping is being sent out.
		cout << "Skynet HK-Aerial Radar sending out ping #" << targetPersonLocationPredictionCounter << endl;

		// An if statement for when the location predicted is greater than the target location.
		if (targetPersonLocationPrediction > targetLoc)
		{
			// Replaces the previous searchGridHighNumber with a new searchGridHighNumber.
			searchPersonGridHighNumber = targetPersonLocationPrediction - 1;
			// Displays the location predicted being higher than the target location.
			cout << "The target location prediction of " << targetPersonLocationPrediction << " was higher than the actual enemy location." << endl;
			// Displays the new searchGridHighNumber.
		}
		// An else if statement for when the target location is higher than the location predicted.
		else if (targetPersonLocationPrediction < targetLoc)
		{
			// Replaces the previous searchGridLowNumber with a new searchGridLowNumber.
			searchPersonGridLowNumber = targetPersonLocationPrediction + 1;
			// States the location of the enemy.
			cout << "Enemy is still in hiding..." << endl;
			// Displays the location predicted being lower than the target location.
			cout << "The target location prediction of " << targetPersonLocationPrediction << " was lower than the actual target location." << endl;
			// Displays the new searchGridLowNumber.
		}
		// Statement for when the target is found.
		else if (targetPersonLocationPrediction == targetLoc)
		{
			// States the location of the enemy.
			cout << "Enemy was hiding at grid " << targetLoc << endl;
			// Informs the user how many pings it took to locate the target.
			cout << "Skynet HK-Aerial Software took " << targetPersonLocationPredictionCounter << " pings to find the target." << endl;
			targetFoundPerson = true;
		}
		else
		{
			// Code that displays when something unexpected happens.
			cout << "Whoops!" << endl;
			cout << "You shouldn't be here!" << endl;
			targetFoundPerson = true;
		}
	}
	while (targetFoundLine == false)
	{
		// code used to find the target through binary search.
		targetLineLocationPredictionCounter++;
		// Dividing line to make screen easy to read
		cout << "=======================================================================================" << endl;
		// Stating that a ping is being sent out.
		cout << "Skynet HK-Aerial Radar sending out ping #" << targetLineLocationPredictionCounter << endl;
		// An else if statement for when the target location is higher than the location predicted.
		if (targetLineLocationPrediction < targetLoc)
		{
			// States the location of the enemy.
			cout << "Enemy is still in hiding..." << endl;
			// Displays the location predicted being lower than the target location.
			cout << "The target location prediction of " << targetLineLocationPrediction << " was lower than the actual target location." << endl;
			// Displays the new searchGridLowNumber.
			targetLineLocationPrediction = targetLineLocationPrediction + 1;
		}
		// Statement for when the target is found.
		else if (targetLineLocationPrediction == targetLoc)
		{
			// States the location of the enemy.
			cout << "Enemy was hiding at grid " << targetLoc << endl;
			// Informs the user how many pings it took to locate the target.
			cout << "Skynet HK-Aerial Software took " << targetLineLocationPredictionCounter << " pings to find the target." << endl;
			targetFoundLine = true;
		}
		else
		{
			// Code that displays when something unexpected happens.
			cout << "Whoops!" << endl;
			cout << "You shouldn't be here!" << endl;
			targetFoundLine = true;
		}
	}
	cout << "The enemy was located at location at grid number " << targetLoc << endl;
	system("pause");
}