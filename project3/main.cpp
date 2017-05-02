//
// Created by fritzles on 2/7/2017.
//

#include "Hero.h"
#include "Team.h"

#include <string>
#include <iomanip>
using namespace std;

int main() {

    //testing the methods of the Team class. Hero methods tested last assignment.
    Hero a(SYMMETRA), b(TORBJORN), c(DVA), d(MERCY), e(BASTION), f(ANA), g(REAPER), h(REINHARDT), i(SOLDIER), j(HANZO);
    vector<Hero> startingTeam = {a, b, c};
    Team t(startingTeam), u;
    t.debug_on();

    cout << "--- Team size" << endl << "|" << endl << "|" << endl << "V" << endl;
    cout << u.size() << " Empty team." << endl;
    cout <<  t.size() <<  " ST- Team: " << t << endl; //starting team
    t.add_member(d);  //add MERCY to list
    cout <<  t.size() << " AM- Team: " << t << endl;
    t.change_member(d, e); //swap MERCY for BASTION
    cout <<  t.size() << " CM- Team: " << t << endl;
    t.add_member(d); //readd MERCY
    cout <<  t.size() << " AM- Team: " << t << endl;
    t.add_member(e); //add BASTION, expect no change/error message (if debug) because hero is already on the team
    cout <<  t.size() << " AMD- Team: " << t << endl;
    t.add_member(f); //add ANA
    cout <<  t.size() << " AM- Team: " << t << endl;
    t.add_member(g); //add REAPER, expect no change, since teams have max size of 6
    cout <<  t.size() << " AMM- Team: " << t << endl;
    t.remove_member(0); //remove first member, expect 5 player team with Symmetra removed
    cout <<  t.size() << " RFM- Team: " << t << endl;
    t.remove_member(100); //remove hundreth member, expect 5 player team with no changes
    cout <<  t.size() << " RFMOOB- Team: " << t << endl;
    t.add_member(a); //readd Symmetra, expect to see Symmetra at end of list
    cout <<  t.size() << " RAFM- Team: " << t << endl;
    t.remove_member(j); //remove non-existent hero, expect no change to team. if debug is on, expect error message in terminal
    cout <<  t.size() << " RNH- Team: " << t << endl;
    t.remove_member(a); //remove Symmetra again, this time by reference to Hero
    cout <<  t.size() << " REH- Team: " << t << endl;
    t.debug_off(); //turn debug off
    t.remove_member(i); //doesn't exist on team, should produce no error output because debug is off.
    cout <<  t.size() << " RNH- Team: " << t << endl;

    return 0;
}

