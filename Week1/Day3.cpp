#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head == NULL || head->next== NULL){
        return false;
    }
    ListNode* slow_ptr=head;
    ListNode* fast_ptr=head;
    while(slow_ptr!=NULL && fast_ptr!=NULL && fast_ptr->next!=NULL){
        slow_ptr= slow_ptr->next;
        fast_ptr= fast_ptr->next->next;
        if(slow_ptr == fast_ptr){
             break;
        }
    }
    if(slow_ptr==fast_ptr){
        return true;
    }
    return false;
}
