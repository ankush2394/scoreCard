#include "team.h"
#include <vector>
#include "winnerCalculator.h"
using namespace std;
class match {
public:

    int numOvers, numOfPLayers;
    int totalRuns, totalWickets;
    vector<int> team1Ids, team2Ids;
    vector<team*> teams;   //match property is teams
    winnerCalculator w;

    match(int numOfPLayers, int numOvers, vector<int> team1Pids, vector<int> team2Pids) {
        this->numOfPLayers = numOfPLayers;
        this->numOvers = numOvers;
        team1Ids = team1Pids;
        team2Ids = team2Pids;
        totalRuns = 0;
        totalWickets = 0;

        initialiseTeams();
    };

    void initialiseTeams() {
        team *team1 = new team(team1Ids, true);
        team *team2 = new team(team2Ids, false);
        teams.push_back(team1);
        teams.push_back(team2);
    }

    int getTotalRuns() {
        return totalRuns;
    }

    int getTotalWickets() {
        return totalWickets;
    }

    void start() {
        string val;
        team *battingTeam = getBattingTeam();
        team *bowlingTeam = getBowlingTeam();
        //cout<<battingTeam->players[0];
        try {
            player *strikerEnd = battingTeam->getOnStrikePlayer();
            player *offStrikerEnd = battingTeam->getOffStrikePlayer();

            for (int i = 0; i < numOvers; i++) {
                do {
                    cin >> val;

                    executeOneBall(val, strikerEnd, battingTeam);

                    if(strikerEnd->isOutt()) {
                        cout<<"striker id who is out is "<<strikerEnd->playerId<<endl;
                        strikerEnd = battingTeam->getOnStrikePlayer();
                        cout<<"new on strike  is "<<strikerEnd->playerId<<endl;

                    }

                    if(shouldChangeStrike(val)) {
                        swap(strikerEnd, offStrikerEnd);
                    }
                } while (setNumber(val));


                swap(strikerEnd, offStrikerEnd);

                //offStrikerEnd->

                cout << "over completed" << " on strike right now "<<strikerEnd->playerId<<" "<<strikerEnd->onStrike()<<endl;
                cout << "over completed" << " off strike right now "<<offStrikerEnd->playerId<<" "<<offStrikerEnd->onStrike()<<endl;

                cout<<battingTeam->runs<<" "<<battingTeam->wickets<<endl;
                cout<<"player"<<" "<<"score"<< " "<<"4s"<<" "<<"6s"<<" "<<"Balls"<<endl;
                for(int i=0;i<battingTeam->players.size();i++) {
                    cout<<battingTeam->players[i]->playerId<<" "<<battingTeam->players[i]->runsScored<<" "<<
                        battingTeam->players[i]->num4s<<" "<< battingTeam->players[i]->num6s<<" "<<battingTeam->players[i]->ballsFaced<<" "<<
                        battingTeam->players[i]->isOutt()<<endl;
                }
            }
            cout<<"INNINGS OVER"<<endl;
            battingTeam->isBatting = false;
            bowlingTeam->isBatting = true;
        } catch (const char * msg) {
            cout<<"all wickets down"<<endl;
        }



        //*************
//        cout<<battingTeam.runs<<" "<<battingTeam.wickets<<endl;
//        cout<<"player"<<" "<<"score"<< " "<<"4s"<<" "<<"6s"<<" "<<"Balls"<<endl;
//        for(int i=0;i<battingTeam.players.size();i++) {
//            cout<<battingTeam.players[i]->playerId<<" "<<battingTeam.players[i]->runsScored<<" "<<
//            battingTeam.players[i]->num4s<<" "<< battingTeam.players[i]->num6s<<" "<<battingTeam.players[i]->ballsFaced<<" "<<
//            battingTeam.players[i]->isOutt()<<endl;
//        }
        //*************
    }

    bool setNumber(string x) {
        if(x=="over") {
            return false;
        }
        return true;
    }

    team* getBattingTeam() {
        if (teams[0]->isBatting) {
            return teams[0];
        }
        return teams[1];
    }

    team* getBowlingTeam() {
        if (!teams[0]->isBatting) {
            return teams[0];
        }
        return teams[1];
    }


    void executeOneBall(const string& ballState, player *striker, team *battingTeam) {

        if(ballState == "1") {

            striker->runsScored += 1;
            striker->setBallsFaced(1);
            battingTeam->runs += 1;

        } else if(ballState == "2") {
            striker->runsScored += 2;
            striker->setBallsFaced(1);
            battingTeam->runs += 2;

        } else if(ballState == "3") {
            striker->runsScored +=3;
            striker->setBallsFaced(1);
            battingTeam->runs += 3;

        } else if(ballState == "4") {
            striker->runsScored +=4;
            striker->num4s +=1;
            battingTeam->runs += 4;
            striker->setBallsFaced(1);

        } else if(ballState == "6") {
            striker->runsScored +=6;
            striker->num6s +=1;
            battingTeam->runs += 6;
            striker->setBallsFaced(1);

        } else if(ballState == "W") {
            striker->setOut(true);
            battingTeam->wickets +=1;

        } else if(ballState == "WD") {
            battingTeam->runs += 1;

        } else if(ballState == "NB") {
            battingTeam->runs += 1;
        }
    }

    bool shouldChangeStrike(string val) {
        if(val == "1" || val =="3") {
            return true;
        }
        return false;
    }

};