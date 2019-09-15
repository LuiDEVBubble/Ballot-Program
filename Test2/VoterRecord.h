
#ifndef VOTERRECORD_H
#define VOTERRECORD_H
#include <iostream>
#include <string>
using namespace std;

class VoterRecord
{
protected:
	string voterID, votes;

public:


	// Constructor 
	VoterRecord();

	// Overload Constructor 
	VoterRecord(string, string);

	//Destructor
	~VoterRecord();

	// First Accessor - returns ID
	string AccessVoterID() const;

	// Second Accessor - gets Votes
	string AccessVotes() const;

	// Mutator that changes ID
	void MutateVoterID(string);

	// Mutator that changes Votes
	void MutateVotes(string);



};


#endif