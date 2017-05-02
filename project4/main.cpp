//
// Created by fritzles on 2/7/2017.
//

#include "Hero.h"
#include "Team.h"

#include <string>
#include <iomanip>
using namespace std;

void test_team();

void test_die();
void test_heal(string expected_result, double heal_amount, double starting_health);
void print(string message);
void test_equality();
void test_cout();
void test_revive();
void print_vector();


int main() {
//    test_die();
//    cout << endl;
//    test_heal("false,0", 20, 0);
//    //test_heal("false,0", 0, 0); //Assert in Hero::heal prevents this
//    //test_heal("false,0", -1, 0); //Assert in Hero::heal prevents this
//    cout << endl;
//    test_equality();
//    cout << endl;
//    test_cout();
//    cout << endl;
//    test_revive();
//    cout << endl;
    test_team();
//    cout << endl;
    return 0;
}

void test_die() {
    print("Die Test");
    Hero h;
    int damage = h.get_health();
    h.take_damage(damage);
    cout << "Actual:   " << boolalpha << h.is_alive() << endl;
    cout << "Expected: false\n";
}

void test_heal(string expected_result, int heal_amount, int starting_health) {
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
    e.set_hero(MERCY);
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

void test_team() {
    //testing the methods of the Team class. Hero methods tested last assignment.
    Player b("fritzles",TORBJORN), c("brokenforce",DVA), d("joylessprole",MERCY), e("testing3",BASTION),
            f("testing4",ANA), g("testing5",REAPER), h("bree",REINHARDT), i("testing7",SOLDIER), j("testing8",HANZO);
    Player a( "Conic", SYMMETRA, {b,c,d});
    vector<Player> startingTeam = {a, b, c};
    Team t(startingTeam), u;
    t.debug_on();

    cout << "--- Team size" << endl << "|" << endl << "|" << endl << "V" << endl;
    cout << u.size() << " Empty team." << endl;
    cout <<  t.size() <<  " ST- Team: " << t << endl; //starting team
    t.add_member(d);  //add MERCY to list
    cout <<  t.size() << " AM- Team: " << t << endl;
    t.change_member(d, e); //swap MERCY for BASTION
    cout <<  t.size() << " CM- Team: " << t << endl;
    t.add_member(d); //readd MERCY
    cout <<  t.size() << " AM- Team: " << t << endl;
    t.add_member(e); //add BASTION, expect no change/error message (if debug) because hero is already on the team
    cout <<  t.size() << " AMD- Team: " << t << endl;
    t.add_member(f); //add ANA
    cout <<  t.size() << " AM- Team: " << t << endl;
    t.add_member(g); //add REAPER, expect no change, since teams have max size of 6
    cout <<  t.size() << " AMM- Team: " << t << endl;
    t.remove_member(0); //remove first member, expect 5 player team with Symmetra removed
    cout <<  t.size() << " RFM- Team: " << t << endl;
    t.remove_member(100); //remove hundreth member, expect 5 player team with no changes
    cout <<  t.size() << " RFMOOB- Team: " << t << endl;
    t.add_member(a); //readd Symmetra, expect to see Symmetra at end of list
    cout <<  t.size() << " RAFM- Team: " << t << endl;
    t.remove_member(j); //remove non-existent hero, expect no change to team. if debug is on, expect error message in terminal
    cout <<  t.size() << " RNH- Team: " << t << endl;
    t.remove_member(a); //remove Symmetra again, this time by reference to Hero
    cout <<  t.size() << " REH- Team: " << t << endl;
    t.debug_off(); //turn debug off
    t.remove_member(i); //doesn't exist on team, should produce no error output because debug is off.
    cout <<  t.size() << " RNH- Team: " << t << endl;

    vector<Player> friends = a.get_friends(); //inital friend list
    cout << "Friends of Conic   " << friends.size() << endl;
    for(int i=0; i < friends.size(); i++) {
        cout << friends[i].get_player_name() << "  " << flush;
    }
    cout << endl;

    a.remove_friend(b); //remove a friend you do have
    friends = a.get_friends();
    cout << "Friends of Conic   " << friends.size() << endl;
    for(int i=0; i < friends.size(); i++) {
        cout << friends[i].get_player_name() << "  " << flush;
    }
    cout << endl;

    a.remove_friend(b); //remove a friend you don't have
    friends = a.get_friends();
    cout << "Friends of Conic   " << friends.size() << endl;
    for(int i=0; i < friends.size(); i++) {
        cout << friends[i].get_player_name() << "  " << flush;
    }
    cout << endl;

    a.add_friend(c); //add the same friend?
    friends = a.get_friends();
    cout << "Friends of Conic   " << friends.size() << endl;
    for(int i=0; i < friends.size(); i++) {
        cout << friends[i].get_player_name() << "  " << flush;
    }
    cout << endl;

    a.add_friend(h); //add the same friend?
    friends = a.get_friends();
    cout << "Friends of Conic   " << friends.size() << endl;
    for(int i=0; i < friends.size(); i++) {
        cout << friends[i].get_player_name() << "  " << flush;
    }
    cout << endl;

    cout << endl;
    cout << "Changing Hero" << endl;
    cout << h.get_name() << endl;
    h.set_player_hero(MCCREE);
    cout << h.get_name() << endl;
}
