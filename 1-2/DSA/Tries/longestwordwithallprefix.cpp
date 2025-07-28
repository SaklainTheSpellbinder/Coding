#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

class Node{
public:
    unordered_map<char,Node*>children;
    bool endofword;
    Node(){
        endofword=false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }

    void insert(string key){
        Node* temp=root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        
        temp->endofword=true;
    }

    bool search(string key){
        Node* temp=root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return temp->endofword;
    }

    void longestHelper(Node* root,string &ans,string temp){
        for(auto child: root->children){
            if(child.second->endofword){
                temp+=child.first;

                if((temp.size()==ans.size() && temp<ans)||(temp.size()>ans.size())){ 
                    ans=temp;
                }

                longestHelper(child.second,ans,temp);
                temp=temp.substr(0,temp.size()-1);
            }
        }
    }

    string longestStringWithEOW(){
        string ans="";
        longestHelper(root,ans,"");
        return ans;
    }
};

string longeststring(vector<string>dict){
    Trie trie;

    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main(){
    vector<string> words={"ap","a","app","appl","apple","apply","banana"};
    cout<<longeststring(words)<<endl;
}
