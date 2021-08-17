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

    cout<<m.getWinner();
    return 0;
}
