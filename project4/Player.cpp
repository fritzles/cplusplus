//
// Created by fritzles on 3/3/2017.
//

#include "Player.h"

Player::Player(string player_name) {
    this->player_name = player_name;
}

Player::Player(string player_name, hero h) {
    this->player_name = player_name;
    set_hero(h);
}

Player::Player(string player_name, hero h, vector<Player> friends_list) {
    this->player_name = player_name;
    set_hero(h);
    this->friends_list = friends_list;
}

string Player::get_player_name() {
    return player_name;
}

vector<Player> Player::get_friends() {
    return friends_list;
}

void Player::add_friend(Player p) {
    int index = find_friend(p);
    if(index == -1) {
        friends_list.push_back(p);
    }
}

void Player::remove_friend(Player p) {
    int index = find_friend(p);
    if(index!=-1) {
        friends_list.erase(friends_list.begin() + index);
    }
}

void Player::set_player_hero(hero h) {
    set_hero(h);
}

int Player::find_friend(Player p) {
    for( int i=0; i < friends_list.size(); i++ ) {
        if(friends_list[i] == p){
            return i;
        }
    }
    return -1;
}

bool operator==(Player& p, Player& l){
    return (p.get_player_name() == l.get_player_name());
}