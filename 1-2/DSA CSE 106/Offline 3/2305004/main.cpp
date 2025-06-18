#include <iostream>
#include <vector>
#include "queue.h"
using namespace std;

/********************************* RANDOM ************************************/
#define LCG_MULTIPLIER (1103515245)
#define LCG_INCREMENT (12345)
#define LCG_MODULUS ((unsigned)~0 >> 1)
static unsigned int lcg_seed = 1;
void custom_srand(unsigned int seed)
{
    lcg_seed = seed;
}
int custom_rand()
{
    lcg_seed = (LCG_MULTIPLIER * lcg_seed + LCG_INCREMENT) % (LCG_MODULUS + 1);
    return lcg_seed;
}
int randomQueue(int seed = -1)
{
    static bool initialized = false;
    if (seed != -1 && !initialized)
    {
        custom_srand(seed);
        initialized = true;
        return -1;
    }
    cout << "randomQueue() called" << endl;
    return (custom_rand() % 2) + 1;
}
/*****************************************************************************/

int main()
{
    //freopen("test_input_1.txt", "r", stdin); // Test Case 1
     freopen("test_input_2.txt", "r", stdin); // Test Case 2
    freopen("output.txt", "w", stdout);
    // Initialize the random generator with a fixed seed
    // You should set the seed only once at the beginning of your program
    // NOTE: Do not modify the following lines.
    randomQueue(42);

    Queue *Q1 = new ListQueue();
    Queue *Q2 = new ListQueue();
    Queue *Q = new ArrayQueue();

    int N;
    cin >> N;

    bool merged=false;
    int arr[10001];

    for (int i = 1; i <= N; i++)
    {
        // TODO: Edit here to add your own logic
        int func;
        cin>>func;
        if(func==1){
            int id,timestamp;
            cin>>id>>timestamp;
            arr[id]=timestamp;
            cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): ";
            if(!merged){
                if(Q1->empty() && Q2->empty()){
                    //cout<<"randomQueue() called";
                    if(randomQueue()==1)
                        Q1->enqueue(id);
                    else
                        Q2->enqueue(id);
                }
                else if(Q1->empty()){
                    Q1->enqueue(id);
                    cout<<endl;
                }
                else if(Q2->empty()){
                    Q2->enqueue(id);
                    cout<<endl;
                }
                else{
                    if(arr[Q1->back()]<arr[Q2->back()]){
                        Q1->enqueue(id);
                    }
                    else{
                        Q2->enqueue(id);
                    }
                    cout<<endl;
                }
            }
            else{
                Q->enqueue(id);
                cout<<endl;
            }
            
        }
        else if(func==2){
            int id,timestamp;
            cin>>id>>timestamp;
            arr[id]=timestamp;
            cout<<"Operation "<<i<<" (Leave "<<id<<" "<<timestamp<<"): \n";
            if(!merged){
                int size1=Q1->size();
                int j=0;
                bool done=false;
                while(j<size1){
                    int temp=Q1->dequeue();
                    if(temp==id){
                        done=true;
                    }
                    else{
                        Q1->enqueue(temp);
                    }
                    j++;
                }
                if(!done){
                    int size2=Q2->size();
                    j=0;
                    while(j<size2){
                        int temp=Q2->dequeue();
                        if(temp==id){
                            done=true;
                        }
                        else{
                            Q2->enqueue(temp);
                        }
                        j++;
                    }
                }
            }
            
            else{
                int size3=Q->size();
                int j=0;
                while(j<size3){
                    int temp=Q->dequeue();
                    if(temp!=id){
                        Q->enqueue(temp);
                    }
                    j++;
                }
            }
        }
        else if(func==3){
            cout<<"Operation "<<i<<" (Merge): \n";
            if(merged)
                continue;
            while(!Q1->empty() && !Q2->empty()){
                int a=Q1->dequeue();
                int b=Q2->dequeue();
                if(arr[a]<arr[b]){
                    Q->enqueue(a);
                    Q->enqueue(b);
                }
                else{
                    Q->enqueue(b);
                    Q->enqueue(a);
                }
            }
            while(!Q1->empty()){
                int a=Q1->dequeue();
                Q->enqueue(a);
            }
            while(!Q2->empty()){
                int b=Q2->dequeue();
                Q->enqueue(b);
            }
            merged=true;
        }
        else if(func==4){
            cout<<"Operation "<<i<<" (Split): \n";
            if(!merged)
                continue;
            int j=1;
            while(!Q->empty()){
                int temp=Q->dequeue();
                if(j%2==0){
                    Q2->enqueue(temp);
                }
                else{
                    Q1->enqueue(temp);
                }
                j++;
            }
            merged=false;
        }
        else if(func==5){
            cout<<"Operation "<<i<<" (Departure): ";
            if(!merged){
                if(!Q1->empty() && !Q2->empty()){
                    //cout<<"randomQueue() called";
                    if(randomQueue()==1)
                        Q1->dequeue();
                    else
                        Q2->dequeue();
                }
                else if(!Q1->empty()){
                    Q1->dequeue();
                    cout<<endl;
                }
                else if(!Q2->empty()){
                    Q2->dequeue();
                    cout<<endl;
                }
            }
            else{
                if(!Q->empty()){
                    Q->dequeue();
                }
                cout<<endl;
            }
        }
        cout<<"Q1: "<<Q1->toString()<<endl;
        cout<<"Q2: "<<Q2->toString()<<endl;
        cout<<"Q : "<<Q->toString()<<endl;

        // After each operation, we will check the queue's size and capacity
        // NOTE: Do not modify the following lines.
        int capacity = ((ArrayQueue *)Q)->getCapacity();
        if ((Q->size() < capacity / 4 && capacity > 2))
        {
            cout << "Error: Queue size is less than 25% of its capacity." << endl;
        }
        else if (capacity < 2)
        {
            cout << "Error: Queue capacity is less than 2." << endl;
        }
    }

    delete Q1;
    delete Q2;
    delete Q;
    return 0;
}