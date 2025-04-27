#include<iostream>
using namespace std;


class Example{
    public:
        static int x;      //ekhane direct declare kora jay na...korte hole   static const int x=0; evabe likhte hbe....kintu sheta hole change kora jabe na jemn amra main e chnage korsi
        Example(){
            cout<<"constructor...\n";
        }
        ~Example(){
            cout<<"destructor...\n";
        }
};

int Example::x=0;

main(){
    static Example e1,e2,e3;   //egular scope to pura main ee...tai static diy r na diy program end howa prjnto cholbe
    cout<<e1.x++<<endl;
    cout<<e1.x++<<endl;
    cout<<e3.x++<<endl;
    int a=0;
    if(a==0){
        static Example eg;    // scope shesh hole eta destroy hoye jabe...jodi static keyword use na kori.....kintu jodi use kori...tahole program end er prjnto thakbe....
    }
    cout<<"code ending"<<endl;
}
