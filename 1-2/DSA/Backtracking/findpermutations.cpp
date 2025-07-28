#include<iostream>
#include<string>
using namespace std;

// void permutations(string str){
//     if(str.size()==0){
//         cout<<"\n";
//         return;                                 //vul
//     }
//     for(int i=0;i<str.size();i++){
//         cout<<str[i];
//         if(i!=0)
//             permutations(str.substr(0,i)+str.substr(i+1,str.size()));
//         else
//             permutations(str.substr(1,str.size()));
//     }
// }

void permutations2(string str,string ans){
    if(str.size()==0){
        cout<<ans<<"\n";
        return;
    }
    for(int i=0;i<str.size();i++){
        permutations2(str.substr(0,i)+str.substr(i+1,str.size()),ans+str[i]);
    }
}

int main(){
    string str="Tuba";
    //permutations(str);
    permutations2(str,"");
}