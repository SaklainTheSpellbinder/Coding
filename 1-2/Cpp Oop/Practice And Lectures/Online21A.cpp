#include<iostream>
#include<string>
using namespace std;

class Book{
    string title;
    string author;
    bool available;
public:
    Book(){
        title="NULL";
        author="NULL";
        available=false;
    }    

    Book(string title,string author,bool available){
        this->title=title;
        this->author=author;
        this->available=available;
    }

    ~Book(){
        //mara khao
    }

    void setTtile(string title){
        this->title=title;
    }

    void setAuthor(string author){
        this->author=author;
    }

    void setAvailability(bool available){
        this->available=available;
    }

    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }

    bool getavailability(){
        return available;
    }

    void displayBook(){
        cout<<"\tTitle: "<<getTitle()<<endl;
        cout<<"\tAuthor: "<<getAuthor()<<endl;
        cout<<"\tAvailability: ";
        if(available){
            cout<<"Available"<<endl;
        }
        else{
            cout<<"Not Available"<<endl;
        }
    }
};

class LibraryMember{
    string name;
    int libraryCard;
public:
    LibraryMember(){

    }

    LibraryMember(string name,int libraryCard){
        this->name=name;
        this->libraryCard=libraryCard;
    }

    ~LibraryMember(){

    }

    void setName(string name){
        this->name=name;
    }

    void setLibraryCard(int libraryCard){
        this->libraryCard=libraryCard;
    }

    string getName(){
        return name;
    }

    int getID(){
        return libraryCard;
    }

    void displayMember(){
        cout<<"\tName: "<<getName()<<endl;
        cout<<"\tLibrary Card Number: "<<getID()<<endl;
    }
};

class Library{
    Book* books;
    LibraryMember* members;
    int bookssize;
    int memberssize;
public:
    Library(){
        books=new Book[100];
        members=new LibraryMember[100];
        bookssize=0;
        memberssize=0;
    }

    ~Library(){
        delete[] books;
        delete[] members;
    }

    void addBook(string title,string author){
        books[bookssize].setTtile(title);
        books[bookssize].setAuthor(author);
        books[bookssize].setAvailability(true);
        bookssize++;
    }

    void registerMember(string name,int number){
        members[memberssize].setName(name);
        members[memberssize].setLibraryCard(number);
        memberssize++;
    }

    void borrowBook(string title,int number){
        int j=0;
        while(j<bookssize){
            if(books[j].getTitle()==title){
                cout<<"Book \'"<<title<<"\' has been borrowed by"<<endl;
                books[j].setAvailability(false);
                break;
            }
            j++;
        }
        for(int i=0;i<memberssize;i++){
            if(members[i].getID()==number){
                members[i].displayMember();
                cout<<endl;
                break;
            }
        }
    }

    void returnBook(string title,int number){
        int j=0;
        while(j<bookssize){
            if(books[j].getTitle()==title){
                cout<<"Book \'"<<title<<"\' has been returned by"<<endl;
                books[j].setAvailability(true);
                break;
            }
            j++;
        }
        for(int i=0;i<memberssize;i++){
            if(members[i].getID()==number){
                members[i].displayMember();
                cout<<endl;
                break;
            }
        }
    }

    void removeBook(string title){
        int j=0;
        while(j<bookssize){
            if(books[j].getTitle()==title){
                cout<<"Book \'"<<title<<"\' has been removed from the library."<<endl;
                cout<<endl;
                break;
            }
            j++;
        }
        for(int k=j;k<bookssize-1;k++){
            books[k]=books[k+1];
        }
        bookssize--;
    }

    void removeMember(int number){
        int j=0;
        while(j<memberssize){
            if(members[j].getID()==number){
                cout<<"Member \'"<<members[j].getName()<<" ("<<number<<")"<<"\' has been removed from the library."<<endl;
                cout<<endl;
                break;
            }
            j++;
        }
        for(int k=j;k<memberssize-1;k++){
            members[k]=members[k+1];
        }
        memberssize--;
    }

    void displayAllBooks(){
        cout<<"Books in the library:"<<endl;
        for(int i=0;i<bookssize;i++){
            books[i].displayBook();
            cout<<endl;
        }
    }

    void displayAllMembers(){
        cout<<"Members in the library:"<<endl;
        for(int i=0;i<memberssize;i++){
            members[i].displayMember();
            cout<<endl;
        }
    }
};

int main() {
    Library library;
    // Adding books
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("Pride and Prejudice", "Jane Austen");
    // Displaying all books
    library.displayAllBooks();
    // Registering members
    library.registerMember("John Doe", 1234);
    library.registerMember("Jane Smith", 5678);
    // Displaying all members
    library.displayAllMembers();
    // Borrowing books
    library.borrowBook("The Great Gatsby", 1234);
    library.borrowBook("To Kill a Mockingbird", 5678);
    // Displaying all books (after borrowing)
    library.displayAllBooks();
    // Returning a book
    library.returnBook("The Great Gatsby", 1234);
    // Displaying all books (after returning)
    library.displayAllBooks();
    // Removing a book
    library.removeBook("Pride and Prejudice");
    // Displaying all books (after removal)
    library.displayAllBooks();
    // Removing a member
    library.removeMember(5678);
    // Displaying all members (after removal)
    library.displayAllMembers();
    return 0;
}