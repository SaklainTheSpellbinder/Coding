#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

class WordGenerator{
    set<string>generatedWords;
public:
    WordGenerator(){
        srand(time(0));
    }

    string generateWord(int len){
        string a="";
        for(int i=0;i<len;i++){
            char c='a'+(rand()%26);
            a+=c;
        }
        return a;
    }

    string generateUniqueWord(int len){
        string a;
        do{
            a=generateWord(len);
        }while(generatedWords.find(a)!=generatedWords.end());
        generatedWords.insert(a);
        return a;
    }

    void reset(){
        generatedWords.clear();
    }
};

template<typename K,typename V>
class ChainNode{
public:
    K key;
    V value;
    ChainNode* next;

    ChainNode(K k, V v){
        key=k;
        value=v;
        next=nullptr;
    }
};

template<typename K,typename V>
class HashEntry{
public:
    K key;
    V value;
    bool isOccupied;
    bool isDeleted;

    HashEntry(){
        isOccupied=false;
        isDeleted=false;
    }

    HashEntry(K k,V v){
        key=k;
        value=v;
        isOccupied=true;
        isDeleted=false;
    }
};

template<typename K,typename V>
class HashTable{
public:
    int tablesize;
    int total;
    int initsize;
    double load_factor;
    int insertcount;
    int deletecount;
    int lastsize;
    int collisioncount;

    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    int nextPrime(int n){
        if(n<=1){
            return 2;
        }
        int prime=n;
        while(!isPrime(prime)){
            prime++;
        }
        return prime;
    }

    int previousPrime(int n){
        if(n<=2){
            return 2;
        }
        int prime=n;
        while(!isPrime(prime)){
            prime--;
            if(prime<2){
                return 2;
            }
        }
        return prime;
    }

    HashTable(int init=13,double loadfactor=0.5){
        initsize=nextPrime(init);
        tablesize=initsize;
        load_factor=loadfactor;
        total=0;
        insertcount=0;
        deletecount=0;
        lastsize=0;
        collisioncount=0;
    }

    virtual ~HashTable(){}

    int hash1(const string& key){
        unsigned long hashvalue=0;
        int prime=31;
        for(char c:key){
            hashvalue=(hashvalue*prime+c)%tablesize;
        }
        return hashvalue;
    }

    int hash2(const string& key){
        unsigned long hashvalue=0;
        for(char c:key){
            hashvalue=c+(hashvalue<<6)+(hashvalue<<16)-hashvalue;
        }
        return (int)((hashvalue%tablesize+tablesize)%tablesize);
    }

    int auxHash(const string& key){
        unsigned long hashvalue=0;
        for(char c:key){
            hashvalue=hashvalue*29+c;
        }
        return (hashvalue%(tablesize-1))+1;
    }

    double loadfactor(){
        return (double)total/tablesize;
    }

    virtual void insert(const K& key,const V& value)=0;
    virtual bool search(const K& key,V& value,int& hits)=0;
    virtual bool remove(const K& key)=0;
};

template<typename K,typename V>
class Chaining: public HashTable<K,V>{
    ChainNode<K,V>** table;
    int choice;
    int getHash(const string& key){
        if(choice==1){
            return this->hash1(key);
        }
        else{
            return this->hash2(key);
        }
    }

    void rehash(int newSize){
        ChainNode<K,V>** oldtable=table;
        int oldsize=this->tablesize;
        this->tablesize=newSize;
        table=new ChainNode<K,V>*[this->tablesize];
        for(int i=0;i<this->tablesize;i++){
            table[i]=nullptr;
        }
        this->total=0;
        for(int i=0;i<oldsize;i++){
            ChainNode<K,V>*curr=oldtable[i];
            while(curr!=nullptr){
                ChainNode<K,V>*next=curr->next;
                int idx=getHash(curr->key);
                curr->next=table[idx];
                table[idx]=curr;
                this->total++;
                curr=next;
            }
        }
        delete[] oldtable;
        this->lastsize=this->total;
    }
public:
    Chaining(int choice=1,int initsize=13,double loadfactor=0.5):HashTable<K,V>(initsize,loadfactor){
        this->choice=choice;
        table=new ChainNode<K,V>*[this->tablesize];
        for(int i=0;i<this->tablesize;i++){
            table[i]=nullptr;
        }
    }

