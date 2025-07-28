#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Binary Search Tree implementation using linked list structure
 * 
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value> {
private:
    /**
     * Node class for the binary search tree
     */
    class Node {
    public:
        Key key;
        Value value;
        Node* left;
        Node* right;
        
        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    size_t node_count;
    
    // TODO: Implement private helper functions as needed
    // Start your private helper functions here

    bool insertHelper(Node* &root,Key key,Value value){
        if(!root){
            root=new Node(key,value);
            node_count++;
            return true;
        }
        if(key<root->key){
            return insertHelper(root->left,key,value);
        }
        else if(key>root->key){
            return insertHelper(root->right,key,value);
        }
        else{
            return false;
        }
    }

    bool removeHelper(Node* &root,Key key){
        if(!root){
            return false;
        }
        if(key<root->key){
            return removeHelper(root->left,key);
        }
        else if(key>root->key){
            return removeHelper(root->right,key);
        }
        else{
            if(!root->left && !root->right){
                delete root;
                root=NULL;
                node_count--;
            }
            else if(!root->left){
                Node* temp=root;
                root=root->right;
                delete temp;
                node_count--;
            }
            else if(!root->right){
                Node* temp=root;
                root=root->left;
                delete temp;
                node_count--;
            }
            else{
                Node* minParent=root;
                Node* minNode=root->right;
                while(minNode->left){
                    minParent=minNode;
                    minNode=minNode->left;
                }
                root->key=minNode->key;
                root->value=minNode->value;
                if(minParent==root){
                    minParent->right=minNode->right;
                }
                else{
                    minParent->left=minNode->right;
                }
                delete minNode;
                node_count--;
            }
            return true;
        }
    }

    bool findHelper(Node* root,Key key) const{
        if(!root){
            return false;
        }
        if(key==root->key){
            return true;
        }
        else if(key<root->key){
            return findHelper(root->left,key);
        }
        else{
            return findHelper(root->right,key);
        }
    }
    
    Value getHelper(Node* root,Key key) const{
        if(!root){
            throw std::runtime_error("Key is not found.");
        }
        if(key==root->key){
            return root->value;
        }
        else if(key<root->key){
            return getHelper(root->left,key);
        }
        else{
            return getHelper(root->right,key);
        }
    }

    void updateHelper(Node* &root,Key key,Value value){
        if(!root){
            throw std::runtime_error("Key is not found.");
        }
        if(key==root->key){
            root->value=value;
            return;
        }
        else if(key<root->key){
            updateHelper(root->left,key,value);
        }
        else{
            updateHelper(root->right,key,value);
        }
    }

    void cleanHelper(Node* &root){
        if(!root)
            return;
        cleanHelper(root->left);
        cleanHelper(root->right);
        delete root;
        root=NULL;
    }

    void preorder(Node* root) const{
        if(!root){
            return;
        }
        std::cout<<"("<<root->key<<":"<<root->value<<") ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) const{
        if(!root){
            return;
        }
        inorder(root->left);
        std::cout<<"("<<root->key<<":"<<root->value<<") ";
        inorder(root->right);
    }

    void postorder(Node* root) const{
        if(!root){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        std::cout<<"("<<root->key<<":"<<root->value<<") ";
    }

    void defaultprint(Node* root) const{
        if(!root){
            return;
        }
        std::cout<<" ("<<root->key<<":"<<root->value;
        if(!root->left && !root->right){
            std::cout<<")";
            return;
        }
        else if(!root->left){
            std::cout<<" ()";
            defaultprint(root->right);
        }
        else{
            defaultprint(root->left);
            defaultprint(root->right);
        }
        std::cout<<")";
    }

    Node* LCAhelper(Node* root,Key x,Key y){
        if(root==NULL){
            return root;
        }
        if(root->key==x || root->key==y){
            return root;
        }
        Node* leftlca=LCAhelper(root->left,x,y);
        Node* rightlca=LCAhelper(root->right,x,y);
        if(leftlca!=NULL && rightlca!=NULL){
            return root;
        }
        return (leftlca==NULL)?rightlca:leftlca;
    }

    int max(int x,int y){
        return (x>y)?x:y;
    }

    int heighthelper(Node* root){
        if(root==NULL){
            return -1;
        }
        int leftheight=heighthelper(root->left);
        int rightheight=heighthelper(root->right);
        return 1+max(leftheight,rightheight);
    }

    void kthlevelhelper(Node* root,int k,int currlevel){
        if(root==NULL){
            return;
        }
        if(currlevel==k){
            std::cout<<root->key<<" ";
        }
        kthlevelhelper(root->left,k,currlevel+1);
        kthlevelhelper(root->right,k,currlevel+1);
    }


    void findpathhelper(Node* root,Key x){
        if(root==NULL){
            cout<<"Not found";
            return;
        }
        if(root->key==x){
            cout<<x<<endl;
            return;
        }
        if(root->key>x){
            cout<<root->key<<" ";
            findpathhelper(root->left,x);
        }
        if(root->key<x){
            cout<<root->key<<" ";
            findpathhelper(root->right,x);
        }
    }

    int dist(Node* root,Key x){
        if(root==NULL){
            return -1;
        }
        if(root->key==x){
            cout<<x<<" reached"<<endl;
            return 0;
        }
        
        if(root->key>x){
            cout<<root->left->key<<" called"<<endl;
            int leftdist=dist(root->left,x);
            
            return leftdist+1;
        }
        
        if(root->key<x){
            cout<<root->right->key<<" called"<<endl;
            int rightdist=dist(root->right,x);
            return rightdist+1;
        }
        return -1;
    }

    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}
    
    /**
     * Destructor
     */
    ~ListBST() {
        // TODO: Implement destructor to free memory
        clear();
    }
    
    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override {
        // TODO: Implement insertion logic
        return insertHelper(root,key,value);
    }
    
    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override {
        // TODO: Implement removal logic
        return removeHelper(root,key);
    }
    
    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override {
        // TODO: Implement find logic
        return findHelper(root,key);
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override {
        // TODO: Implement get logic
        return getHelper(root,key);
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override {
        // TODO: Implement update logic
        updateHelper(root,key,value);
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override {
        // TODO: Implement clear logic
        cleanHelper(root);
        root=NULL;
        node_count=0;
    }
    
    /**
     * Get the number of keys in the BST
     */
    size_t size() const override {
        // TODO: Implement size logic
        return node_count;
    }
    
    /**
     * Check if the BST is empty
     */
    bool empty() const override {
        // TODO: Implement empty check logic
        return root==NULL;
    }
    
    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override {
        // TODO: Implement find_min logic
        if(!root){
            throw std::runtime_error("Tree is empty. So no minimum.");
        }
        Node* current=root;
        while(current->left){
            current=current->left;
        }
        return current->key;
    }
    
    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override {
        // TODO: Implement find_max logic
        if(!root){
            throw std::runtime_error("Tree is empty. So, no maximum.");
        }
        Node* current=root;
        while(current->right){
            current=current->right;
        }
        return current->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override {
        // TODO: Implement print logic
        if(traversal_type=='D' || traversal_type=='d'){
            std::cout<<"BST (Default):";
            defaultprint(root);
        }
        else if(traversal_type=='I' || traversal_type=='i'){
            std::cout<<"BST (In-order): ";
            inorder(root);
        }
        else if(traversal_type=='P' || traversal_type=='p'){
            std::cout<<"BST (Pre-order): ";
            preorder(root);
        }
        else if(traversal_type=='O' || traversal_type=='o'){
            std::cout<<"BST (Post-order): ";
            postorder(root);
        }
        else{
            throw std::invalid_argument("Not a valid argument to print");
        }
        std::cout<<"\n";
    }

    Key LCA(Key x,Key y){
        return LCAhelper(root,x,y)->key;
    }

    int height(){
        return heighthelper(root);
    }

    void kthlevel(int k){
        kthlevelhelper(root,k,0);
        std::cout<<endl;
        return;
    }

    int mindist(Key x,Key y){
        Node* lca=LCAhelper(root,x,y);
        cout<<"LCA: "<<lca->key<<endl;
        int leftdist=dist(lca,x);
        cout<<"Left: "<<leftdist<<endl;
        int rightdist=dist(lca,y);
        cout<<"Right: "<<rightdist<<endl;
        return leftdist+rightdist;
    }

    void findpath(Key x){
        findpathhelper(root,x);
    }

    Key getSuccessor(Key x){
        Node* succ=nullptr;
        Node* curr=root;
        while(curr){
            if(x<curr->key){
                succ=curr;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return succ->key;
    }

    Key getPredecessor(Key x){
        Node* succ=nullptr;
        Node* curr=root;
        while(curr){
            if(x>curr->key){
                succ=curr;
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        return succ->key;
    }
    
};

#endif // LISTBST_H