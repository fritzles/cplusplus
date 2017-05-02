//
// Created by fritzles on 2/7/2017.
//

#include "Hero.h"

//Commented out asserts, per project feedback

Hero::Hero() : damage(50), health(200), alive(true){
    set_hero(SOLDIER);
}

Hero::Hero(hero h) : damage(50), health(200), alive(true){
    set_hero(h);
}

Hero::~Hero() {
}

string Hero::get_name() const{
    return name;
}

int Hero::get_damage() const{
    return damage;
}

int Hero::get_health() const {
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

void Hero::set_damage(int damage) {
    assert(damage >= 0);
    this->damage = damage;
}

void Hero::set_health(int health) {
    //no max health, since you can get shield and armor
    assert(health >= 0);
    if(health == 0) {
        die();
    }else {
        this->health = health;
    }
}

void Hero::take_damage(int damage_amount) {
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
    if(hero_id == NULL_HERO){
        hero_class = -1;
    }else if(hero_id <= REAPER) {
        hero_class = OFFENSE;
    }else if(hero_id <= TORBJORN) {
        hero_class = DEFENSE;
    }else if(hero_id <= REINHARDT) {
        hero_class = TANK;
    }else if(hero_id <= SYMMETRA) {
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
    return name + ":" + class_to_string() + " " + to_string(health);
}

ostream& operator<<(ostream& os, Hero h) {
    os << h.hero_to_string();
    return os;
}

bool operator==(Hero& h, Hero& e){
    return (h.get_name() == e.get_name());
}
