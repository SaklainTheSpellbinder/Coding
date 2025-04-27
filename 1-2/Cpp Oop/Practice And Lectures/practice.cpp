#include<iostream>
#include<algorithm>
using namespace std;
class User{
    int id;
    string password;
    public:
        string username;
    User(int id){
        this->id=id;
    }
    //settr
    void setpass(string pass){
        password=pass;
    }
    string getpass(){
        return password;
    }
};