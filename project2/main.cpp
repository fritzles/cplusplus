//
// Created by fritzles on 2/7/2017.
//

#include "Hero.h"

#include <string>
#include <iomanip>
using namespace std;

void test_die();
void test_heal(string expected_result, double heal_amount, double starting_health);
void print(string message);
void test_equality();
void test_cout();
void test_revive();

int main() {
    test_die();
    cout << endl;
    test_heal("false,0", 20, 0);
    //test_heal("false,0", 0, 0); //Assert in Hero::heal prevents this
    //test_heal("false,0", -1, 0); //Assert in Hero::heal prevents this
    cout << endl;
    test_equality();
    cout << endl;
    test_cout();
    cout << endl;
    test_revive();
    return 0;
}

void test_die() {
    print("Die Test");
    Hero h;
    double damage = h.get_health();
    h.take_damage(damage);
    cout << "Actual:   " << boolalpha << h.is_alive() << endl;
    cout << "Expected: false\n";
}

void test_heal(string expected_result, double heal_amount, double starting_health) {
    //ensure you cannot heal when dead
    //ensure you can't heal for < 0 (done via assert)
    print("Heal Test");
    Hero h;
    h.set_health(starting_health);
    h.heal(heal_amount);
    cout << "Actual:   " << boolalpha << h.is_alive() << "," << h.get_health() << endl;
    cout << "Expected: " << expected_result << endl;
}

void test_equality() {
    print("Equality Test");
    Hero h, e, r, o;
    //Make each hero slightly different, since equality is based on name alone
    e.set_name("High Noon");
    r.set_health(500);
    o.set_damage(2000);

    print("           h==e  h==r h==o e==r  e==o  r==o h==h");
    print("Expected:  false true true false false true true");
    cout << "Actual:   " << boolalpha << " " << (h==e);
    cout << " " << (h==r);
    cout << " " << (h==o);
    cout << " " << (e==r);
    cout << " " << (e==o);
    cout << " " << (r==o);
    cout << " " << (h==h) << endl;
}

void test_cout() {
    print("cout Test");
    Hero h;
    print("Expected: Mcree 200");
    cout << "Actual:   " << h << endl;
}

void test_revive() {
    //Revive can only be for positive values, no need to test (cause of assert)
    print("Revive Test");
    Hero h;
    cout << "Actual:   " << h.get_health() << ' ' << h.is_alive();
    h.take_damage(h.get_health());
    cout << ' ' << h.get_health() << ' ' << h.is_alive();
    h.revive(h.get_damage());
    cout << ' ' << h.get_health() << ' ' << h.is_alive();
    print("\nExpected: 200 true 0 false 50 true");
}

//Shortcut ig
void print(string message) {
    cout << message << endl;
}
