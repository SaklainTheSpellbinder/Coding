#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *array;
    // declare variables you need
    int size;
    int capacity;
    int curr;
} arrayList;

void init(arrayList* list)
{
    // implement initialization
    list->array=calloc(2,sizeof(int));
    list->capacity=2;
    list->size=0;
    list->curr=-1;
}

void free_list(arrayList* list)
{
    // implement destruction of list
    free(list->array);
    list->array=NULL;
}

void increase_capacity(arrayList* list)
{
    // implement capacity increase
    int* again=calloc(2*list->capacity,sizeof(int));
    for(int i=0;i<list->capacity;i++){
        again[i]=list->array[i];
    }
    free(list->array);
    list->array=again;
    printf("Capacity increased from %d to %d\n",list->capacity,list->capacity*2);
    list->capacity*=2;
}

void decrease_capacity(arrayList* list)
{
    // implement capacity decrease
    int* again=calloc(list->capacity/2,sizeof(int));
    for(int i=0;i<(list->capacity)/2;i++){
        again[i]=list->array[i];
    }
    free(list->array);
    list->array=again;
    printf("Capacity decreased from %d to %d\n",list->capacity,list->capacity/2);
    list->capacity/=2;
}

void print(arrayList* list)
{
    // implement list printing
    if(list->size==0){
        printf("[.]\n");
    }
    else{
        printf("[");
        for(int i=0;i<list->size;i++){
            printf(" %d",list->array[i]);
            if(list->curr==i){
                printf("|");
            }
        }
        printf(" ]\n");
    }
}

void insert(int item, arrayList* list)
{
    // implement insert function
    if(list->size+1>list->capacity/2){
        increase_capacity(list);
    }
    for(int i=list->size-1;i>list->curr;i--){
        list->array[i+1]=list->array[i];
    }
    list->array[list->curr+1]=item;
    list->size++;
    list->curr++;
    print(list);
}

int delete_cur(arrayList* list)
{
    // implement deletion of current index function
    if(list->size-1<list->capacity/4){
        decrease_capacity(list);
    }
    int temp=list->array[list->curr];
    for(int i=list->curr;i<list->size-1;i++){
        list->array[i]=list->array[i+1];
    }
    list->size--;
    if(list->size<=list->curr){
        list->curr--;
    }
    print(list);
    return temp;
}

void append(int item, arrayList* list)
{
    // implement append function
    if(list->size+1>list->capacity/2){
        increase_capacity(list);
    }
    if(list->curr==-1){
        list->curr++;
    }
    list->array[list->size++]=item;
    print(list);
}

int size(arrayList* list)
{
    // implement size function
    return list->size;
}

void prev(int n, arrayList* list)
{
    // implement prev function
    if(list->curr-n<=0){
        list->curr=0;
    }
    else{
        list->curr-=n;
    }
    print(list);
}

void next(int n, arrayList* list)
{
    // implement next function
    if(list->curr+n>=(list->size-1)){
        list->curr=list->size-1;
    }
    else{
        list->curr+=n;
    }
    print(list);
}

int is_present(int n, arrayList* list)
{
    // implement presence checking function
    for(int i=0;i<list->size;i++){
        if(list->array[i]==n){
            return 1;
        }
    }
    return 0;
}

void clear(arrayList* list)
{
    // implement list clearing function
    free_list(list);
    init(list);
    print(list);
}

void delete_item(int item, arrayList* list)
{
    // implement item deletion function
    if(is_present(item,list)){
        int i;
        for(i=0;i<list->size;i++){
            if(list->array[i]==item){
                break;  
            }
        }
        if(list->size-1<list->capacity/4){
            decrease_capacity(list);
        }
        for(int j=i;j<list->size-1;j++){
            list->array[j]=list->array[j+1];
        }
        list->size--;
        if(i<list->curr){
            list->curr--;
        }
        if(list->size<=list->curr){
            list->curr--;
        }
        print(list);
    }
    else{
        printf("%d not found\n",item);
        return;
    }
    
}

void swap_ind(int ind1, int ind2, arrayList* list)
{
    // implement swap function
    if(ind1<0 || ind2<0 || ind1>=list->size || ind2>=list->size){
        printf("Index out of bounds\n");
        return;
    }
    int temp=list->array[ind1];
    list->array[ind1]=list->array[ind2];
    list->array[ind2]=temp;
    print(list);
}

// you can define helper functions you need