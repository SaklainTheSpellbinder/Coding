#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

static int idx=-1;
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode=new Node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);
    return currNode;
}



void preorder(Node* root){//O(n)
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){//O(n)
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){//O(n)
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){//O(n)
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(q.empty())
                break;
            q.push(NULL);
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

int height(Node* root){   //O(n)
    if (root == NULL){
        return -1;
    }
    // if(root->left==NULL && root->right==NULL){
    //     return 0;                  lagbe na eta
    // }
    int heightleft=height(root->left);
    int heightright=height(root->right);
    return 1+max(heightleft,heightright);
}

int nodecount(Node* root){
    if(root==NULL)
        return 0;
    int leftnodes=nodecount(root->left);
    int rightnodes=nodecount(root->right);
    return 1+leftnodes+rightnodes;
}

int sumofnodes(Node* root){
    if(root==NULL)
        return 0;
    int leftsum=sumofnodes(root->left);
    int rightsum=sumofnodes(root->right);
    return root->data+leftsum+rightsum;
}

bool findpath(Node* root,int n,vector<int>&path){
    if(root==NULL)
        return false;
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    bool isleft=findpath(root->left,n,path);
    bool isright=findpath(root->right,n,path);
    if(isleft||isright)
        return true;
    path.pop_back();
    return false;
}

int LCA(Node* root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;
    
    findpath(root,n1,path1);
    findpath(root,n2,path2);
    int common=-1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i]==path2[j])
            common=path1[i];
    }
    return common;
}

Node* LCA2(Node* root,int n1,int n2){
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftlca=LCA2(root->left,n1,n2);
    Node* rightlca=LCA2(root->right,n1,n2);
    if(leftlca!=NULL && rightlca!=NULL){
        return root;
    }
    return (leftlca==NULL)?rightlca:leftlca;
}

int dist(Node* root,int n){
    if(root==NULL)
        return -1;
    if(root->data==n)
        return 0;
    
    int leftdist=dist(root->left,n);
    if(leftdist!=-1)
        return leftdist+1;
    
    int rightdist=dist(root->right,n);
    if(rightdist!=-1)
        return rightdist+1;
    
    return -1;
}

int minDist(Node* root,int n1,int n2){ //O(n)
    Node* lca=LCA2(root,n1,n2);

    int dist1=dist(lca,n1);
    int dist2=dist(lca,n2);

    return dist1+dist2;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    // levelorder(root);
    // cout<<height(root)<<endl;
    // cout<<nodecount(root)<<endl;
    // cout<<sumofnodes(root)<<endl;
    //cout<<LCA2(root,4,6)->data;
    cout<<minDist(root,3,5);
    cout<<endl;
} 