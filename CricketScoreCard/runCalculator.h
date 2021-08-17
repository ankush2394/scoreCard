
#include "team.h"
#include "player.h"
#ifndef CRICKETSCORECARD_RUNCALCULATOR_H
#define CRICKETSCORECARD_RUNCALCULATOR_H

class runCalculator {
public:
    runCalculator() {

    }

    void executeOneBall(const string& ballState, player *striker, team *battingTeam) {

        if(ballState == "1") {

            striker->setRuns(1);
            striker->setBallsFaced(1);
            battingTeam->setRuns( 1);

        } else if(ballState == "2") {
            striker->setRuns(2);
            striker->setBallsFaced(1);
            battingTeam->setRuns( 2);

        } else if(ballState == "3") {
            striker->setRuns(3);
            striker->setBallsFaced(1);
            battingTeam->setRuns( 3);

        } else if(ballState == "4") {
            striker->setRuns(4);
            striker->set4s(1);
            battingTeam->setRuns( 4);
            striker->setBallsFaced(1);

        } else if(ballState == "6") {
            striker->setRuns(6);
            striker->set6s(1);
            battingTeam->setRuns( 6);
            striker->setBallsFaced(1);

        } else if(ballState == "W") {
            striker->setOut(true);
            battingTeam->setWickets(1);

        } else if(ballState == "WD") {
            battingTeam->setRuns( 1);

        } else if(ballState == "NB") {
            battingTeam->setRuns( 1);
        }
    }


};
#endif //CRICKETSCORECARD_RUNCALCULATOR_H
