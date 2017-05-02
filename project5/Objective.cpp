//
// Created by fritzles on 3/6/2017.
//

#include "Objective.h"


Objective::Objective(): attackers_on_point(0), defenders_on_point(0){}
Objective::~Objective() {}

void Objective::set_attackers(int attackers) {
    attackers_on_point = attackers;
}

void Objective::set_defenders(int defenders) {
    defenders_on_point = defenders;
}


Payload::Payload(team defend, team attack): Objective(),
                                            defending_team(defend),
                                            attacking_team(attack),
                                            distance_traveled(0) {}

void Payload::capture(double distance_to_travel) {
    if(attackers_on_point == 0 && defenders_on_point > 0) {
        distance_traveled += distance_to_travel;
    }
}

double Payload::get_progress() {
    return distance_traveled;
}

string Payload::print() {
    return "Payload: " + std::to_string(get_progress()) + " meters traveled";
}


Point::Point(team control): Objective(),  controlling_team(control) , locked(false){}

void Point::capture(double percent_to_cap) {
    if(!locked) {
        if(attackers_on_point > 0 && defenders_on_point == 0) {
            percentage += percent_to_cap;
        }

        if(percentage >= 100){
            percentage = 100;
            lock();
        }
    }
}

string Point::print() {
    return "Payload: " + std::to_string(get_progress()) + "%";
}

void Point::lock() {
    locked = true;
}

double Point::get_progress() {
    return percentage;
}