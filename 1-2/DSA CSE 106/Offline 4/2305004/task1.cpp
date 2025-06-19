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
                std::cout<<"Key "<<val<<" found in BST.\n";
            }
            else{
                std::cout<<"Key "<<val<<" not found in BST.\n";
            }
        }
        else if(c=='E'){
            bst->clear();
            std::cout<<"Empty\n";
        }
        else if(c=='I'){
            in_file>>val;
            if(bst->insert(val,val)){
                std::cout<<"Key "<<val<<" inserted into BST, ";
            }
            else{
                std::cout<<"Insertion failed! Key "<<val<<" already exists in BST, ";
            }
            bst->print();
        }
        else if(c=='M'){
            string temp;
            in_file>>temp;
            if(temp=="Min"){
                std::cout<<"Minimum value: "<<bst->find_min()<<"\n";
            }
            else if(temp=="Max"){
                std::cout<<"Maximum value: "<<bst->find_max()<<"\n";
            }
        }
        else if(c=='D'){
            in_file>>val;
            if(bst->remove(val)){
                std::cout<<"Key "<<val<<" removed from BST, ";
            }
            else{
                std::cout<<"Removal failed! Key "<<val<<" not found in BST, ";
            }
            bst->print();
        }
        else if(c=='S'){
            std::cout<<"Size: "<<bst->size()<<"\n";
        }
        else if(c=='T'){
            string temp;
            in_file>>temp;
            if(temp=="In"){
                bst->print('I');
            }
            else if(temp=="Pre"){
                bst->print('P');
            }
            else if(temp=="Post"){
                bst->print('O');
            }
        }
        // End your code here
    }
    in_file.close();
    delete bst;
    return 0;
}
