#include <iostream>
#include <fstream>
#include <string>
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
        return 1;
    }

    BST<string, int> *bst1 = new ListBST<string, int>();
    if (!bst1) {
        cerr << "Memory allocation failed\n";
        return 2;
    }
    BST<string, int> *bst2 = new ListBST<string, int>();
    if (!bst2) {
        cerr << "Memory allocation failed\n";
        delete bst1; // Clean up previously allocated memory
        return 3;
    }

    int n;
    in_file >> n;
    for (int i = 0; i < n; ++i) {
        // TODO: Implement the logic to read Phil's words
        // Start your code here
        string str;
        in_file>>str;

        try{
            if(bst1->find(str)){
                int temp=bst1->get(str);
                bst1->update(str,temp+1);
            }
            else{
                bst1->insert(str,1);
            }
        }
        catch(const runtime_error &e){
            cerr<<"Error: "<<e.what()<<endl;
        }
        // End your code here
    }
    for (int i = 0; i < n; ++i) {
        // TODO: Implement the logic to read Claire's words
        // Start your code here
        string str;
        in_file>>str;
        try{
            if(bst2->find(str)){
                int temp=bst2->get(str);
                bst2->update(str,temp+1);
            }
            else{
                bst2->insert(str,1);
            }
        }
        catch(const runtime_error &e){
            cerr<<"Error: "<<e.what()<<endl;
        }
        // End your code here
    }

    // TODO: Implement the logic to print the initial state of both hands
    // Start your code here
    cout<<"Phil's words:\n";
    try{
        bst1->print('I');
    }
    catch(const invalid_argument &e){
        cerr<<"Error: "<<e.what()<<endl;
    }
    cout<<"\n";
    cout<<"Claire's words:\n";
    try{
        bst2->print('I');
    }
    catch(const invalid_argument &e){
        cerr<<"Error: "<<e.what()<<endl;
    }
    // End your code here
    cout << "\nGame starts!\n\n";
    cout << "==============================\n";

    while (true) {
        string word;
        in_file >> word;
        
        // TODO: Implement the logic to process the game turn and print both hands after each turn
        // Start your code here
        if(bst1->find(word)){
            cout<<"Phil has "<<word<<"!\n";
            try{
                int temp=bst1->get(word);
                if(temp==1){
                    bst1->remove(word);
                }
                else{
                    bst1->update(word,temp-1);
                }
            }
            catch(const runtime_error &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
        }
        if(bst2->find(word)){
            cout<<"Claire has "<<word<<"!\n";
            try{
                int temp=bst2->get(word);
                if(temp==1){
                    bst2->remove(word);
                }
                else{
                    bst2->update(word,temp-1);
                }
            }
            catch(const runtime_error &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
        }

        if(bst1->empty() && bst2->empty()){
            cout<<"It's a tie\n";
            break;
        }
        else if(bst1->empty()){
            cout<<"Phil wins!\n";
            break;
        }
        else if(bst2->empty()){
            cout<<"Claire wins!\n";
            break;
        }
        else{
            cout<<"\nPhil's remaining words:\n";
            try{
                bst1->print('I');
            }
            catch(const invalid_argument &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
            cout<<"\n";
            cout<<"Claire's remaining words:\n";
            try{
                bst2->print('I');
            }
            catch(const invalid_argument &e){
                cerr<<"Error: "<<e.what()<<endl;
            }
            cout<<"\n";
        }

        // End your code here
        cout << "==============================\n";
    }

    in_file.close();
    delete bst1;
    delete bst2;
    return 0;
}