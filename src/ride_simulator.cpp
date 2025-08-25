#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Driver {
    string name;
    float rating;
    float distance;
    bool operator<(const Driver& d) const {
        return rating < d.rating; // max-heap by rating
    }
};

queue<string> riders;
priority_queue<Driver> drivers;
vector<string> rideHistory;

void addDriver() {
    Driver d;
    cout << "Enter driver name: ";
    cin >> d.name;
    cout << "Enter rating: ";
    cin >> d.rating;
    cout << "Enter distance to rider (km): ";
    cin >> d.distance;
    drivers.push(d);
}

void addRider() {
    string name;
    cout << "Enter rider name: ";
    cin >> name;
    riders.push(name);
}

void dispatchRide() {
    if (drivers.empty() || riders.empty()) {
        cout << "No drivers or riders available.\n";
        return;
    }
    Driver d = drivers.top(); drivers.pop();
    string r = riders.front(); riders.pop();
    cout << "Driver " << d.name << " (Rating: " << d.rating << ") assigned to Rider " << r << endl;
    rideHistory.push_back(d.name + " -> " + r);
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Driver\n2. Add Rider\n3. Dispatch Ride\n4. View History\n5. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addDriver();
        else if (choice == 2) addRider();
        else if (choice == 3) dispatchRide();
        else if (choice == 4)
            for (auto &r : rideHistory) cout << r << endl;
    } while (choice != 5);
    return 0;
}