    ~Chaining(){
        for(int i=0;i<this->tablesize;i++){
            ChainNode<K,V>* curr=table[i];
            while(curr!=nullptr){
                ChainNode<K,V>* temp=curr;
                curr=curr->next;
                delete temp;
            }
        }
        delete[] table;
    }

    bool search(const K& key,V& value,int& hits) override{
        hits=0;
        int idx=getHash(key);
        ChainNode<K,V>* curr=table[idx];
        while(curr!=nullptr){
            hits++;
            if(curr->key==key){
                value=curr->value;
                return true;
            }
            curr=curr->next;
        }
        return false;
    }

    void insert(const K& key,const V& value) override{
        V temp;
        int hits;
        if(search(key,temp,hits)){
            return;
        }
        int idx=getHash(key);
        if(table[idx]!=nullptr){
            this->collisioncount++;
        }
        ChainNode<K,V>* newNode=new ChainNode<K,V>(key,value);
        newNode->next=table[idx];
        table[idx]=newNode;
        this->total++;
        this->insertcount++;
        if(this->loadfactor()>0.5 && this->insertcount>=this->lastsize/2){
            int newsize=this->nextPrime(2*this->tablesize);
            rehash(newsize);
            this->insertcount=0;
        }
    }

    bool remove(const K& key)override{
        int idx=getHash(key);
        ChainNode<K,V>* curr=table[idx];
        ChainNode<K,V>* prev=nullptr;
        while(curr!=nullptr){
            if(curr->key==key){
                if(prev==nullptr){
                    table[idx]=curr->next;
                }
                else{
                    prev->next=curr->next;
                }
                delete curr;
                this->total--;
                this->deletecount++;
                if(this->tablesize>this->initsize && this->loadfactor()<0.25 && this->deletecount>=this->lastsize/2){
                    int newSize=this->previousPrime(this->tablesize/2);
                    if(newSize>=this->initsize){
                        rehash(newSize);
                        this->deletecount=0;
                    }
                }
                return true;
            }
            prev=curr;
            curr=curr->next;
        }
        return false;
    }    
};

template<typename K,typename V>
class DoubleHashingTable:public HashTable<K,V>{
    HashEntry<K,V>*table;
    int choice;
    int getHash(const string& key){
        if(choice==1){
            return this->hash1(key);
        }
        else{
            return this->hash2(key);
        }
    }

    int doubleHash(const string& key,int i){
        return (getHash(key)+i*this->auxHash(key))%this->tablesize;
    }

    void rehash(int newSize){
        HashEntry<K,V>*oldtable=table;
        int oldsize=this->tablesize;
        this->tablesize=newSize;
        table=new HashEntry<K,V>[this->tablesize];
        this->total=0;
        for(int i=0;i<oldsize;i++){
            if(oldtable[i].isOccupied && !oldtable[i].isDeleted){
                int j=0;
                int idx;
                while(j<this->tablesize){
                    idx=doubleHash(oldtable[i].key,j);
                    if(!table[idx].isOccupied){
                        table[idx]=HashEntry<K,V>(oldtable[i].key,oldtable[i].value);
                        this->total++;
                        break;
                    }
                    j++;
                }
            }
        }
        delete[] oldtable;
        this->lastsize=this->total;
    }
public:
    DoubleHashingTable(int choice=1,int initsize=13,double loadfactor=0.5):HashTable<K,V>(initsize,loadfactor){
        this->choice=choice;
        table=new HashEntry<K,V>[this->tablesize];
    }
    ~DoubleHashingTable(){
        delete[] table;
    }

    bool search(const K& key,V& value,int& hits)override{
        hits=0;
        int i=0;
        int idx;
        while(i<this->tablesize){
            idx=doubleHash(key,i);
            hits++;
            if(!table[idx].isOccupied){
                return false;
            }
            if(table[idx].isOccupied && !table[idx].isDeleted && table[idx].key==key){
                value=table[idx].value;
                return true;
            }
            i++;
        }
        return false;
    }

