#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

enum Color {RED, BLACK};

template<typename T>
class Node{
public:
    T key;
    Color color;
    int size;
    Node* left;
    Node* right;
    Node* parent;
    Node(T k){
        key=k;
        color=RED;
        size=1;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }
};


template<typename T>
class RBT{
    Node<T>* root;
    Node<T>* blackDummyLeaf;

    void updateSize(Node<T>* x){
        if(x!=blackDummyLeaf){
            x->size=1+x->left->size+x->right->size;
        }
    }

    void leftRotate(Node<T>* x){
        Node<T>* y=x->right;
        x->right=y->left;
        if(y->left!=blackDummyLeaf){
            y->left->parent=x;
        }
        y->parent=x->parent;
        if(x->parent==nullptr){
            root=y;
        }
        else if(x==x->parent->left){
            x->parent->left=y;
        }
        else{
            x->parent->right=y;
        }
        y->left=x;
        x->parent=y;
        updateSize(x);
        updateSize(y);
    }

    void rightRotate(Node<T>* y){
        Node<T>* x=y->left;
        y->left=x->right;
        if(x->right!=blackDummyLeaf){
            x->right->parent=y;
        }
        x->parent=y->parent;
        if(y->parent==nullptr){
            root=x;
        }
        else if(y==y->parent->left){
            y->parent->left=x;
        }
        else{
            y->parent->right=x;
        }
        x->right=y;
        y->parent=x;
        updateSize(y);
        updateSize(x);
    }

    void fixInsert(Node<T>* k){
        while(k->parent && k->parent->color==RED){
            if(k->parent==k->parent->parent->right){
                Node<T>* u=k->parent->parent->left;
                if(u->color==RED){
                    u->color=BLACK;
                    k->parent->color=BLACK;
                    k->parent->parent->color=RED;
                    k=k->parent->parent;
                }
                else{
                    if(k==k->parent->left){
                        k=k->parent;
                        rightRotate(k);
                    }
                    k->parent->color=BLACK;
                    k->parent->parent->color=RED;
                    leftRotate(k->parent->parent);
                }
            }
            else{
                Node<T>* u=k->parent->parent->right;
                if(u->color==RED){
                    u->color=BLACK;
                    k->parent->color=BLACK;
                    k->parent->parent->color=RED;
                    k=k->parent->parent;
                }
                else{
                    if(k==k->parent->right){
                        k=k->parent;
                        leftRotate(k);
                    }
                    k->parent->color=BLACK;
                    k->parent->parent->color=RED;
                    rightRotate(k->parent->parent);
                }
            }
            if(k==root){
                break;
            }
        }
        root->color=BLACK;
    }

    void transplant(Node<T>* u,Node<T>* v){
        if(u->parent==nullptr){
            root=v;
        }
        else if(u==u->parent->left){
            u->parent->left=v;
        }
        else{
            u->parent->right=v;
        }
        v->parent=u->parent;
    }

    void fixDelete(Node<T>* x){
        while(x!=root && x->color==BLACK){
            if(x==x->parent->left){
                Node<T>* s=x->parent->right;
                if(s->color==RED){
                    s->color=BLACK;
                    x->parent->color=RED;
                    leftRotate(x->parent);
                    s=x->parent->right;
                }
                if(s->left->color==BLACK && s->right->color==BLACK){
                    s->color=RED;
                    x=x->parent;
                }
                else{
                    if(s->right->color==BLACK){
                        s->left->color=BLACK;
                        s->color=RED;
                        rightRotate(s);
                        s=x->parent->right;
                    }
                    s->color=x->parent->color;
                    x->parent->color=BLACK;
                    s->right->color=BLACK;
                    leftRotate(x->parent);
                    x=root;
                }
            }
            else{
                Node<T>* s=x->parent->left;
                if(s->color==RED){
                    s->color=BLACK;
                    x->parent->color=RED;
                    rightRotate(x->parent);
                    s=x->parent->left;
                }
                if(s->right->color==BLACK && s->left->color==BLACK){
                    s->color=RED;
                    x=x->parent;
                }
                else{
                    if(s->left->color==BLACK){
                        s->right->color=BLACK;
                        s->color=RED;
                        leftRotate(s);
                        s=x->parent->left;
                    }
                    s->color=x->parent->color;
                    x->parent->color=BLACK;
                    s->left->color=BLACK;
                    rightRotate(x->parent);
                    x=root;
                }
            }
        }
        x->color=BLACK;
    }

public:
    RBT(){
        blackDummyLeaf=new Node<T>(0);
        blackDummyLeaf->color=BLACK;
        blackDummyLeaf->size=0;
        root=blackDummyLeaf;
    }

    int insert(T key){
        if(search(key)){
            return 0;
        }
        Node<T>* node=new Node<T>(key);
        node->left=blackDummyLeaf;
        node->right=blackDummyLeaf;
        Node<T>* y=nullptr;
        Node<T>* x=root;
        while(x!=blackDummyLeaf){
            y=x;
            x->size++;
            if(node->key<x->key){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        node->parent=y;
        if(y==nullptr){
            root=node;
        }
        else if(node->key<y->key){
            y->left=node;
        }
        else{
            y->right=node;
        }
        fixInsert(node);
        return 1;
    }

    int search(T k){
        Node<T>* x=root;
        while(x!=blackDummyLeaf){
            if(k==x->key){
                return 1;
            }
            if(k<x->key){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        return 0;
    }

    int remove(T key){
        Node<T>* z=root;
        while(z!=blackDummyLeaf && z->key!=key){
            if(key<z->key){
                z=z->left;
            }
            else{
                z=z->right;
            }
        }
        if(z==blackDummyLeaf){
            return 0;
        }

        Node<T>* temp=root;
        while(temp!=z){
            temp->size--;
            if(key<temp->key){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }

        Node<T> *x,*y;
        y=z;
        Color og=y->color;
        if(z->left==blackDummyLeaf){
            x=z->right;
            transplant(z,z->right);
        }
        else if(z->right==blackDummyLeaf){
            x=z->left;
            transplant(z,z->left);
        }
        else{
            y=z->right;
            while(y->left!=blackDummyLeaf){
                y=y->left;
            }
            og=y->color;
            x=y->right;
            Node<T>*path=z->right;
            while(path!=y){
                path->size--;
                path=path->left;
            }
            if(y->parent==z){
                x->parent=y;
            }
            else{
                transplant(y,y->right);
                y->right=z->right;
                y->right->parent=y;
            }
            transplant(z,y);
            y->left=z->left;
            y->left->parent=y;
            y->color=z->color;
            updateSize(y);
        }
        delete z;
        if(og==BLACK){
            fixDelete(x);
        }
        return 1;
    }

    int countLess(T k){
        int count=0;
        Node<T>* x=root;
        while(x!=blackDummyLeaf){
            if(k>x->key){
                count+=(x->left->size+1);
                x=x->right;
            }
            else{
                x=x->left;
            }
        }
        return count;
    }

};



int main() {
    FAST_IO;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;
    fout<<N<<endl;
    RBT<int>rbt;
    for(int i=0;i<N;i++){
        int e,x;
        fin>>e>>x;
        int res=0;
        if(e==0) res=rbt.remove(x);
        else if(e==1) res=rbt.insert(x);
        else if(e==2) res=rbt.search(x);
        else if(e==3) res=rbt.countLess(x);
        fout<<e<<" "<<x<<" "<<res<<endl;
    }
    return 0;
}