#pragma once

#include "player.h"
#include <vector>
#include <map>
using namespace std;
class team {
    bool isBatting;
    int runs,wickets;
    vector<player*> players;

public:

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
            if(!players[i]->isOutt() &&!players[i]->getOnPitch()) {
                notoutplayers.push_back(players[i]);
                if(players[i]->onStrike()) {
                    return players[i];
                }
            }
        }
        if(notoutplayers.size()) {
            for(int i=0;i<notoutplayers.size();i++) {
                if(!notoutplayers[i]->getOnPitch()) {
                    notoutplayers[0]->setBatting(true);
                    notoutplayers[0]->setOnPitch(true);
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
                players[i]->setOnPitch( true);
                return players[i];
            }
        }
        throw "no player left";
    }

    void setRuns(int x) {
        runs+=x;
    }
    int getRuns() {
        return runs;
    }
    void setWickets(int x) {
        wickets+=x;
    }
    int getWickets() {
        return wickets;
    }
    void setBatting(bool x) {
        isBatting = x;
    }
    bool getBatting() {
        return isBatting;
    }

    //morality says always kep ur promises it binds you, wisdom says never make promises, it frees you

};