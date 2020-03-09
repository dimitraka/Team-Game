/*  Aikaterini Vouzoulidou AEM:8787 avouzoul@ece.auth.gr
    Dimitra Karatza AEM:8828 kadimitra@ece.auth.gr  */

#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include <iostream>
#include <string>
#include "Competition.h"
#include "ExcursionAward.h"
#include "Team.h"

using namespace std;

class CreativityCompetition : public Competition{

protected:
    ExcursionAward excursionAward;
    static string ingredients[10];

public:
    CreativityCompetition();
    CreativityCompetition(int i, string n, ExcursionAward exAward);
    ~CreativityCompetition();

    void status();

    void compete(Team &team1, Team &team2);

};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
