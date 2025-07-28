#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    string str;
    cin>>str;
    string ptr;
    cin>>ptr;
    unordered_map<char,int>m;
    if(str.size()!=ptr.size()){
        cout<<"Not an anagram"<<endl;
        return 0;
    }
    for(int i=0;i<str.size();i++){
        if(m.count(str[i]))
            m[str[i]]++;
        else{
            m[str[i]]=1;
        }
    }
    for(int i=0;i<ptr.size();i++){
        if(m.count(ptr[i]))
            m[ptr[i]]--;
        else{
            cout<<"Not an anagram"<<endl;
            return 0;
        }
        //we can try erasing if it is zero here....but maybe sometimes erasing is time consuming.....so i chosed not to
    }
    for (auto& pair : m) {
        if (pair.second != 0) {
            cout << "Not an Anagram" << endl;
            return 0;
        }
    }
    cout << "An Anagram" << endl;
    return 0;
}