#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        bool validPalindromehelper(string &s,int i,int j,bool used){
                if(i>=j)
                    return true;

                if(s[i]==s[j]){
                    return validPalindromehelper(s,i+1,j-1,used);
                }
                else{
                    if(!used){
                        used=true;
                        return validPalindromehelper(s,i+1,j,used) || validPalindromehelper(s,i,j-1,used);
                    }
                    else
                        return false;
                }
        }
        
        bool validPalindrome(string s) {
            bool used=false;
            return validPalindromehelper(s,0,s.size()-1,used);
        }
};