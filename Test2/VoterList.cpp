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
}

void VoterList::AddNewRecord()
{
	bool Running = true;
	bool Running2 = true;
	string voterID, votes;
	string C1, C2, C3, C4;

	int size = vectorlist.size();
	while (Running) {
		for (int i = 0; i < 1; i++)
		{
			cout << "\nEnter the New Voter ID:   ";
			cin >> voterID;
			
				for (unsigned int j = 0; j < size; j++) {

					if (voterID == vectorlist[j].AccessVoterID())
					{
						cout << "Sorry, that vote already exists!" << endl;
						return AddNewRecord();
					}
				}
			
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
			Running = false;

		}
		else if (choice == 'N')
		{
			Running = false;
		}
		else
		{
			cout << "Sorry, could you choose 'Y'(yes) or 'N'(no)\n";
			cout << "Program will now close!!!!!!!\n\n\n\n";
			return exit(1);

		}
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
				
				vectorlist[i].MutateVotes(votes);
				
				cout << endl;
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
			
		}
		else if (choice == 'N')
		{

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
		cout << endl;
		cout << "That ID does not exist!" << endl << endl;
		SetVote();
	}
}

