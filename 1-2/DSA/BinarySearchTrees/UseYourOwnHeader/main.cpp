#include"listBST.hpp"

using namespace std;

int main(){
    BST<int,int>* bst=new ListBST<int,int>();
    int arr[]={11,6,13,5,7,12,14,1,2,20,9,4,22};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        int val=arr[i];
    if(bst->insert(val,val)){
                cout<<"Key "<<val<<" inserted into BST, ";
            }
            else{
                cout<<"Insertion failed! Key "<<val<<" already exists in BST, ";
            }
            try{
                bst->print();
            }
            catch(const invalid_argument &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
    }

    bst->print('I');
    bst->print('D');
    cout<<"LCA: "<<bst->LCA(7,14)<<endl;
    cout<<bst->height()<<endl;

    bst->kthlevel(1);
    bst->kthlevel(2);
    cout<<bst->mindist(4,22)<<endl;
    bst->findpath(4);
    cout<<bst->getSuccessor(20)<<endl;
    cout<<bst->getPredecessor(9);
}