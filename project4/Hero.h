//
// Created by fritzles on 2/7/2017.
//


#ifndef hero_hpp
#define hero_hpp

#include <iostream>
#include <string>
#include <cassert>
#include <ostream>

using namespace std;

enum hero {
    GENJI, MCCREE, PHARA, REAPER, SOLDIER, SOMBRA, //Offense
    BASTION, HANZO, JUNKRAT, MEI, TORBJORN, WIDOWMAKER, //Defense
    DVA, REINHARDT, ROADHOG, WINSTON, ZARYA, //Tank
    ANA, LUCIO, MERCY, SYMMETRA, ZENYATTA, //Support
    NULL_HERO
};

enum hero_class {OFFENSE, DEFENSE, TANK, SUPPORT};

class Hero {
public:
    /**
     * constructor(s)/destructor
     */
    Hero();
    Hero(hero);
    ~Hero();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns name, damage, health, alive-ness
     */
    string get_name() const;
    int get_damage() const;
    int get_health() const;
    bool is_alive() const;

    /**
    * Requires: string, double, double
    * Modifies: name, damage, health
    * Effects: sets the variable to given value
    */
    void set_hero(hero);
    void set_damage(int);
    void set_health(int);

    /**
    * Requires: double, double
    * Modifies: (double) health, (bool) alive
    * Effects: changes health based on passed in value, iff the hero is alive
    */
    void take_damage(int);
    void heal(double);



    /**
     * Requires: double representing health to be regenerated upon revive
     * Modifies: (double)health and (bool)alive
     * Effects: fully heals to given input and toggles alive to true
     */
    void revive(double);

    friend ostream& operator<<(ostream&, Hero);
    /**
     * heros are equal based on name alone,
     * since if you're both playing Mcree, that's the same character
     * damage may change, for instance if you get buffed or something.
     * Only true equality is name
     */
    friend bool operator==(Hero&, Hero&);

private:
    /**
     * Requires: nothing
     * Modifies: (double)health and (bool)alive
     * Effects: set health to 0, toggle alive to false
     */
    //METHODS
    void die();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns enum as string
     */
    string hero_to_string();
    string class_to_string();

    /**
     * Requires:
     * Modifies:
     * Effects:
     */
    void set_class_type();
    void set_name();


    // fields
    string name;
    int damage;
    int health;
    bool alive;

    int hero_class;
    int hero_id;


};


#endif //hero_hpp
