#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length()!=t.length())
                return false;
            int freq[26]={0};
            int n=s.length();
            int i=0;
            while(i<n){
                freq[s[i]-'a']++;
                i++;
            }
            i=0;
            while(i<n){
                if(freq[t[i]-'a']==0){
                    return false;
                }
                freq[t[i]-'a']--;
                i++;
            }
            return true;
        }
    };