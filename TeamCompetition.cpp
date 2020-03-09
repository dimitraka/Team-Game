/*  Aikaterini Vouzoulidou AEM:8787 avouzoul@ece.auth.gr
    Dimitra Karatza AEM:8828 kadimitra@ece.auth.gr  */

#include "TeamCompetition.h"
#include <iostream>
#include <string>
#include "Round.h"
#include "FoodAward.h"

/////hdhee
using namespace std;

//constructor without arguments
TeamCompetition::TeamCompetition(){

    cout << "Constructor for TeamCompetition initialized." << endl;

}

//constructor with arguments
TeamCompetition::TeamCompetition(int i, string n, FoodAward f){

    cout << "Constructor with parameters for TeamCompetition initialized." << endl;

    foodAward = f;

}

//destructor
TeamCompetition::~TeamCompetition(){

    cout << "TeamCompetition with name" << name << "is destroyed." << endl;

}

//function that prints the status of the variables
void TeamCompetition::status(){

    cout << "TeamCompetition object:" << endl;
    Competition:: status();
    cout << "Food Award:" << endl;
    foodAward.status();
    cout << "Round:" << endl;
    for(int i=0;i<3;i++){
        rounds[i].status();
    }
    cout << endl << endl;
}

//this function implements what happens when the 2 teams compete at the Team Competition
int TeamCompetition::compete(Team &team1, Team &team2){

    int wins1=0, wins2=0, round=1;

    //3 rounds
    while(round < 4){


        Player players1[5]; //create an array of 5 players(objects) for the 1st team
        Player players2[5]; //create an array of 5 players(objects) for the 2nd team
        int selected[11]; //to find out if a player is selected
        for (int i=0;i<5;i++){
            selected[i] = 0;
        }

        for (int i=0;i<5;i++){
            //random players
            int pos = -1; //the position of each player
            do{
                pos = rand() % 10; //chooses a random number from 0 to 10 and then find which player has this position
            }while(selected[pos]==1); //1(true) for chosen, 0(false) for not chosen

            selected[pos] = 1; //the player in the position "pos" is chosen(has the value 1)
            players1[i] = team1.getPlayers()[pos]; //the position i of the players1 has the player from the 1st team that was just chosen
            players2[i] = team2.getPlayers()[pos]; //the position i of the players2 has the player from the 2nd team that was just chosen

        }


        for (int i=0;i<5;i++){
            players1[i].compete();
            players2[i].compete();
        }

        float midTechnique1=0, midTechnique2=0;

        //change the technique of the players that took part at the competition
        for (int i=0;i<5;i++){

            midTechnique1 += players1[i].getTechnique();
            midTechnique2 += players2[i].getTechnique();

        }

        //find the winner and create a new round
        if (midTechnique1 > midTechnique2){
            //create round with winner 1
            Round newRound(round, 3*3.600, team1.getColor());
            rounds[round] = newRound;
            wins1++;

        }else if(midTechnique1 < midTechnique2){
            //create round with winner 2
            Round newRound(round, 3*3.600, team2.getColor());
            rounds[round] = newRound;
            wins2++;

        }else{

            float midFatigue1=0, midFatigue2=0;

            for (int i=0;i<5;i++){

                midFatigue1 += players1[i].getFatigue();
                midFatigue2 += players2[i].getFatigue();

            }

            if(midFatigue1 < midFatigue2){
                //create round with winner 1
                Round newRound(round, 3*3.600, team1.getColor());
                rounds[round] = newRound;
                wins1++;
            }else{
                //create round with winner 1
                Round newRound(round, 3*3.600, team2.getColor());
                rounds[round] = newRound;
                wins2++;
            }

        }

        round++;

    }

    //print results
    cout << "Results from rounds:" << endl;
    status();

    //change the wins and the supplies of the team that won at the competition
    if (wins1 >= wins2){
        int w = team1.getWins();
        team1.setWins(w++);
        int s = team1.getSupplies();
        team1.setSupplies(s++);
        return 1;
    }else{
        int w = team2.getWins();
        team2.setWins(w++);
        int s = team1.getSupplies();
        team2.setSupplies(s++);
        return 0;
    }

}

