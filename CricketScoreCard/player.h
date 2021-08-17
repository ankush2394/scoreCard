#pragma once
class player {
    bool isOut, isBatting ;
public:
    int playerId, runsScored=0;
    int num4s = 0; int num6s = 0;
    int ballsFaced = 0;
    bool onPitch;

    //make them private once everything done

    player(int pId, bool isOut , bool isBatting) {
        this->playerId = pId;
        this->isOut = isOut;
        this->isBatting = isBatting;
        this->onPitch = false;
    }

    int getRunsScored(int playerId) {
        return runsScored;
    }

    void setRuns(int runs) {
        runsScored+=runs;
        return;
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

};


