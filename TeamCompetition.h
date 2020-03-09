/*  Aikaterini Vouzoulidou AEM:8787 avouzoul@ece.auth.gr
    Dimitra Karatza AEM:8828 kadimitra@ece.auth.gr  */

#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

#include <iostream>
#include <string>
#include "Competition.h"
#include "FoodAward.h"
#include "Team.h"
#include "Round.h"


using namespace std;

class TeamCompetition : public Competition{

protected:
    FoodAward foodAward;
    Round rounds[3];


public:
    TeamCompetition();
    TeamCompetition(int i, string n, FoodAward f);
    ~TeamCompetition();

    void status();

    int compete(Team &team1, Team &team2);


};


#endif // TEAMCOMPETITION_H_INCLUDED
