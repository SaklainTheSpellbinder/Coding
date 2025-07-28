#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int globalAlignment(string s1,string s2,int match,int mismatch,int gap){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=i*gap;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j*gap;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int diag;
            if(s1[i-1]==s2[j-1]){
                diag=dp[i-1][j-1]+match;
            }
            else{
                diag=dp[i-1][j-1]+mismatch;
            }
            int up=dp[i-1][j]+gap;
            int left=dp[i][j-1]+gap;
            dp[i][j]=max(diag,max(up,left));
        }
    }
    string x="";
    string y="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1] && dp[i][j]==dp[i-1][j-1]+match){
            x+=s1[i-1];
            y+=s2[j-1];
            i--;
            j--;
        }
        else if(s1[i-1]!=s2[j-1] && dp[i][j]==dp[i-1][j-1]+mismatch){
            x+=s1[i-1];
            y+=s2[j-1];
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]+gap){
            y+='-';
            x+=s1[i-1];
            i--;
        }
        else if(dp[i][j]==dp[i][j-1]+gap){
            x+='-';
            y+=s2[j-1];
            j--;
        }
    }
    while(i>0){
        x+=s1[i-1];
        y+='-';
        i--;
    }
    while(j>0){
        x+='-';
        y+=s2[j-1];
        j--;
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    cout<<"\nGlobal Alignment:\n";
    cout<<x<<endl;
    cout<<y<<endl;
    return dp[n][m];
}

int localAlignment(string s1,string s2,int match,int mismatch,int gap){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int maxscore=0;
    int endidx=0;
    int endjdx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int diag;
            if(s1[i-1]==s2[j-1]){
                diag=dp[i-1][j-1]+match;
            }
            else{
                diag=dp[i-1][j-1]+mismatch;
            }
            int up=dp[i-1][j]+gap;
            int left=dp[i][j-1]+gap;
            dp[i][j]=max(0,max(diag,max(left,up)));
            if(dp[i][j]>maxscore){
                maxscore=dp[i][j];
                endidx=i;
                endjdx=j;
            }
        }
    }
    string x="";
    string y="";
    int i=endidx,j=endjdx;
    while(i>0 && j>0 && dp[i][j]>0){
        if(s1[i-1]==s2[j-1] && dp[i][j]==dp[i-1][j-1]+match){
            x+=s1[i-1];
            y+=s2[j-1];
            i--;
            j--;
        }
        else if(s1[i-1]!=s2[j-1] && dp[i][j]==dp[i-1][j-1]+mismatch){
            x+=s1[i-1];
            y+=s2[j-1];
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]+gap){
            y+='-';
            x+=s1[i-1];
            i--;
        }
        else if(dp[i][j]==dp[i][j-1]+gap){
            x+='-';
            y+=s2[j-1];
            j--;
        }
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    cout<<"\nLocal Alignment:\n";
    cout<<x<<endl;
    cout<<y<<endl;    
    return maxscore;
}



int main() {
    //FAST_IO;
    string s1;
    cout<<"Enter first sequence: ";
    cin>>s1;
    string s2;
    cout<<"Enter second sequence: ";
    cin>>s2;
    int match,mismatch,gap;
    cout<<"Enter match score: ";
    cin>>match;
    cout<<"Enter mismatch penalty: ";
    cin>>mismatch;
    cout<<"Enter gap penalty: ";
    cin>>gap;
    int ans1=globalAlignment(s1,s2,match,mismatch,gap);
    cout<<"\nMaximum Score: "<<ans1<<endl;
    int ans2=localAlignment(s1,s2,match,mismatch,gap);
    cout<<"\nMaximum Score: "<<ans2<<endl;
    return 0;
}