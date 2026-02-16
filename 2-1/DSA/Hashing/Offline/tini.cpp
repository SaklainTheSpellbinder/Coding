#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

class WordGenerator {
    set<string> generatedWords;
public:
    WordGenerator() { srand(time(0)); }

    string generateWord(int len) {
        string a = "";
        for (int i = 0; i < len; i++) {
            char c = 'a' + (rand() % 26);
            a += c;
        }
        return a;
    }

    string generateUniqueWord(int len) {
        string a;
        do {
            a = generateWord(len);
        } while (generatedWords.find(a) != generatedWords.end());
        generatedWords.insert(a);
        return a;
    }
};

template<typename K, typename V>
class ChainNode {
public:
    K key; V value;
    ChainNode* next;
    ChainNode(K k, V v) : key(k), value(v), next(nullptr) {}
};

template<typename K, typename V>
struct HashEntry {
    K key; V value;
    bool isOccupied = false;
    bool isDeleted = false;
};

template<typename K, typename V>
class HashTable {
public:
    int tablesize, initsize, total = 0;
    int insertcount = 0, deletecount = 0;
    int elementsAtLastResize = 0;
    int collisioncount = 0;
    double max_load_factor;

    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }

    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

    int previousPrime(int n) {
        while (n > 2 && !isPrime(n)) n--;
        return n;
    }

    HashTable(int init = 13, double loadfactor = 0.5) {
        initsize = nextPrime(init);
        tablesize = initsize;
        max_load_factor = loadfactor;
    }

    virtual ~HashTable() {}

    // Hash1 and Hash2 as required [cite: 35]
    int hash1(const string& key) {
        unsigned long h = 0;
        for (char c : key) h = (h * 31 + c) % tablesize;
        return h;
    }

    int hash2(const string& key) {
        unsigned long h = 0;
        for (char c : key) h = (h * 37 + c) % tablesize;
        return h;
    }

    int auxHash(const string& key) {
        unsigned long h = 0;
        for (char c : key) h = h * 29 + c;
        return (h % (tablesize - 1)) + 1;
    }

    double currentLoadFactor() { return (double)total / tablesize; }

    virtual void insert(const K& key, const V& value) = 0;
    virtual bool search(const K& key, V& value, int& hits) = 0;
    virtual bool remove(const K& key) = 0;
};

// 4.1 Chaining Method [cite: 42]
template<typename K, typename V>
class Chaining : public HashTable<K, V> {
    ChainNode<K, V>** table;
    int choice;

    int getHash(const K& key) {
        string s = key;
        return (choice == 1) ? this->hash1(s) : this->hash2(s);
    }

    void rehash(int newSize) {
        ChainNode<K, V>** oldTable = table;
        int oldSize = this->tablesize;
        this->tablesize = newSize;
        table = new ChainNode<K, V>*[this->tablesize]();
        
        this->total = 0;
        for (int i = 0; i < oldSize; i++) {
            ChainNode<K, V>* curr = oldTable[i];
            while (curr) {
                ChainNode<K, V>* next = curr->next;
                int idx = getHash(curr->key);
                curr->next = table[idx];
                table[idx] = curr;
                this->total++;
                curr = next;
            }
        }
        delete[] oldTable;
        this->elementsAtLastResize = this->total;
    }

public:
    Chaining(int choice = 1, int init = 13) : HashTable<K, V>(init), choice(choice) {
        table = new ChainNode<K, V>*[this->tablesize]();
    }

    void insert(const K& key, const V& value) override {
        V temp; int h;
        if (search(key, temp, h)) return;
        int idx = getHash(key);
        if (table[idx]) this->collisioncount++;
        ChainNode<K, V>* node = new ChainNode<K, V>(key, value);
        node->next = table[idx];
        table[idx] = node;
        this->total++; this->insertcount++;

        if (this->currentLoadFactor() > 0.5 && this->insertcount >= this->elementsAtLastResize / 2) {
            rehash(this->nextPrime(this->tablesize * 2));
            this->insertcount = 0;
        }
    }

    bool search(const K& key, V& value, int& hits) override {
        hits = 0;
        int idx = getHash(key);
        ChainNode<K, V>* curr = table[idx];
        while (curr) {
            hits++;
            if (curr->key == key) { value = curr->value; return true; }
            curr = curr->next;
        }
        return false;
    }

