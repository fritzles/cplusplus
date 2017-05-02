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

class Hero {
public:
    /**
     * constructor(s)/destructor
     */
    Hero();
    ~Hero();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns name, damage, health, alive-ness
     */
    string get_name() const;
    double get_damage() const;
    double get_health() const;
    bool is_alive() const;

    /**
    * Requires: string, double, double
    * Modifies: name, damage, health
    * Effects: sets the variable to given value
    */
    void set_name(string);
    void set_damage(double);
    void set_health(double);

    /**
    * Requires: double, double
    * Modifies: (double) health, (bool) alive
    * Effects: changes health based on passed in value, iff the hero is alive
    */
    void take_damage(double);
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

    // fields
    string name;
    double damage;
    double health;
    bool alive;
};
#endif //hero_hpp
