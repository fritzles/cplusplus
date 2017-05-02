//
// Created by fritzles on 2/7/2017.
//

#include "Hero.h"

Hero::Hero() {
    name = "Mcree";
    damage = 50.0;
    health = 200;
    alive = true;
}

Hero::~Hero() {
}

string Hero::get_name() const{
    return name;
}

double Hero::get_damage() const{
    return damage;
}

double Hero::get_health() const {
    return health;
}

bool Hero::is_alive() const {
    return alive;
}

void Hero::set_name(string name) {
    this->name = name;
}

void Hero::set_damage(double damage) {
    assert(damage >= 0);
    this->damage = damage;
}

void Hero::set_health(double health) {
    //no max health, since you can get shield and armor
    assert(health >= 0);
    if(health == 0) {
        die();
    }else {
        this->health = health;
    }
}

void Hero::take_damage(double damage_amount) {
    assert(damage_amount >= 0);
    health -= damage_amount;
    if(health <= 0){
        die();
    }
}

void Hero::heal(double health_regenerated) {
    assert(health_regenerated > 0); //you can't heal for < 0
    if(alive){ //if they still have health
        health += health_regenerated;
    }
}

void Hero::die() {
    alive = false;
    health = 0;
}

void Hero::revive(double health) {
    assert(health > 0);
    alive = true;
    set_health(health);
}

ostream& operator<<(ostream& os, Hero h) {
    os << h.get_name() << " " << h.get_health();
    return os;
}

bool operator==(Hero& h, Hero& e){
    return (h.get_name() == e.get_name());
}
