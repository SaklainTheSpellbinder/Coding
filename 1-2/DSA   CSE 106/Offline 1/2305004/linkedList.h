#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node* next;
    struct node* prev;
} node;

typedef struct 
{
    // declare head, tail, cur and other variables you need
    node* head;
    node* tail;
    int size;
    node* pos;
} linkedList;

void init(linkedList* list)
{
    // implement initialization
    list->head=list->tail=NULL;
    list->size=0;
    list->pos=NULL;
}

void free_list(linkedList* list)
{
    // implement destruction of list
    node* curr=list->head;
    while(curr){
        node* temp=curr;
        curr=curr->next;
        free(temp);
    }
    init(list);
}

void print(linkedList* list)
{
    // implement list printing
    if(list->head==NULL){
        printf("[.]\n");
        return;
    }
    printf("[");
    node* curr=list->head;
    while(curr){
        printf(" %d",curr->element);
        if(curr==list->pos){
            printf("|");
        }
        curr=curr->next;
    }
    printf(" ]\n");
}

void insert(int item, linkedList* list)
{
    // implement insert function
    node* newNode=(node*)malloc(sizeof(node));
    newNode->element=item;
    newNode->next=newNode->prev=NULL;
    if(list->pos==NULL){
        list->head=list->tail=list->pos=newNode;
    }
    else{
        node* temp=list->pos->next;
        newNode->prev=list->pos;
        list->pos->next=newNode;
        newNode->next=temp;
        if(temp!=NULL)
            temp->prev=newNode;
        else
            list->tail=newNode;
        list->pos=newNode;
    }
    list->size++;
    print(list);
}

int delete_cur(linkedList* list)
{
    // implement deletion of current index function
    if(list->pos==NULL){
        printf("Nothing to delete\n");
        return -1;
    }
    int dummy;
    if(list->pos==list->head){
        node* temp=list->head;
        list->head=list->head->next;
        list->pos=list->head;
        if(list->head!=NULL){
            list->head->prev=NULL;
        }
        else{
            list->tail=NULL;
        }
        temp->next=NULL;
        dummy=temp->element;
        free(temp);
    }
    else if(list->pos==list->tail){
        node *old=list->tail;
        list->pos=old->prev;
        list->pos->next=NULL;
        list->tail=list->pos;
        dummy=old->element;
        free(old);
    }
    else{
        list->pos->prev->next=list->pos->next;
        list->pos->next->prev=list->pos->prev;
        node* temp=list->pos;
        list->pos=list->pos->next;
        temp->next=temp->prev=NULL;
        dummy=temp->element;
        free(temp);
    }
    list->size--;
    print(list);
    return dummy;
}

void append(int item, linkedList* list)
{
    // implement append function
    node* newNode=(node*)malloc(sizeof(node));
    newNode->element=item;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(list->head==NULL){
        list->head=list->tail=newNode;
        list->pos=list->head;
    }
    else{
        list->tail->next=newNode;
        newNode->prev=list->tail;
        list->tail=newNode;
    }
    list->size++;
    print(list);
}

int size(linkedList* list)
{
    // implement size function
    int size=0;
    node* curr=list->head;
    while(curr){
        curr=curr->next;
        size++;
    }
    return size;
}

void prev(int n, linkedList* list)
{
    // implement prev function
    while(n-- && list->pos && list->pos->prev){
        list->pos=list->pos->prev;
    }
    print(list);
}

void next(int n, linkedList* list)
{
    // implement next function

    while(n-- && list->pos && list->pos->next){
        list->pos=list->pos->next;
    }
    print(list);
}

int is_present(int n, linkedList* list)
{
    // implement presence checking function
    node* temp=list->head;
    while(temp){
        if(temp->element==n){
            return 1;
        }
        temp=temp->next;
    }
    return 0;

}

void clear(linkedList* list)
{
    // implement list clearing function
    free_list(list);
    print(list);
}

void delete_item(int item, linkedList* list)
{
    // implement item deletion function
    node* temp=list->head;
    while(temp){
        if(temp->element==item){
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("%d not found\n",item);
        return;
    }
    if(temp==list->pos && list->pos->next){
        list->pos=list->pos->next;
    }
    if(temp==list->head){
        node* tintin=list->head;
        list->head=list->head->next;
        if(list->head)
            list->head->prev=NULL;
        else{
            list->tail=NULL;
            list->pos=NULL;
        }
        tintin->next=NULL;
        free(tintin);
    }
    else if(temp==list->tail){
        list->tail->prev->next=NULL;
        node* tintin=list->tail->prev;
        if(list->pos==list->tail){
            list->pos=tintin;
        }
        free(list->tail);
        list->tail=tintin;
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
    list->size--;
    print(list);

}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    // implement swap function
    if(ind1<0 || ind2<0 || ind1>=list->size || ind2>=list->size){
        printf("Index out of bounds\n");
        return;
    }
    node* temp1=list->head;
    node* temp2=list->head;
    while(ind1--){
        temp1=temp1->next;
    }
    while(ind2--){
        temp2=temp2->next;
    }
    int temp=temp1->element;
    temp1->element=temp2->element;
    temp2->element=temp;
    print(list);
}

// you can define helper functions you need