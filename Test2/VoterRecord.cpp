#include "VoterRecord.h"


VoterRecord::VoterRecord()
{}
VoterRecord::VoterRecord(string VoterID, string Votes)
{
	voterID = VoterID;
	votes = Votes;
}

VoterRecord::~VoterRecord()
{}

string VoterRecord::AccessVoterID() const
{
	return voterID;
}

string VoterRecord::AccessVotes() const
{
	return votes;
}

void VoterRecord::MutateVoterID(string VoterID)
{
	voterID = VoterID;
}

void VoterRecord::MutateVotes(string Votes)
{
	votes = Votes;
}

