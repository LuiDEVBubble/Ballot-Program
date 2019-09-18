#include <iostream>
#include <vector>
#include "VoterRecord.h"
#include "VoterList.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;


int main()
{
		VoterList ListObj;

		bool Running = true;

		string FirstName, choice;
		cout << "What's your First name?     ";
		cin >> FirstName;
		cout << "	\nHey " << FirstName << " What can the Vote Record program do for you today?" << endl;

		while (Running) {

			int NumChoice;

			cout << "	Please choose one of the following options:\n\n\n";
			cout << "	1) Query a voter's record given the voter's ID.\n";
			cout << "	2) Add a new voter's record and print the receipt.\n";
			cout << "	3) Modify a voter's record given the voter's ID and print the modified receipt.\n";
			cout << "	4) Print the voting statistics to the screen, that is, the percent of votes\n" << "	   cast for each candidate, proposition, and measure.\n";
			cout << "	5) Print the sorted list of voter records.\n";
			cout << "	6) Exit the program.\n\n\n";
			cin >> NumChoice;
			if (NumChoice == 1)
			{
				ListObj.Query();

			}
			else if (NumChoice == 2)
			{
				ListObj.AddNewRecord();
			}
			else if (NumChoice == 3)
			{
				ListObj.SetVote();
			}
			else if (NumChoice == 4)
			{
				exit(1);//Statistics(vectorlist);
			}
			else if (NumChoice == 5)
			{
				ListObj.printVector();

			}
			else if (NumChoice == 6)
			{
				 exit(1);
			}
			else
			{
				cout << "Sorry, what you typed was invalid, please try again" << endl << endl;

			}

			cout << endl << endl;
			cout << "Do you want to go back to the Main Menu or exit the program?" << endl;
			cout << "Type Yes or No" << endl << endl;
			cin >> choice;
			if (choice == "No" || choice == "N")
			{
				Running = false;
			}
			else {}


		}
		
	system("pause");
	

}






