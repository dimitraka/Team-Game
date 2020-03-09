/*  Aikaterini Vouzoulidou AEM:8787 avouzoul@ece.auth.gr
    Dimitra Karatza AEM:8828 kadimitra@ece.auth.gr  */

#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED

#include <iostream>

using namespace std;

class Vote{

    string voted;
    string reason;

public:

    Vote(){voted = ""; reason = "";}
    Vote(string v, string  r){voted = v; reason = r;}

    string getVoted(){return voted;}
    string getReason(){return reason;}

    void setVoted(string val){voted = val;}
    void setReason(string val){reason = val;}

    void status(){cout << "Vote for: " << voted << endl; cout << "Reason why they were voted: " << reason << endl;}
};

#endif // VOTE_H_INCLUDED
