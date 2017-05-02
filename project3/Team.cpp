//
// Created by fritzles on 2/23/2017.
//

#include "Team.h"


Team::Team() {
    team = {};
}

Team::Team(vector<Hero> t) {
    if(t.size() <= max_team_size) {
        team = t;
    }
}

Team::~Team() {
}

void Team::debug_on()  { debug = true; }
void Team::debug_off() { debug = false; }

void Team::add_member(Hero h) {
    if((find_hero(h) == -1) && (team.size() < max_team_size)) {
        team.push_back(h);
    }else if((find_hero(h) != -1) && debug){
        cout << "ERROR: Teams can only have a maximum of 1 of each hero." << endl;
    }else if((team.size() == max_team_size) && debug) {
        cout << "ERROR: Teams can only have a maximum of 6 heros." << endl;
    }
}

int Team::find_hero(Hero h){
    for( int i=0; i < team.size(); i++ ) {
        if(team[i] == h){
            return i;
        }
    }
    return -1;
}

int Team::size() {
    return team.size();
}

void Team::change_member(Hero h, Hero e) {
    int index = find_hero(h);
    if(index != -1) {
        team[index] = e;
    }
}

void Team::remove_member(Hero h) {
    int index = find_hero(h);
    if(index!=-1) {
        team.erase(team.begin() + index);
    }else {
        if(debug) { cout << "Hero not found on team." << endl; }
    }
}

void Team::remove_member(int i) {
    if(team.size() > i) {
        team.erase(team.begin() + i);
    }
}

Hero Team::get_member(int i) {
    if(team.size() > i) {
        return team[i];
    } else {
        return NULL;
    }
}

ostream& operator<<(ostream& os, Team t) {
    string team_comp = "";
    for(int i = 0; i < t.size(); i++) {
        team_comp += t.get_member(i).get_name() + " ";
    }
    os << team_comp << flush;
    return os;
}
