#include <iostream>
#include <fstream>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst) {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c) {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here
        if(c=='F'){
            in_file>>val;
            if(bst->find(val)){
                cout<<"Key "<<val<<" found in BST.\n";
            }
            else{
                cout<<"Key "<<val<<" not found in BST.\n";
            }
        }
        else if(c=='E'){
            if(bst->empty())
                cout<<"Empty\n";
            else
                cout<<"Not Empty\n";
        }
        else if(c=='I'){
            in_file>>val;
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
        else if(c=='M'){
            in_file>>str;
            try{
                if(str[0]=='M' && str[1]=='i' && str[2]=='n'){
                    cout<<"Minimum value: "<<bst->find_min()<<"\n";
                }
                else if(str[0]=='M' && str[1]=='a' && str[2]=='x'){
                    cout<<"Maximum value: "<<bst->find_max()<<"\n";
                }
                else{
                    throw runtime_error("Not a valid command");
                }
            }
            catch(const runtime_error &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
        }
        else if(c=='D'){
            in_file>>val;
            if(bst->remove(val)){
                cout<<"Key "<<val<<" removed from BST, ";
            }
            else{
                cout<<"Removal failed! Key "<<val<<" not found in BST, ";
            }
            try{
                bst->print();
            }
            catch(const invalid_argument &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
        }
        else if(c=='S'){
            cout<<"Size: "<<bst->size()<<"\n";
        }
        else if(c=='T'){
            in_file>>str;
            try{
                if(str[0]=='I' && str[1]=='n'){
                    bst->print('I');
                }
                else if(str[0]=='P' && str[1]=='r' && str[2]=='e'){
                    bst->print('P');
                }
                else if(str[0]=='P' && str[1]=='o' && str[2]=='s' && str[3]=='t'){
                    bst->print('O');
                }
                else{
                    throw invalid_argument("Not a valid traversal");
                }
            }
            catch(const invalid_argument &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
        }
        // End your code here
    }
    in_file.close();
    delete bst;
    return 0;
}
