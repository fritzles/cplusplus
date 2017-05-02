#include <iostream>
#include <vector>
#include <memory>

#include "Objective.h"

using namespace std;

int main() {
    vector<unique_ptr<Objective> > myObjectives;
    myObjectives.push_back(make_unique<Payload>(RED, BLUE));
    myObjectives.push_back(make_unique<Point>(RED));

    myObjectives[0]->set_defenders(1);
    myObjectives[1]->set_attackers(1);
    for (int i = 0; i < myObjectives.size(); ++i) {
        cout << myObjectives[i]->get_progress() << endl;
        myObjectives[i]->capture(.2);
        cout << myObjectives[i]->print() << endl;
        myObjectives[i]->capture(200);
        cout << myObjectives[i]->print() << endl;
        myObjectives[i]->capture(-20);
        cout << myObjectives[i]->print() << endl;
        cout << endl;
    }
    return 0;
}