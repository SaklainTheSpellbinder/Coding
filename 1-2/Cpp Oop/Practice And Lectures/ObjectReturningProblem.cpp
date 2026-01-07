#include<iostream>
#include<cstring>
using namespace std;

class Samp{
    char* s;
public:
    Samp(){
        cout<<"Creating a new object"<<endl;
        s=nullptr;
    }

    ~Samp(){
        cout<<"Going to destroy Samp obj"<<endl;
        free(s);
        cout<<"Freed S "<<endl;
    }

    Samp(const Samp& other){
        cout<<"Copying...."<<endl;
        s=(char*)malloc(strlen(other.s)+1); //eta ekta initialize er jayga...ekhane s null kina check kora jabe na to...karon eta to tahole bhul hobe...karon s to ekhono initialize kora hoynai
        strcpy(s,other.s);
        cout<<"copy done...exiting copy constructor"<<endl;
    }

    //Move constructor...notun jinish yayyyyyyyyyyyyyyyyyyyyyyyyyy
    Samp(Samp&& other){//eta dile auto call hoy copy constructor er jaygay oije return er shomoy temp jinish er shomoy
        cout<<"We are moving instead of copying....cause that helps....karon function theke return korar shomoy to oi function er object ta emneo destroy hoye jaber tai...notun copy na kore move korle bhalo na??"<<endl;
        s=other.s;
        other.s=nullptr;
        cout<<"Moving done"<<endl;
    }

    Samp& operator=(const Samp& other){
        if(this==&other)
            return *this;
        if(s!=nullptr){
            free(s);
        }
        cout<<"Assigning operator using"<<endl;
        s=(char*)malloc(strlen(other.s)+1);
        strcpy(s,other.s);
        cout<<"Assigning done"<<endl;
        return *this;
    }

    void show(){
        cout<<s<<endl;
    }

    void set(char* str){
        if(s!=nullptr)
            free(s);
        s=(char*)malloc(strlen(str)+1);
        strcpy(s,str);
    }
};

Samp input(){
    cout<<"Now inside input() function....we are going to create a new object here"<<endl;
    Samp s;
    cout<<"Now we are going to set something"<<endl;
    s.set("Hello from the string set in input() function now shown by show() function");
    cout<<"setting done....returning from input() function"<<endl;
    return s;
}

Samp justCheck(Samp s){
    cout<<"inside Just check...we are going to create another object now"<<endl;
    Samp t;
    t=s;
    return t;
}

int main(){
    Samp ob;
    cout<<"Going to call input()"<<endl;
    ob=input();
    cout<<"Back to main()"<<endl;
    ob.show();
    cout<<"Hey new thingy check kora lagbe...so amra justcheck() ke call kortesi"<<endl;
    Samp cute=justCheck(ob);
    cout<<"Okay bye bye returning from main....so main's object is destroying"<<endl;
}