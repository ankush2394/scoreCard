#include "team.h"
#include <vector>
#include "winnerCalculator.h"
#include "runCalculator.h"
using namespace std;
class match {
    int numOvers, numOfPLayers;
    int totalRuns, totalWickets;
    vector<int> team1Ids, team2Ids;
    vector<team*> teams;
    runCalculator runcalculator;

public:

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
        try {
            player *strikerEnd = battingTeam->getOnStrikePlayer();
            player *offStrikerEnd = battingTeam->getOffStrikePlayer();

            for (int i = 0; i < numOvers; i++) {
                do {
                    cin >> val;

                    runcalculator.executeOneBall(val, strikerEnd, battingTeam);

                    if(strikerEnd->isOutt()) {
                        cout<<"striker id who is out is "<<strikerEnd->getPlayerId()<<endl;
                        strikerEnd = battingTeam->getOnStrikePlayer();
                        cout<<"new on strike  is "<<strikerEnd->getPlayerId()<<endl;

                    }

                    if(shouldChangeStrike(val)) {
                        swap(strikerEnd, offStrikerEnd);
                    }
                } while (setNumber(val));


                swap(strikerEnd, offStrikerEnd);

                cout << "over completed" << " on strike right now "<<strikerEnd->getPlayerId()<<" "<<strikerEnd->onStrike()<<endl;
                cout << "over completed" << " off strike right now "<<offStrikerEnd->getPlayerId()<<" "<<offStrikerEnd->onStrike()<<endl;

                cout<<battingTeam->getRuns()<<" "<<battingTeam->getWickets()<<endl;
                cout<<"player"<<" "<<"score"<< " "<<"4s"<<" "<<"6s"<<" "<<"Balls"<<endl;
                for(int i=0;i<battingTeam->getPlayers().size();i++) {
                    cout<<battingTeam->getPlayers()[i]->getPlayerId()<<" "<<battingTeam->getPlayers()[i]->getRunsScored()<<" "<<
                        battingTeam->getPlayers()[i]->get4s()<<" "<< battingTeam->getPlayers()[i]->get6s()<<" "<<battingTeam->getPlayers()[i]->getBallsFaced()<<" "<<
                        battingTeam->getPlayers()[i]->isOutt()<<endl;
                }
            }
            cout<<"INNINGS OVER"<<endl;
            battingTeam->setBatting(false);
            bowlingTeam->setBatting(true);
        } catch (const char * msg) {
            cout<<"all wickets down"<<endl;
        }

    }

    bool setNumber(string x) {
        if(x=="over") {
            return false;
        }
        return true;
    }

    team* getBattingTeam() {
        if (teams[0]->getBatting()) {
            return teams[0];
        }
        return teams[1];
    }

    team* getBowlingTeam() {
        if (!teams[0]->getBatting()) {
            return teams[0];
        }
        return teams[1];
    }

    bool shouldChangeStrike(string val) {
        if(val == "1" || val =="3") {
            return true;
        }
        return false;
    }

    string getWinner() {
        int ans = abs(teams[0]->getRuns()-teams[1]->getRuns());
        if(teams[0]->getRuns()>teams[1]->getRuns()) {
            return "team1 is winner by "+ to_string(ans)+" runs";
        } else if(teams[0]->getRuns()<teams[1]->getRuns()) {
            return "team2 is winner by "+ to_string(ans)+" runs";
        } else {
            return "tie";
        }
    }

};