    void insert(const K& key,const V& value)override{
        V temp;
        int hits;
        if(search(key,temp,hits)){
            return;
        }
        int i=0;
        int idx;
        while(i<this->tablesize){
            idx=doubleHash(key,i);
            if(!table[idx].isOccupied || table[idx].isDeleted){
                if(i>0){
                    this->collisioncount++;
                }
                table[idx]=HashEntry<K,V>(key,value);
                this->total++;
                this->insertcount++;
                if(this->loadfactor()>0.5 && this->insertcount>=this->lastsize/2){
                    int newSize=this->nextPrime(2*this->tablesize);
                    rehash(newSize);
                    this->insertcount=0;
                }
                return;
            }
            i++;
        }
    }

    bool remove(const K& key)override{
        int i=0;
        int idx;
        while(i<this->tablesize){
            idx=doubleHash(key,i);
            if(!table[idx].isOccupied){
                return false;
            }
            if(table[idx].isOccupied && !table[idx].isDeleted &&table[idx].key==key){
                table[idx].isDeleted=true;
                this->total--;
                this->deletecount++;
                if(this->tablesize>this->initsize && this->loadfactor()<0.25 && this->deletecount>=this->lastsize/2){
                    int newSize=this->previousPrime(this->tablesize/2);
                    if(newSize>=this->initsize){
                        rehash(newSize);
                        this->deletecount=0;
                    }
                }
                return true;
            }
            i++;
        }
        return false;
    }
};

template<typename K,typename V>
class CustomProbingTable:public HashTable<K,V>{
    HashEntry<K,V>*table;
    int choice;
    int C1,C2;
    int gethash(const string& key){
        if(choice==1){
            return this->hash1(key);
        }
        else{
            return this->hash2(key);
        }
    }

    int customHash(const string& key,int i){
        ll h1=gethash(key);
        ll aux=this->auxHash(key);
        ll probe=(h1+C1*i*aux+C2*i*i)%this->tablesize;
        if(probe<0){
            probe+=this->tablesize;
        }
        return probe;
    }

    void rehash(int newSize){
        HashEntry<K,V>*oldtable=table;
        int oldsize=this->tablesize;
        this->tablesize=newSize;
        table=new HashEntry<K,V>[this->tablesize];
        this->total=0;
        for(int i=0;i<oldsize;i++){
            if(oldtable[i].isOccupied && !oldtable[i].isDeleted){
                int j=0;
                int idx;
                while(j<this->tablesize){
                    idx=customHash(oldtable[i].key,j);
                    if(!table[idx].isOccupied){
                        table[idx]=HashEntry<K,V>(oldtable[i].key,oldtable[i].value);
                        this->total++;
                        break;
                    }
                    j++;
                }
            }
        }
        delete[] oldtable;
        this->lastsize=this->total;
    }
public:
    CustomProbingTable(int choice=1,int C1=1,int C2=3,int initsize=13,double loadfactor=0.5):HashTable<K,V>(initsize,loadfactor){
        this->choice=choice;
        this->C1=C1;
        this->C2=C2;
        table=new HashEntry<K,V>[this->tablesize];
    }

    ~CustomProbingTable(){
        delete[] table;
    }

    bool search(const K& key,V& value,int& hits)override{
        hits=0;
        int i=0;
        int idx;
        while(i<this->tablesize){
            idx=customHash(key,i);
            hits++;
            if(!table[idx].isOccupied){
                return false;
            }
            if(table[idx].isOccupied && !table[idx].isDeleted && table[idx].key==key){
                value=table[idx].value;
                return true;
            }
            i++;
        }
        return false;
    }

    void insert(const K& key,const V& value)override{
        V temp;
        int hits;
        if(search(key,temp,hits)){
            return;
        }
        int i=0;
        int idx;
        while(i<this->tablesize){
            idx=customHash(key,i);
            if(!table[idx].isOccupied ||table[idx].isDeleted){
                if(i>0){
                    this->collisioncount++;
                }
                table[idx]=HashEntry<K,V>(key,value);
                this->total++;
                this->insertcount++;
                if(this->loadfactor()>0.5 && this->insertcount>=this->lastsize/2){
                    int newSize=this->nextPrime(2*this->tablesize);
                    rehash(newSize);
                    this->insertcount=0;
                }
                return;
            }
            i++;
        }
    }

