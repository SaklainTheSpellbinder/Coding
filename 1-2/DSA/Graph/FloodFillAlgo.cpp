#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    public:
        void dfs(vector<vector<bool>>&vis,vector<vector<int>>& image,int newcolor,int oldcolor,int row,int col,int n,int m){
            vis[row][col]=true;
            image[row][col]=newcolor;

            if(row-1>=0 && !vis[row-1][col] && image[row-1][col]==oldcolor){
                dfs(vis,image,newcolor,oldcolor,row-1,col,n,m);
            }
            if(row+1<n && !vis[row+1][col] && image[row+1][col]==oldcolor){
                dfs(vis,image,newcolor,oldcolor,row+1,col,n,m);
            } 
            if(col-1>=0 && !vis[row][col-1] && image[row][col-1]==oldcolor){
                dfs(vis,image,newcolor,oldcolor,row,col-1,n,m);
            } 
            if(col+1<m && !vis[row][col+1] && image[row][col+1]==oldcolor){
                dfs(vis,image,newcolor,oldcolor,row,col+1,n,m);
            } 
        }

        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int n=image.size();
            int m=image[0].size();
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            dfs(vis,image,color,image[sr][sc],sr,sc,n,m);
            return image;
        }
};