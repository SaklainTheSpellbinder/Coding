#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int i=0;
            int j=s.length()-1;
            while(i<j){
                while(i<j && !('a'<=s[i] && s[i]<='z') && !('A'<=s[i] && s[i]<='Z') && !('0'<=s[i] && s[i]<='9')){
                    i++;
                }
                while(i<j && !('a'<=s[j] && s[j]<='z') && !('A'<=s[j] && s[j]<='Z') && !('0'<=s[j] && s[j]<='9')){
                    j--;
                }
                if(tolower(s[i])!=tolower(s[j]))
                    return false;
                i++;
                j--;
            }
            return true;                        
        }
};