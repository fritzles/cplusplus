//Michael Fritz
//CS120B
//Proejct 1

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << fixed << setprecision(2);

    cout << "Welcome to Overwatch, Hero!" << endl;
    cout << "We need a name for you... But, here's a list of already used names!" << endl;

    //Open file, read into a vector and also print it out
    ifstream in_file("overwatch.txt");
    vector<string> overwatch_heros;
    if(in_file) {
        string hero_name;
        while(getline(in_file,hero_name)) {
            overwatch_heros.push_back(hero_name);
            cout << hero_name << endl;
        }
    }
    in_file.close();

    cout << "So now we you've met your fellow heros..." << endl;
    cout << "What is your first name? (Only your first name will be saved.) " << endl;

    //set it to something shrug
    string your_name = "Fred";
    cin >> your_name; //ignore everything after the first word, since we don't care
    //also I guess you can call yourself a number or literally anything.... it's your name.

    //clear the rest of that line in prep for the next question
    string flush_cin;
    getline(cin, flush_cin);

    cout << "And how much damage can you do? (Please enter a number)" << endl;
    int your_damage = 0;
    while(!(cin >> your_damage)) {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "That's not right... Try again." << endl;
    }

    cout << "Okay, nice to meet you, " << your_name << "!" << endl;
    cout << "And your damage is " << your_damage << "." << endl;
    cout << "Wow... That must mean you're a";
    if(your_damage < 0) {
        cout << " healer, right?";
    } else if(your_damage < 100) {
        cout << " tank or offense character, right?";
    } else {
        cout << " character that Blizzard is going to nerf in their next patch.";
    }

    cout << endl;

    cout << "We just need a second to write that down...." << endl;

    //Record the new recruits, appended!
    ofstream out_file("new_overwatch.txt", ofstream::app);
    if(out_file) {
        //Output format: Name Damage
        out_file <<  your_name << " " << your_damage << endl;
    }
    out_file.close();

    cout << "Okay, so now that I got that written down...." <<  endl;
    cout << "Welcome to Overwatch, " << your_name << "!" << endl;

    cout << "I also want to let you know about the other recent sign ups..." << endl;

    cout << "Name               Damage" << endl; //25 chars long
    ifstream recruits_file("new_overwatch.txt");
    if(recruits_file) {
        string recruit;
        int damage;
        cout << setfill(' ');
        while(recruits_file >> recruit >> damage) {
            cout << recruit ;
            cout << setw(25 - (int)recruit.length())<< damage << endl;
        }
    }
    recruits_file.close();

    return 0;
}

