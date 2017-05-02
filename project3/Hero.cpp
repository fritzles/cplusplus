//
// Created by fritzles on 2/7/2017.
//

#include "Hero.h"

//Commented out asserts, per project feedback

Hero::Hero() {
    set_hero(MCCREE);
    damage = 50.0;
    health = 200;
    alive = true;
}

Hero::Hero(hero h){
    set_hero(h);
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

void Hero::set_hero(hero h) {
    this->hero_id = h;
    set_name();
    set_class_type();
}

void Hero::set_name(){
    switch(hero_id){
        case GENJI:      name = "Genji"; break;
        case MCCREE:     name = "McCree"; break;
        case PHARA:      name = "Phara"; break;
        case REAPER:     name = "Reaper"; break;
        case SOLDIER:    name = "Soldier:76"; break;
        case SOMBRA:     name = "Sombra"; break;
        case BASTION:    name = "Bastion"; break;
        case HANZO:      name = "Hanzo"; break;
        case JUNKRAT:    name = "Junkrat"; break;
        case MEI:        name = "Mei"; break;
        case TORBJORN:   name = "Torbjörn"; break;
        case WIDOWMAKER: name = "Widowmaker"; break;
        case DVA:        name = "D.Va"; break;
        case REINHARDT:  name = "Reinhardt"; break;
        case ROADHOG:    name = "Roadhog"; break;
        case WINSTON:    name = "Winston"; break;
        case ZARYA:      name = "Zarya"; break;
        case ANA:        name = "Ana"; break;
        case LUCIO:      name = "Lucio"; break;
        case MERCY:      name = "Mercy"; break;
        case SYMMETRA:   name = "Symmetra"; break;
        case ZENYATTA:   name = "Zenyatta"; break;
        default:         name = "ERROR";
    }
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
//    assert(health > 0);
    alive = true;
    set_health(health);
}

void Hero::set_class_type(){
    if(hero_id <= SOMBRA) {
        hero_class = OFFENSE;
    }else if(hero_id <= WIDOWMAKER) {
        hero_class = DEFENSE;
    }else if(hero_id <= ZARYA) {
        hero_class = TANK;
    }else if(hero_id <= ZENYATTA) {
        hero_class = SUPPORT;
    }else {
        hero_class = -1; //signifies an error
    }
}

string Hero::class_to_string() {
    switch(hero_class){
        case OFFENSE: return "Offense";
        case DEFENSE: return "Defense";
        case TANK: return "Tank";
        case SUPPORT: return "Support";
        case -1: return "Invalid Hero Class";
        default: return "Error";
    }
}

string Hero::hero_to_string() {
    return get_name() + " " + to_string(get_health());
}

ostream& operator<<(ostream& os, Hero h) {
    os << h.get_name() << " " << h.get_health();
    return os;
}

bool operator==(Hero& h, Hero& e){
    return (h.get_name() == e.get_name());
}
