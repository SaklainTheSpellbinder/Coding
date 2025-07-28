#include<iostream>
using namespace std;
class Student{

    //properties        default private thake
    private://na dileo private ee thakbe
    string name;

    public:
        float cgpa;

        //methods
        void getPercentage(){
            cout<<(cgpa*10)<<"% \n";
        }
        
        //sttlers
        void setName(string nameVal){
            name=nameVal;
        }
        void setCgpa(float cgpaVal){
            cgpa=cgpaVal;
        }

        //getters
        string getName(){
            return name;
        }
        float getcgpa(){
            return cgpa;
        }

};

class User{
    int id;
    string username;
    string pass;
    void deactivate(){
        cout<<"Deactivating.." <<endl;
    }
};

int main(){
    Student s1;//object
    //s1.name="Saklain";        unaccessable
    s1.cgpa=3.99;
    s1.getPercentage();
    s1.setName("Saklain");
    s1.setCgpa(4);
    cout<<s1.getName()<<endl;
    cout<<s1.getcgpa()<<endl;
    cout<<sizeof(s1)<<endl;
    return 0;
}