    bool remove(const K& key) override {
        int idx = getHash(key);
        ChainNode<K, V> *curr = table[idx], *prev = nullptr;
        while (curr) {
            if (curr->key == key) {
                if (prev) prev->next = curr->next; else table[idx] = curr->next;
                delete curr; this->total--; this->deletecount++;
                if (this->tablesize > this->initsize && this->currentLoadFactor() < 0.25 && this->deletecount >= this->elementsAtLastResize / 2) {
                    rehash(this->previousPrime(this->tablesize / 2));
                    this->deletecount = 0;
                }
                return true;
            }
            prev = curr; curr = curr->next;
        }
        return false;
    }
};

// 4.2 Double Hashing [cite: 46]
template<typename K, typename V>
class DoubleHashingTable : public HashTable<K, V> {
    HashEntry<K, V>* table;
    int choice;

    int getProbe(const K& key, int i) {
        string s = key;
        int h1 = (choice == 1) ? this->hash1(s) : this->hash2(s);
        return (h1 + i * this->auxHash(s)) % this->tablesize;
    }

    void rehash(int newSize) {
        HashEntry<K, V>* oldTable = table;
        int oldSize = this->tablesize;
        this->tablesize = newSize;
        table = new HashEntry<K, V>[this->tablesize];
        this->total = 0;
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i].isOccupied && !oldTable[i].isDeleted) {
                for (int j = 0; j < this->tablesize; j++) {
                    int idx = getProbe(oldTable[i].key, j);
                    if (!table[idx].isOccupied) {
                        table[idx] = {oldTable[i].key, oldTable[i].value, true, false};
                        this->total++; break;
                    }
                }
            }
        }
        delete[] oldTable;
        this->elementsAtLastResize = this->total;
    }

public:
    DoubleHashingTable(int choice = 1, int init = 13) : HashTable<K, V>(init), choice(choice) {
        table = new HashEntry<K, V>[this->tablesize];
    }

    void insert(const K& key, const V& value) override {
        V temp; int h; if (search(key, temp, h)) return;
        for (int i = 0; i < this->tablesize; i++) {
            int idx = getProbe(key, i);
            if (!table[idx].isOccupied || table[idx].isDeleted) {
                if (i > 0) this->collisioncount++;
                table[idx] = {key, value, true, false};
                this->total++; this->insertcount++;
                if (this->currentLoadFactor() > 0.5 && this->insertcount >= this->elementsAtLastResize / 2) {
                    rehash(this->nextPrime(this->tablesize * 2));
                    this->insertcount = 0;
                }
                return;
            }
        }
    }

    bool search(const K& key, V& value, int& hits) override {
        hits = 0;
        for (int i = 0; i < this->tablesize; i++) {
            hits++;
            int idx = getProbe(key, i);
            if (!table[idx].isOccupied) return false;
            if (!table[idx].isDeleted && table[idx].key == key) { value = table[idx].value; return true; }
        }
        return false;
    }

    bool remove(const K& key) override {
        for (int i = 0; i < this->tablesize; i++) {
            int idx = getProbe(key, i);
            if (!table[idx].isOccupied) return false;
            if (!table[idx].isDeleted && table[idx].key == key) {
                table[idx].isDeleted = true; this->total--; this->deletecount++;
                if (this->tablesize > this->initsize && this->currentLoadFactor() < 0.25 && this->deletecount >= this->elementsAtLastResize / 2) {
                    rehash(this->previousPrime(this->tablesize / 2));
                    this->deletecount = 0;
                }
                return true;
            }
        }
        return false;
    }
};

// 4.3 Custom Probing [cite: 53]
template<typename K, typename V>
class CustomProbingTable : public HashTable<K, V> {
    HashEntry<K, V>* table;
    int choice, C1, C2;

    int getProbe(const K& key, int i) {
        string s = key;
        ll h1 = (choice == 1) ? this->hash1(s) : this->hash2(s);
        ll aux = this->auxHash(s);
        ll probe = (h1 + (ll)C1 * i * aux + (ll)C2 * i * i) % this->tablesize;
        return (probe < 0) ? probe + this->tablesize : probe;
    }

    void rehash(int newSize) {
        HashEntry<K, V>* oldTable = table;
        int oldSize = this->tablesize;
        this->tablesize = newSize;
        table = new HashEntry<K, V>[this->tablesize];
        this->total = 0;
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i].isOccupied && !oldTable[i].isDeleted) {
                for (int j = 0; j < this->tablesize; j++) {
                    int idx = getProbe(oldTable[i].key, j);
                    if (!table[idx].isOccupied) {
                        table[idx] = {oldTable[i].key, oldTable[i].value, true, false};
                        this->total++; break;
                    }
                }
            }
        }
        delete[] oldTable;
        this->elementsAtLastResize = this->total;
    }