    bool remove(const K& key)override{
        int i=0;
        int idx;
        while(i<this->tablesize){
            idx=customHash(key,i);
            if(!table[idx].isOccupied){
                return false;
            }
            if(table[idx].isOccupied && !table[idx].isDeleted && table[idx].key==key){
                table[idx].isDeleted=true;
                this->total--;
                this->deletecount++;
                if(this->tablesize>this->initsize && this->loadfactor()<0.25 && this->deletecount>=this->lastsize/2){
                    int newSize=this->previousPrime(this->tablesize/2);
                    if(newSize>=this->initsize){
                        rehash(newSize);
                        this->deletecount=0;
                    }
                }
                return true;
            }
            i++;
        }
        return false;
    }
};

void runEvaluation(){
    const int NUM_WORDS=10000;
    const int WORD_LENGTH=10;
    const int NUM_SEARCH=1000;
    
    cout<<"Generating "<<NUM_WORDS<<" unique words of length "<<WORD_LENGTH<<"..."<<endl;
    
    WordGenerator wordGen;
    vector<string>words;
    
    for(int i=0;i<NUM_WORDS;i++) {
        words.push_back(wordGen.generateUniqueWord(WORD_LENGTH));
    }
    
    cout<<"Words generated successfully!"<<endl<<endl;
    
    struct Result{
        string method;
        int collisionsHash1;
        double avgHitsHash1;
        int collisionsHash2;
        double avgHitsHash2;
    };
    
    vector<Result>results;
    cout<<"Testing Chaining Method..."<<endl;
    
    Chaining<string,int>chainHash1(1);
    for(int i=0;i<NUM_WORDS;i++){
        chainHash1.insert(words[i],i+1);
    }
    
    vector<string>searchWords;
    for(int i=0;i<NUM_SEARCH;i++){
        int randomIndex=rand()%NUM_WORDS;
        searchWords.push_back(words[randomIndex]);
    }
    
    int totalHits1=0;
    for(const string& word:searchWords){
        int value,hits;
        chainHash1.search(word,value,hits);
        totalHits1+=hits;
    }
    
    Chaining<string,int>chainHash2(2);
    for(int i=0;i<NUM_WORDS;i++) {
        chainHash2.insert(words[i],i+1);
    }
    
    int totalHits2=0;
    for(const string& word:searchWords){
        int value,hits;
        chainHash2.search(word,value,hits);
        totalHits2+=hits;
    }
    
    results.push_back({
        "Chaining Method",
        chainHash1.collisioncount,
        (double)totalHits1/NUM_SEARCH,
        chainHash2.collisioncount,
        (double)totalHits2/NUM_SEARCH
    });
    
    cout<<"  Hash1 - Collisions: "<<chainHash1.collisioncount<<", Avg Hits: "<<fixed<<setprecision(2)<<(double)totalHits1/NUM_SEARCH<<endl;
    cout<<"  Hash2 - Collisions: "<<chainHash2.collisioncount<<", Avg Hits: "<<fixed<<setprecision(2)<<(double)totalHits2/NUM_SEARCH<<endl<<endl;
    cout<<"Testing Double Hashing..."<<endl;
    
    DoubleHashingTable<string,int>doubleHash1(1);
    for(int i=0;i<NUM_WORDS;i++){
        doubleHash1.insert(words[i],i+1);
    }
    
    totalHits1=0;
    for(const string& word:searchWords){
        int value,hits;
        doubleHash1.search(word,value,hits);
        totalHits1+=hits;
    }
    
    DoubleHashingTable<string,int>doubleHash2(2);
    for(int i=0;i<NUM_WORDS;i++){
        doubleHash2.insert(words[i],i+1);
    }
    
    totalHits2=0;
    for(const string& word:searchWords){
        int value,hits;
        doubleHash2.search(word,value,hits);
        totalHits2+=hits;
    }
    
    results.push_back({
        "Double Hashing",
        doubleHash1.collisioncount,
        (double)totalHits1/NUM_SEARCH,
        doubleHash2.collisioncount,
        (double)totalHits2/NUM_SEARCH
    });
    
    cout<<"  Hash1 - Collisions: "<<doubleHash1.collisioncount<<", Avg Hits: "<<fixed<<setprecision(2)<<(double)totalHits1/NUM_SEARCH<<endl;
    cout<<"  Hash2 - Collisions: "<<doubleHash2.collisioncount<<", Avg Hits: "<<fixed<<setprecision(2)<<(double)totalHits2/NUM_SEARCH<<endl<<endl;
    cout<<"Testing Custom Probing..."<<endl;
    
    CustomProbingTable<string,int>customHash1(1);
    for(int i=0;i<NUM_WORDS;i++) {
        customHash1.insert(words[i],i+1);
    }
    
    totalHits1=0;
    for(const string& word:searchWords){
        int value,hits;
        customHash1.search(word,value,hits);
        totalHits1+=hits;
    }
    
    CustomProbingTable<string,int>customHash2(2);
    for(int i=0;i<NUM_WORDS;i++) {
        customHash2.insert(words[i],i+1);
    }
    
    totalHits2=0;
    for(const string& word:searchWords) {
        int value,hits;
        customHash2.search(word,value,hits);
        totalHits2+=hits;
    }
    
    results.push_back({
        "Custom Probing",
        customHash1.collisioncount,
        (double)totalHits1/NUM_SEARCH,
        customHash2.collisioncount,
        (double)totalHits2/NUM_SEARCH
    });
    
    cout<<"  Hash1 - Collisions: "<<customHash1.collisioncount<<", Avg Hits: "<<fixed<<setprecision(2)<<(double)totalHits1/NUM_SEARCH<<endl;
    cout<<"  Hash2 - Collisions: "<<customHash2.collisioncount<<", Avg Hits: "<<fixed<<setprecision(2)<<(double)totalHits2/NUM_SEARCH<<endl<<endl;
    cout << "\n========================================" << endl;
    cout << "         PERFORMANCE REPORT" << endl;
    cout << "========================================" << endl;
    cout << "Total Words: " << NUM_WORDS << endl;
    cout << "Word Length: " << WORD_LENGTH << endl;
    cout << "Search Words: " << NUM_SEARCH << endl;
    cout << "========================================\n" << endl;
    
    cout << setw(20) << left << "" 
         << setw(35) << "Hash1" 
         << setw(35) << "Hash2" << endl;
    cout << setw(20) << left << "" 
         << setw(17) << "Collisions" 
         << setw(18) << "Avg Hits"
         << setw(17) << "Collisions" 
         << setw(18) << "Avg Hits" << endl;
    cout << string(90, '-') << endl;
    
    for (const Result& r : results) {
        cout << setw(20) << left << r.method
             << setw(17) << r.collisionsHash1
             << setw(18) << fixed << setprecision(2) << r.avgHitsHash1
             << setw(17) << r.collisionsHash2
             << setw(18) << fixed << setprecision(2) << r.avgHitsHash2
             << endl;
    }
    cout << string(90, '-') << endl;
}

int main() {
    FAST_IO;
    int choice;
    
    while (true) {
        cout <<"\nMenu:" << endl;
        cout <<"1. Run full evaluation (10,000 words)" << endl;
        cout <<"2. Test with custom number of words" << endl;
        cout <<"3. Exit" << endl;
        cin>>choice;
        
        if (choice == 1) {
            runEvaluation();
        }
        else if (choice == 2) {
            int numWords, wordLength;
            cout << "Enter number of words: ";
            cin >> numWords;
            cout << "Enter word length: ";
            cin >> wordLength;
            
            WordGenerator wordGen;
            vector<string>words;
            
            cout << "Generating words..." << endl;
            for (int i = 0; i < numWords; i++) {
                words.push_back(wordGen.generateUniqueWord(wordLength));
            }
            
            Chaining<string, int> table(1);
            for (int i = 0; i < numWords; i++) {
                table.insert(words[i], i + 1);
            }
            
            cout << "Inserted " << numWords << " words" << endl;
            cout << "Total collisions: " << table.collisioncount << endl;
            cout << "Load factor: " << fixed << setprecision(2) << table.loadfactor() << endl;
            cout << "Table size: " << table.tablesize << endl;
        }
        else if(choice==3) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}