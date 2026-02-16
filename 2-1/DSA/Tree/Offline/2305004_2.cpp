#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

template<typename T>
class Node{
public:
    T key;
    Node* left;
    Node* right;
    int height;

    Node(T k){
        key=k;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};

template<typename T>
class AVL{
    Node<T>* root;

    int height(Node<T>* N){
        return (N==nullptr)?0:N->height;
    }

    int getBalance(Node<T>* N){
        return (N==nullptr)?0:height(N->left)-height(N->right);
    }

    Node<T>* rightRotate(Node<T>* y){
        Node<T>* x=y->left;
        Node<T>* T2=x->right;
        x->right=y;
        y->left=T2;
        y->height=max(height(y->left),height(y->right))+1;
        x->height=max(height(x->left),height(x->right))+1;
        return x;
    }

    Node<T>* leftRotate(Node<T>* x){
        Node<T>* y=x->right;
        Node<T>* T2=y->left;
        y->left=x;
        x->right=T2;
        x->height=max(height(x->left),height(x->right))+1;
        y->height=max(height(y->left),height(y->right))+1;
        return y;
    }

    Node<T>* insertNode(Node<T>* node,T key, bool& success){
        if(node==nullptr){
            success=true;
            return new Node<T>(key);
        }

        if(key<node->key){
            node->left=insertNode(node->left,key,success);
        }
        else if(key>node->key){
            node->right=insertNode(node->right,key,success);
        }
        else{
            success=false;
            return node;
        }
        node->height=1+max(height(node->left),height(node->right));
        int balance=getBalance(node);

        if(balance>1 && key<node->left->key){
            return rightRotate(node);
        }
        if(balance<-1 && key>node->right->key){
            return leftRotate(node);
        }
        if(balance>1 && key>node->left->key){
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance<-1 && key<node->right->key){
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node<T>* minValueNode(Node<T>* node){
        Node<T>* curr=node;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        return curr;
    }

    Node<T>* deleteNode(Node<T>* root,T key,bool& success){
        if(root==nullptr){
            success=false;
            return root;
        }
        if(key<root->key){
            root->left=deleteNode(root->left,key,success);
        }
        else if(key>root->key){
            root->right=deleteNode(root->right,key,success);
        }
        else{
            success=true;
            if((root->left==nullptr)||(root->right==nullptr)){
                Node<T>* temp=root->left?root->left:root->right;
                if(temp==nullptr){
                    temp=root;
                    root=nullptr;
                }
                else{
                    *root=*temp;
                }
                delete temp;
            }
            else{
                Node<T>* temp=minValueNode(root->right);
                root->key=temp->key;
                root->right=deleteNode(root->right,temp->key,success);
            }
        }

        if(root==nullptr) 
            return root;
        root->height=1+max(height(root->left),height(root->right));
        int balance=getBalance(root);

        if(balance>1 && getBalance(root->left)>=0){
            return rightRotate(root);
        }
        if(balance>1 && getBalance(root->left)<0){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance<-1 && getBalance(root->right)<=0){
            return leftRotate(root);
        }
        if(balance<-1 && getBalance(root->right)>0){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    void preOrder(Node<T>* root,ofstream &fout){
        if(root!=nullptr){
            fout<<root->key<<" ";
            preOrder(root->left,fout);
            preOrder(root->right,fout);
        }
    }

    void inOrder(Node<T>* root,ofstream &fout) {
        if(root!=nullptr){
            inOrder(root->left,fout);
            fout<<root->key<<" ";
            inOrder(root->right,fout);
        }
    }

    void postOrder(Node<T>* root,ofstream &fout) {
        if(root!=nullptr){
            postOrder(root->left,fout);
            postOrder(root->right,fout);
            fout<<root->key<<" ";
        }
    }

    void levelOrder(Node<T>* root,ofstream &fout){
        if(root == nullptr) 
            return;
        queue<Node<T>*>q;
        q.push(root);
        while(!q.empty()){
            Node<T>* node=q.front();
            fout<<node->key<<" ";
            q.pop();
            if(node->left != nullptr) 
                q.push(node->left);
            if(node->right != nullptr) 
                q.push(node->right);
        }
    }
public:
    AVL(){
        root=nullptr;
    }

    int insert(T key){
        bool success=false;
        root=insertNode(root,key,success);
        return success?1:0;
    }

    int remove(T key){
        bool success=false;
        root=deleteNode(root,key,success);
        return success?1:0;
    }

    void traverse(int type,ofstream& fout){
        if(type==1){
            preOrder(root,fout);
        }
        else if(type==2){
            inOrder(root,fout);
        }
        else if(type==3){
            postOrder(root,fout);
        }
        else if(type==4){
            levelOrder(root,fout);
        }
        fout<<endl;
    }
};

int main() {
    FAST_IO;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin>>N;
    fout<<N<<endl;
    AVL<int>avl;
    for (int i=0;i<N;i++) {
        int e,x;
        fin>>e>>x;
        if(e==0)
            fout<<e<<" "<<x<<" "<<avl.remove(x)<<endl;
        else if(e==1)
            fout<<e<<" "<<x<<" "<<avl.insert(x)<<endl;
        else if(e==2)
            avl.traverse(x, fout);
    }
    return 0;
}