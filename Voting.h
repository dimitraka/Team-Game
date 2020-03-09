/*  Aikaterini Vouzoulidou AEM:8787 avouzoul@ece.auth.gr
    Dimitra Karatza AEM:8828 kadimitra@ece.auth.gr  */

#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED

#include <vector>
#include <map>
#include "Vote.h"
#include "Team.h"

using namespace std;

class Voting{

    static vector <Vote> votes;
    static map <string, int> results;

public:

    static void votingProcess(Team &team);

    //static void initializeVector(vector<Vote> &votes, int size);
    //static void initializeMap();

    static int choosePlayer(Team &team);
    static void depositVotes(Team &team);
    static void countVotes();
    static void withdrawal(Team &team);

};

#endif // VOTING_H_INCLUDED