public:
    CustomProbingTable(int choice = 1, int c1 = 1, int c2 = 3, int init = 13) 
        : HashTable<K, V>(init), choice(choice), C1(c1), C2(c2) {
        table = new HashEntry<K, V>[this->tablesize];
    }

    void insert(const K& key, const V& value) override {
        V temp; int h; if (search(key, temp, h)) return;
        for (int i = 0; i < this->tablesize; i++) {
            int idx = getProbe(key, i);
            if (!table[idx].isOccupied || table[idx].isDeleted) {
                if (i > 0) this->collisioncount++;
                table[idx] = {key, value, true, false};
                this->total++; this->insertcount++;
                if (this->currentLoadFactor() > 0.5 && this->insertcount >= this->elementsAtLastResize / 2) {
                    rehash(this->nextPrime(this->tablesize * 2));
                    this->insertcount = 0;
                }
                return;
            }
        }
    }

    bool search(const K& key, V& value, int& hits) override {
        hits = 0;
        for (int i = 0; i < this->tablesize; i++) {
            hits++;
            int idx = getProbe(key, i);
            if (!table[idx].isOccupied) return false;
            if (!table[idx].isDeleted && table[idx].key == key) { value = table[idx].value; return true; }
        }
        return false;
    }

    bool remove(const K& key) override {
        for (int i = 0; i < this->tablesize; i++) {
            int idx = getProbe(key, i);
            if (!table[idx].isOccupied) return false;
            if (!table[idx].isDeleted && table[idx].key == key) {
                table[idx].isDeleted = true; this->total--; this->deletecount++;
                if (this->tablesize > this->initsize && this->currentLoadFactor() < 0.25 && this->deletecount >= this->elementsAtLastResize / 2) {
                    rehash(this->previousPrime(this->tablesize / 2));
                    this->deletecount = 0;
                }
                return true;
            }
        }
        return false;
    }
};

void runEvaluation() {
    const int NUM_WORDS = 10000;
    const int WORD_LENGTH = 10;
    const int NUM_SEARCH = 1000;
    
    WordGenerator wordGen;
    vector<string> words;
    for (int i = 0; i < NUM_WORDS; i++) words.push_back(wordGen.generateUniqueWord(WORD_LENGTH));
    
    vector<string> searchWords;
    for (int i = 0; i < NUM_SEARCH; i++) searchWords.push_back(words[rand() % NUM_WORDS]);

    auto evaluate = [&](HashTable<string, int>& ht) {
        for (int i = 0; i < NUM_WORDS; i++) ht.insert(words[i], i + 1);
        int totalHits = 0;
        for (const string& w : searchWords) {
            int val, hits;
            ht.search(w, val, hits);
            totalHits += hits;
        }
        return make_pair(ht.collisioncount, (double)totalHits / NUM_SEARCH);
    };

    Chaining<string, int> c1(1), c2(2);
    DoubleHashingTable<string, int> d1(1), d2(2);
    CustomProbingTable<string, int> cp1(1), cp2(2);

    auto r_c1 = evaluate(c1); auto r_c2 = evaluate(c2);
    auto r_d1 = evaluate(d1); auto r_d2 = evaluate(d2);
    auto r_cp1 = evaluate(cp1); auto r_cp2 = evaluate(cp2);

    cout << "\n" << setw(20) << "" << setw(35) << "Hash1" << setw(35) << "Hash2" << endl;
    cout << setw(20) << "Method" << setw(17) << "Collisions" << setw(18) << "Avg Hits" << setw(17) << "Collisions" << setw(18) << "Avg Hits" << endl;
    cout << string(90, '-') << endl;
    cout << setw(20) << "Chaining" << setw(17) << r_c1.first << setw(18) << fixed << setprecision(2) << r_c1.second << setw(17) << r_c2.first << setw(18) << r_c2.second << endl;
    cout << setw(20) << "Double Hashing" << setw(17) << r_d1.first << setw(18) << r_d1.second << setw(17) << r_d2.first << setw(18) << r_d2.second << endl;
    cout << setw(20) << "Custom Probing" << setw(17) << r_cp1.first << setw(18) << r_cp1.second << setw(17) << r_cp2.first << setw(18) << r_cp2.second << endl;
}

int main() {
    FAST_IO;
    runEvaluation();
    return 0;
}