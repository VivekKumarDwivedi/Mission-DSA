/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
       else{
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* dummy=new ListNode(100);
        ListNode* d=dummy;
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                d->next=temp1;
                temp1=temp1->next;
                d=d->next;
            }
            else {
                d->next=temp2;
                temp2=temp2->next;
                     d=d->next;
            }
        }
        while(temp1==NULL && temp2!=NULL){
             d->next=temp2;
                temp2=temp2->next;
                     d=d->next;

        }
         while(temp1!=NULL && temp2==NULL){
             d->next=temp1;
                temp1=temp1->next;
                     d=d->next;

        }

        return dummy->next;
       }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode* dummy =new ListNode(-100000);

       for(auto l:lists){
        dummy =mergeTwoLists(dummy,l);
       }
      return dummy->next;
       
    }
};