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
        return 0;
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

int diam1(Node* root){//O(n^2)
    if(root==NULL){
        return 0;
    }
    int currdiam=height(root->left)+height(root->right)+1; //O(n)
    int leftdiam=diam1(root->left);
    int rightdiam=diam1(root->right);
    return max(currdiam,max(leftdiam,rightdiam));
}

pair<int,int> diam2(Node* root){
    if(root==NULL){
        return {0,0};
    }
    //diameter,height
    pair<int,int> lefty=diam2(root->left);
    pair<int,int> righty=diam2(root->right);
    int currdiam=lefty.second+righty.second+1;
    int leftdiam=lefty.first;
    int rightdiam=righty.first;
    int heighty=1+max(lefty.second,righty.second);
    return {max(currdiam,max(leftdiam,rightdiam)),heighty};
}



int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    levelorder(root);
    cout<<height(root)<<endl;
    // cout<<nodecount(root)<<endl;
    // cout<<sumofnodes(root)<<endl;
    // cout<<diam1(root)<<endl;
    cout<<diam2(root).first<<endl;
    
    cout<<endl;
}