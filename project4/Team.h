//
// Created by fritzles on 2/23/2017.
//

#ifndef team_h
#define team_h


#include "Player.h"
#include <vector>
#include <iostream>

using namespace std;

class Team {

public:
    /*
     * constructors/destructor
     */
    Team();
    Team(vector<Player>);
    ~Team();

    /*
     * Requires: Hero to add
     * Modifies: team vector
     * Effects: adds hero to team iff unique hero and team not full
     */
    void add_member(Player);

    /*
    * Requires: Hero to change from and to
    * Modifies: vector<Hero> team
    * Effects: replaces an instance of one hero with another, provided they are still a unique hero on the team
    */
    void change_member(Player, Player);

    /*
    * Requires: Hero (to find on team) or index of hero on team
    * Modifies: vector<Hero> team
    * Effects: removes selected hero iff they exist/ hero at index iff valid space on team
    */
    void remove_member(Player);
    void remove_member(int);

    /*
    * Requires: index
    * Modifies: nothing
    * Effects: returns Hero at given index
    */

    Hero get_member(int);

    /*
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns size of vector
    */
    int size();

    /*
    * Requires: Hero to find
    * Modifies: nothing
    * Effects: returns index of Hero, -1 if not found
    */
    int find_hero(Player);

    /*
    * Requires: nothing
    * Modifies: debug
    * Effects: whether or not certain debug messages are printed to console
    */
    void debug_on();
    void debug_off();

    friend ostream& operator<<(ostream&, Team);

private:
    vector<Player> team;
    const int max_team_size = 6;
    bool debug = false;
};


#endif //team_h
