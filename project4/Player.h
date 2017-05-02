//
// Created by fritzles on 3/3/2017.
//

#ifndef player_h
#define player_h

#include "Hero.h"
#include <vector>

class Player : public Hero{
public:
   /**
     * Constructors
     *
     * Destructors
     */
    Player(string);
    Player(string, hero);
    Player(string, hero, vector<Player>);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns friends/name
     */
    string get_player_name();
    vector<Player> get_friends();

    /**
     * Requires: Player
     * Modifies: vector<Player> friends
     * Effects: adds/removes friends
     */
    void add_friend(Player);
    void remove_friend(Player);

    /**
     * Requires: hero
     * Modifies: the player's current hero
     * Effects: sets the hero
     */
    void set_player_hero(hero);
private:
    string player_name;
    vector<Player> friends_list;

    /**
     * Requires: player
     * Modifies: nothing
     * Effects; finds friend in friends list of current player
     */
    int find_friend(Player);

    friend bool operator==(Player&, Player&);
};


#endif //UNTITLED1_PLAYER_H
