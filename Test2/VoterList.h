#ifndef VOTERLIST_H
#define VOTERLIST_H
#include <iostream>
#include <string>
#include "VoterRecord.h"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>


class VoterList : public VoterRecord
{
private:
		
	vector<VoterRecord> vectorlist;



public:
	//change votes
	void SetVote(); 

	//add new record
	void AddNewRecord();

	//look up voter info
	void Query();


	//void Statistics();

	void printVector();


	VoterList(); // Constructor

	void MainMenu();



	//vector<VoterRecord> vectorlist;


};


#endif