#include <iostream>
#include "match.h"
#include "over.h"
#include "team.h"
#include <vector>
#include <cmath>
using namespace std;


int main() {
    vector<int> v1{1,2,3,4,5}, v2{6,7,8,9,10};

    match m( 5, 2, v1, v2);
    //toss result
    m.start();
    m.start();

    vector<team*> teams = m.teams;
    int ans = abs(teams[0]->runs-teams[1]->runs);
    if(teams[0]->runs>teams[1]->runs) {
        cout<<"team1 is winner by "<<ans<<" runs"<<endl;
    } else if(teams[0]->runs<teams[1]->runs) {
        cout<<"team2 is winner"<<ans<<" runs"<<endl;
    } else {
        cout<<"tie"<<endl;
    }

    return 0;
}
