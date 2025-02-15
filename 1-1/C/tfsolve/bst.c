#include<stdio.h>
int* start;
int BST_height(int* node,int x){
    if(*node==x)
        return 1;
    if(*node==-1){
        return -1;
    }
    int idx=start-node;
    if(*node>x)
        return 1+BST_height(node+2*idx,x);
    if(*node<x)
        return 1+BST_height(node+2*idx+1,x);
}
void BST_insert(int* node,int x){
    int idx=start-node;
    if(*node==-1){
        
    }

}
int main(){

}