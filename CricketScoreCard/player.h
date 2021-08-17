#pragma once
class player {
    bool isOut, isBatting ;
    int playerId, runsScored=0;
    int num4s = 0; int num6s = 0;
    int ballsFaced = 0;
    bool onPitch;
public:

    player(int pId, bool isOut , bool isBatting) {
        this->playerId = pId;
        this->isOut = isOut;
        this->isBatting = isBatting;
        this->onPitch = false;
    }

    int getRunsScored() {
        return runsScored;
    }

    void setRuns(int runs) {
        runsScored+=runs;
        return;
    }
    void set4s(int x) {
        num4s+=1;
    }
    void set6s(int x) {
        num6s+=1;
    }
    int get4s() {
        return num4s;
    }

    int get6s() {
        return num6s;
    }

    void setOut(bool out) {
        isOut = out;
    }

    bool isOutt() {
        return isOut;
    }

    bool onStrike() {
        return isBatting;
    }

    void setBallsFaced(int balls) {
        ballsFaced += balls;
    }

    int getBallsFaced() {
        return ballsFaced;
    }

    void setBatting(bool isBat) {
        isBatting = isBat;
    }

    void setOnPitch(bool x) {
        onPitch = x;
    }

    bool getOnPitch() {
        return onPitch;
    }

    int getPlayerId() {
        return playerId;
    }

};


