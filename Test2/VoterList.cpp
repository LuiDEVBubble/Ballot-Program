#include "VoterList.h"

using namespace std;

VoterList::VoterList()
{
	
	string voterID, votes, filename;

	cout << "HI!!!! Can you please input the files name?: " << endl;
	cout << "Remember to type .txt at the end of your file" << endl << endl;
	cin >> filename;

	int count = 0;
	ifstream inFile;

	inFile.open(filename);

	//check for errors
	if (inFile.fail())
	{
		cerr << "There was something wrong!";
		exit(1);
	}
	

	
	while (inFile >> voterID >> votes)
	{

		VoterRecord line(voterID, votes);
		vectorlist.push_back(line);
	}

	
	

}

void VoterList::printVector()
{
	int size = vectorlist.size();
	for (unsigned int i = 0; i < size; i++)
	{
		cout << "Voter ID:  " << vectorlist[i].AccessVoterID() << endl;
		cout << "Voter Votes:  " << vectorlist[i].AccessVotes() << endl;

		cout << endl;

	}
	char choice2;
	string choice;
	cout << "Would you like to return to the Main Menu?:   (Y/N)\n";
	cin >> choice2;
	if (choice2 == 'Y')
	{
		MainMenu();
	}
	else if (choice2 == 'N')
	{
		cout << "Program will now close!!!!!!! " << endl;
		return exit(1);
	}
	else
	{
		cout << "Sorry, could you choose 'Y'(yes) or 'N'(no)\n";
		cout << "Program will now close!!!!!!!\n\n\n\n";
		return exit(1);

	}
}

void VoterList::AddNewRecord()
{
	string voterID, votes;
	string C1, C2, C3, C4;



	for (int i = 0; i < 1; i++)
	{
		cout << "\nEnter the New Voter ID:   ";
		cin >> voterID;
		cout << "Enter the New votes:  ";
		cout << "\n1. VOTE FOR MAYOR\n		" << endl;
		cout << "		A. Pincher, Penny" << endl;
		cout << "		B. Dover, Skip" << endl;
		cout << "		C. Perman, Sue" << endl;
		cin >> C1;
		cout << "\n2. PROPOSITION 17" << endl;
		cout << "		D. Yes" << endl;
		cout << "		E. No" << endl;
		cin >> C2;
		cout << "\n3. MEASURE 1" << endl;
		cout << "		F. Yes" << endl;
		cout << "		G. No" << endl;
		cin >> C3;
		cout << "\n4. MEASURE 2" << endl;
		cout << "		H. Yes" << endl;
		cout << "		I. No" << endl;
		cin >> C4;


		votes = C1 + C2 + C3 + C4;

		VoterRecord line(voterID, votes);
		vectorlist.push_back(line);
		cout << endl;
	}

	cout << endl;
	char choice;
	char choice2;

	cout << "Would you like your receipt?:   (Y/N)\n";

	cin >> choice;
	if (choice == 'Y')
	{
		cout << "****************************************************************" << endl;
		cout << "\nYour Voter ID is:   " << voterID << " And your Votes were:   " << votes;
		cout << "\n****************************************************************" << endl;
		cout << endl;
		MainMenu();

	}
	else if (choice == 'N')
	{
		cout << "Would you like to return to the main menu?:   (Y/N)\n";
		cin >> choice2;
		if (choice2 == 'Y')
		{
			MainMenu();
		}
		else if (choice2 == 'N')
		{
			cout << "Program will now close!!!!!!! " << endl;
			return exit(1);
		}

	}
	else
	{
		cout << "Sorry, could you choose 'Y'(yes) or 'N'(no)\n";
		cout << "Program will now close!!!!!!!\n\n\n\n";
		return exit(1);

	}

	


}

void VoterList::Query() 
{

	
	string oldID;
	string choice;
	cout << "What is your ID number?:   " << endl;
	cin >> oldID;
	int size = vectorlist.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (oldID == vectorlist[i].AccessVoterID())
		{
			cout << "You voter ID is:  " << oldID;
			cout << " And Your Votes were:  " << vectorlist[i].AccessVotes();
			cout << endl;
		
		}


	}
	cout << "would you like to return to main menu or exist? (Y/N)";
	cin >> choice;
	if (choice == "Y")
	{
		MainMenu();
	}
	else
	{
		cout << "Fine! I'll just kick you out the program!!";
		return exit(1);
	}
	

}

void VoterList::SetVote()
{
	bool Answer = false;
	string oldID, votes;
	string C1, C2, C3, C4;
	cout << "What is your ID number?:   " << endl;
	cin >> oldID;
	int size = vectorlist.size();
	for (unsigned int i = 0; i < size; i++)
	{

	
		if (oldID == vectorlist[i].AccessVoterID())
		{
			Answer = true;
			for (int i = 0; i < 1; i++)
			{
				cout << "Enter the New votes:  ";
				cout << "\n1. VOTE FOR MAYOR\n		" << endl;
				cout << "		A. Pincher, Penny" << endl;
				cout << "		B. Dover, Skip" << endl;
				cout << "		C. Perman, Sue" << endl;
				cin >> C1;
				cout << "\n2. PROPOSITION 17" << endl;
				cout << "		D. Yes" << endl;
				cout << "		E. No" << endl;
				cin >> C2;
				cout << "\n3. MEASURE 1" << endl;
				cout << "		F. Yes" << endl;
				cout << "		G. No" << endl;
				cin >> C3;
				cout << "\n4. MEASURE 2" << endl;
				cout << "		H. Yes" << endl;
				cout << "		I. No" << endl;
				cin >> C4;

				

				votes = C1 + C2 + C3 + C4;

				
				vectorlist[i].AccessVotes().assign(votes);
				
					
				VoterRecord line(oldID, votes);
				//vectorlist.assign(line).AccessVotes();
				cout << endl;

			}
		}
		
	}
	if (Answer == true)
	{
		cout << endl;
		char choice;
		char choice2;

		cout << "Would you like your receipt?:   (Y/N)\n";

		cin >> choice;
		if (choice == 'Y')
		{
			cout << "****************************************************************" << endl;
			cout << "\nYour Voter ID is:   " << oldID << " And your New Votes are:   " << votes;
			cout << "\n****************************************************************" << endl;
			cout << endl;
			MainMenu();
		}
		else if (choice == 'N')
		{
			cout << "Would you like to return to the main menu?:   (Y/N)\n";
			cin >> choice2;
			if (choice2 == 'Y')
			{
				MainMenu();
			}
			else if (choice2 == 'N')
			{
				cout << "Program will now close!!!!!!! " << endl;
				return exit(1);
			}

		}
		else
		{
			cout << "Sorry, could you choose 'Y'(yes) or 'N'(no)\n";
			cout << "Program will now close!!!!!!!\n\n\n\n";
			return exit(1);

		}
	}
	else
	{
		SetVote();
	}




}

void VoterList::MainMenu()
{
string FirstName;
int NumChoice;

cout << "What's your First name?     ";
cin >> FirstName;
cout << "	\nHey " << FirstName << " What can the Vote Record program do for you today?" << endl;
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
	Query();

}
else if (NumChoice == 2)
{
	AddNewRecord();
}
else if (NumChoice == 3)
{
	SetVote();
}
else if (NumChoice == 4)
{
	exit(1);//Statistics(vectorlist);
}
else if (NumChoice == 5)
{
	printVector();

}
else if (NumChoice == 6)
{
	exit(1);
}
else
{
	cout << "Sorry, what you typed was invalid, please try again" << endl << endl;

}
}
//void VoterList::Statistics()
//{
//	
//	if (vectorlist[0] == 'A')
//	
//}
