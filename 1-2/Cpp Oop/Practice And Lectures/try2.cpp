#include <cstring>
#include<iostream>
using namespace std;

class Player {
    char* name = new char[50]; // name of the player
    int salary = 0;            // salary of the player

public:
    Player() = default;

    // Copy constructor for Player (deep copy)
    Player(const Player& other) {
        name = new char[50];
        strcpy(name, other.name);
        salary = other.salary;
    }

    // Assignment operator (optional if needed)
    Player& operator=(const Player& other) {
        if (this != &other) {
            strcpy(name, other.name);
            salary = other.salary;
        }
        return *this;
    }

    ~Player() {
        delete[] name;
    }
};

class Club {
    char* name = new char[50];        // name of the club
    Player* players = new Player[20]; // list of players in the club
    int num = 0;                      // number of players in the club

public:
    Club() = default;

    // Copy constructor for Club (deep copy)
    Club(const Club& other) {
        name = new char[50];
        strcpy(name, other.name);
        players = new Player[20];
        num = other.num;
        for (int i = 0; i < num; ++i) {
            players[i] = other.players[i]; // uses Player's assignment operator
        }
        cout <<"hey from copy constructor\n";
    }
      Club& operator=(const Club& other) {
        if (this != &other) {
            // Free existing memory
            delete[] name;
            delete[] players;

            // Allocate new memory and copy
            name = new char[50];
            strcpy(name, other.name);

            players = new Player[20];
            num = other.num;
            for (int i = 0; i < num; ++i) {
                players[i] = other.players[i];
            }
        }
        cout <<"Hey form copy assignment operator\n";
        return *this;
    }

    ~Club() {
        delete[] players;
        delete[] name;
    }
};

int main() {
    Club c1;
    Club c2 = c1; // Copy constructor is called
    return 0;
}