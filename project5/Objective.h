//
// Created by fritzles on 3/6/2017.
//

#ifndef objective_h
#define objective_h

#include <string>
#include <ostream>
#include <iostream>

using namespace std;

enum team { BLUE, RED };

class Objective {
public:
    //constructors
    Objective();
    ~Objective();

    /**
     * Requires: double to add to capture progress
     * Modifies: capture progress
     * Effects: increases capture progress
     */
    virtual void capture(double) = 0;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints the state of the objective
     */
    virtual string print() = 0;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: gets the progress of the objective
     */
    virtual double get_progress() = 0;


    /**
     * Requires: int
     * Modifies: attackers/defenders
     * Effects: sets the thing to the thing sorry its late and i dont wanna think
     */
    void set_attackers(int);
    void set_defenders(int);

protected:
    int attackers_on_point;
    int defenders_on_point;
};

class Payload : public Objective{
public:
    //constructor
    Payload(team, team);


    /**
     * Requires: double to cap
     * Modifies: progress
     * Effects: adds distance
     */
    virtual void capture(double) override ;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns progress
     */
    virtual double get_progress();


    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints state of payload
     */
    virtual string print();

private:
    double distance_traveled;
    team defending_team;
    team attacking_team;
};

class Point : public Objective{
public:
    //constructor
    Point(team);


    /**
     * Requires: double to cap
     * Modifies: the progress %
     * Effects: adds to cap progress, locks the point once 100% achieved
     */
    virtual void capture(double) override ;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns progress
     */
    virtual double get_progress();


    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints that state of the point
     */
    virtual string print();

private:

    /**
     * Requires: nothing
     * Modifies: locked bool
     * Effects: sets locked to true
     */
    void lock();

    bool locked;
    double percentage;
    team controlling_team;
};


#endif //UNTITLED1_MAP_H


