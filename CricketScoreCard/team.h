#ifndef CRICKETSCORECARD_TEAM_H
#define CRICKETSCORECARD_TEAM_H

#include "player.h"
#include <vector>
#include <map>
using namespace std;
class team {

public:
    bool isBatting;
    int runs,wickets;
    map<int, player> currentIdsOnPitch;
    vector<player*> players;

    team(vector<int> pIds, bool isBatt) {
        runs=0;
        wickets=0;
        this->isBatting = isBatt;
        for(int i=0;i<pIds.size();i++) {
            //auto *p1 = new player(pIds[i], false, false);
            players.push_back(new player(pIds[i], false, false));
        }
    }

    vector<player*> getPlayers() {
        return players;
    }

    player* getOnStrikePlayer() {
        vector<player*> notoutplayers;
        for(int i=0;i<players.size();i++) {
            if(!players[i]->isOutt() &&!players[i]->onPitch) {
                notoutplayers.push_back(players[i]);
                if(players[i]->onStrike()) {
                    return players[i];
                }
            }
        }
        if(notoutplayers.size()) {
            for(int i=0;i<notoutplayers.size();i++) {
                if(!notoutplayers[i]->onPitch) {
                    notoutplayers[0]->setBatting(true);
                    notoutplayers[0]->onPitch = true;
                    return notoutplayers[i];
                }
            }
        } else {
            throw "no player left";
        }
        throw "no player left";
    }

    player* getOffStrikePlayer() {
        vector<player*> notoutplayers;
        for(int i=0;i<players.size();i++) {
            if(!players[i]->isOutt() && !players[i]->onStrike()) {
                players[i]->onPitch = true;
                return players[i];
            }
        }
        throw "no player left";
    }

    //morality says always kep ur promises it binds you, wisdom says never make promises, it frees you

};

#endif