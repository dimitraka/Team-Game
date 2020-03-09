/*  Aikaterini Vouzoulidou AEM:8787 avouzoul@ece.auth.gr
    Dimitra Karatza AEM:8828 kadimitra@ece.auth.gr  */

#include "Voting.h"
#include "Team.h"
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

//initialization
 vector <Vote> Voting::votes;
 map <string, int> Voting::results;

//this is an array with reasons why a player may be voted by other players
string randomReason[10] = {"He/she is arrogant.", "I believe he/she is untalented.", "I didn't have another choice.", "He/she has luck of technique." , "His/her dishes are not that delicious.", "Living with him/her in the same house is really difficult.", "I don't like her/him.", "He/she wasn't good this week.", "I like him/her, but he/she is the most weak player.", "He/she is always criticizing me."};

//This function chooses a player to be voted
int Voting::choosePlayer(Team &team){

    int random = rand() % 3; //random number 1 or 2 or 3

    int pos = -1;

    switch(random){
    case 0:
        {
            pos = rand() % 11;

            break;
        }

    case 1:
        {
            float minTechnique = 100;

            for(int i = 0; i < 11; i++){

                if(minTechnique <= team.getPlayers()[i].getTechnique() && team.getPlayers()[i].getName() != ""){

                    minTechnique = team.getPlayers()[i].getTechnique();
                    pos = i;
                }

            }

            break;
        }

    case 2:

        {
            int minWins = 10000000;

            for(int i = 0; i < 11; i++){


                if(minWins <= team.getPlayers()[i].getWins() && team.getPlayers()[i].getName() != ""){

                    minWins = team.getPlayers()[i].getWins();
                    pos = i;

                }


            }
            break;
        }
    }

    return pos;

}

//This function implements the process of voting in which the players are called to vote another player
void Voting::depositVotes(Team &team){

    for(int i = 0; i < 11; i++){

        while(team.getPlayers()[i].getVotes() > 0){

                //check if the voted player can be actually voted

                int voted;
                string name;
                bool im;


                do{
                    voted = Voting::choosePlayer(team);

                    //the name of the voted player
                    name = team.getPlayers()[voted].getName();


                    //the immunity of the voted player
                    im = team.getPlayers()[voted].getImmunity();


                }while(name == team.getPlayers()[i].getName() || im == true || team.getPlayers()[voted].getName()=="" );

                int posReason = rand()%10;
                string reason = randomReason[posReason];

                //create a new vote

                Vote newVote;

                newVote.setVoted(name);
                newVote.setReason(reason);

                //add the vote at the vector
                votes.push_back(newVote);

                //decrease the available voted of the player
                int leftVotes = team.getPlayers()[i].getVotes()-1;
                team.getPlayers()[i].setVotes(leftVotes);
        }

    }

    //print the votes
    for(unsigned int i = 0; i < votes.size();i++){

        cout << "\tNAME\tREASON VOTED\n";
        cout << "\t" << votes[i].getVoted() << "  " << votes[i].getReason() << endl;

    }

}


//This function implements the process of counting the votes that were deposited and printing the result
void Voting::countVotes(){

    map <string, int> :: iterator itr;

    for(unsigned int i = 0; i < votes.size();i++){

            //search for the key in results
            string n = votes[i].getVoted();

            itr = results.find(n);

            if ( itr == results.end() ) {
                // not found
                results.insert(pair <string, int> (n,1));

            }else{

                //increase the key by one
                results[n] ++;

            }


    }

    //print the results from the map

    for(itr = results.begin(); itr != results.end(); itr++){

        cout << "\tNAME\tNUMBER OF VOTES\n";

        cout << "\t" << itr->first << "\t" << itr->second << "\n";
    }

}

//This function implements the process of choosing the 2 most voted players and withdrawing the one with the least technique
void Voting::withdrawal(Team &team){

    //find the 2 most voted players
    map <string, int> :: iterator itr;

    int max1=-1;
    int max2=-1;
    string candidate1=" ";
    string candidate2=" ";

    for(itr = results.begin(); itr != results.end(); itr++){

        if(itr->second > max1){
            max1 = itr->second;
            candidate1=itr->first;
        }
    }

    for(itr = results.begin(); itr != results.end(); itr++){

        if(itr->second > max2 && itr->first!= candidate1){
            max2=itr->second;
            candidate2=itr->first;
        }
    }

    float technique1,technique2;

    for(int i = 0; i < 11; i++){

        if(candidate1 == team.getPlayers()[i].getName()){

            team.getPlayers()[i].setCandidate(true);
            technique1 = team.getPlayers()[i].getTechnique();

        }else if(candidate2 == team.getPlayers()[i].getName()){

            team.getPlayers()[i].setCandidate(true);
            technique2 = team.getPlayers()[i].getTechnique();
        }
    }

    if(technique1<technique2){

        team.removePlayer(candidate1);
        cout << "Player" << candidate1 << "left the game.";
    }else if(technique1>technique2){

        team.removePlayer(candidate2);
        cout << "Player" << candidate2 << "left the game.";
    }else{

        int random = rand() % 2;

        if (random == 1){
            team.removePlayer(candidate1);
            cout << "Player" << candidate1 << "left the game.";
        }else{
            team.removePlayer(candidate2);
            cout << "Player" << candidate2 << "left the game.";
        }
    }


}


void Voting::votingProcess(Team &team){

    if(team.getNumberOfPlayers()<=2){
        cout<< "No others players can be removed." << endl;
        return;
    }
    depositVotes(team);
    countVotes();
    withdrawal(team);

    votes.clear();
    results.clear();

}


