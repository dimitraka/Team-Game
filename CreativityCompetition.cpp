/*  Aikaterini Vouzoulidou AEM:8787 avouzoul@ece.auth.gr
    Dimitra Karatza AEM:8828 kadimitra@ece.auth.gr  */

#include <iostream>
#include <string>
#include "CreativityCompetition.h"
#include "ExcursionAward.h"

using namespace std;

string CreativityCompetition::ingredients[10] = {"butter", "sugar", "sweet potato", "chicken", "salt", "pepper", "lemon", "oregano", "asparagus", "mustard"};


//constructor without arguments
CreativityCompetition::CreativityCompetition(){

    cout << "Constructor for CreativityCompetition initialized." << endl;

    //ingredients[10]= {""};

}

//constructor with arguments
CreativityCompetition::CreativityCompetition(int i, string n, ExcursionAward exAward){

    cout << "Constructor with parameters for CreativityCompetition initialized." << endl;

    excursionAward = exAward;
    //ingredients[10] = {"butter", "sugar", "sweet potato", "chicken", "salt", "pepper", "lemon", "oregano", "asparagus", "mustard"};


}

//destructor
CreativityCompetition::~CreativityCompetition(){

    cout << "CreativityCompetition with name" << name << "is destroyed." << endl;

}

//function that prints the status of the variables
void CreativityCompetition::status(){

    cout << "CreativityCompetition object: " << endl;
    Competition:: status();
    cout << "Excursion Award:" << endl;
    excursionAward.status();
    cout << "Ingredients: " << endl;
    for (int i = 0; i < 10; i++){
        cout << ingredients[i];
    }

}

//this function implements what happens when the 2 teams compete at the Creativity Competition
void CreativityCompetition::compete(Team &team1, Team &team2){

    int k = team1.getNumberOfPlayers(); //k has the number of players of the 1st team
    int l = team2.getNumberOfPlayers(); //l has the number of players of the 2nd team
    int m = k+l; //all the players

    Player allPlayers[m]; //allPlayers is an array which includes all the players as objects

    for(int i=0;i<k;i++){
        allPlayers[i]=team1.getPlayers()[i];
    }

    int n = 0; //the position of each player
    for(int i=k+1;i<m;i++){
        allPlayers[i]=team2.getPlayers()[n];
        n++;
    }

    //finding the winner
    int maxTechnique = -1;
    int maxIndex = -1;
    int playerIndex = 0;

    while(playerIndex < m ){

        float technique = allPlayers[playerIndex].getTechnique();

        if(technique > maxTechnique){

            maxTechnique = technique;
            maxIndex = playerIndex;

        }
        playerIndex++;

    }

    //print the winner
    cout << "\nWinner for the Creativity Competition:" << endl;
    allPlayers[maxIndex].status();

    ExcursionAward exAward; //the winner wins the award which is an object of the class Excursion Award

    //change the technique of the winner
    float t = allPlayers[maxIndex].getTechnique();
    t += exAward.getTechniqueBonus();

    //change the popularity of the winner
    float p = allPlayers[maxIndex].getPopularity();
    p -= exAward.getPopularityPenalty();
}

