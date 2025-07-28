#include<stdio.h>
#include<stdbool.h>
#include "linkedList.h"

node* reverseKGroup(node* head,int k){
    node* curr=head;
    node* new_head=NULL;
    node* group_prev=NULL;
    while(curr){
        node* start=curr;
        node* prev=NULL;
        node* next=NULL;
        int p=0;
        while(p<k && curr){
            next=curr->next;
            curr->next=prev;
            curr->prev=next;
            prev=curr;
            curr=next;
            p++;
        }
        if(!new_head){
            new_head=prev;
        }
        
        if(group_prev){
            group_prev->next=prev;
            prev->prev=group_prev;
        }

        start->next=curr;
        if(curr)
            curr->prev=start;
        group_prev=start;
    }
    if(new_head)
        new_head->prev=NULL;
    return new_head? new_head:head;
}

int main(){
    linkedList* LL;
    init(LL);
    append(1,LL);
    append(2,LL);
    append(2,LL);
    append(4,LL);
    append(5,LL);
    append(6,LL);
    append(7,LL);
    append(8,LL);
    print(LL);
    LL->head=reverseKGroup(LL->head,4);
    prev(5,LL);
    print(LL);
}