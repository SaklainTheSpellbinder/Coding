#include <cstring>
#include<iostream>
using namespace std;

class Player {
    char* name = new char[50]; // name of the player
    int salary = 0;            // salary of the player

public:
    Player() = default;

    char* getName(){
        return name;
    }

    int getSalary(){
        return salary;
    }

    void setName(char* s){
        strcpy(name,s);
    }

    void setSalary(int salary){
        this->salary=salary;
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
        strcpy(name, other.name);
        num = other.num;
        for (int i = 0; i < num; ++i) {
            players[i].setName(other.players[i].getName()) ; // uses Player's assignment operator
            players[i].setSalary(other.players[i].getSalary()) ;
        }
        cout <<"hey from copy constructor\n";
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
