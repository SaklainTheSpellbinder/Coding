#include<iostream>
#include<algorithm>
using namespace std;
class A{
    string secret="secret data";
    friend class B;
    friend void revealsecret(A &obj);
};

class B{  //becomes a friend class of A
    public :
        void showSecret(A &obj){
            cout << obj.secret <<endl; 
        }
};

void revealsecret(A &obj){
    cout<<obj.secret<<endl;
}

int main(){ 
    A a1;
    B b1;
    b1.showSecret(a1);
    revealsecret(a1);
    return 0;
}

