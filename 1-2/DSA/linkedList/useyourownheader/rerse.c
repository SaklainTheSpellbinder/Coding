#include<stdio.h>
#include "linkedList.h"

void reverse(linkedList* list){
    node* curr=list->head;
    node* curr2=list->tail;
    while(curr && curr2 && curr!=curr2 && curr2->next!=curr){
        int temp=curr->element;
        curr->element=curr2->element;
        curr2->element=temp;
        curr=curr->next;
        curr2=curr2->prev;
    }
}

int main(){
    linkedList* LL;
    init(LL);
    append(1,LL);
    append(3,LL);
    append(0,LL);
    append(2,LL);
    print(LL);
    reverse(LL);
    print(LL);
    free_list(LL);
}