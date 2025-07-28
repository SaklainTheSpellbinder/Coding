#include<stdio.h>
#include "linkedList.h"

node* splitAtMid(node* head){
    node* slow=head;
    node* fast=head;
    node* prev=NULL;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev){
        prev->next=NULL;
    }
    return slow;
}

node* merge(node* head1,node* head2){
    linkedList ans;
    init(&ans);
    node* curr1=head1;
    node* curr2=head2;
    while(curr1 && curr2){
        if(curr1->element<curr2->element){
            append(curr1->element,&ans);
            curr1=curr1->next;
        }
        else{
            append(curr2->element,&ans);
            curr2=curr2->next;
        }
    }
    while(curr1){
        append(curr1->element,&ans);
        curr1=curr1->next;
    }
    while(curr2){
        append(curr2->element,&ans);
        curr2=curr2->next;
    }
    return ans.head;
}

node* mergesort(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* righthead=splitAtMid(head);
    node* left=mergesort(head);
    node* right=mergesort(righthead);
    return merge(left,right);
}

int main(){
    linkedList LL;
    init(&LL);
    append(3,&LL);
    append(4,&LL);
    append(1,&LL);
    append(18,&LL);
    append(6,&LL);
    LL.head=mergesort(LL.head);
    print(&LL);
}