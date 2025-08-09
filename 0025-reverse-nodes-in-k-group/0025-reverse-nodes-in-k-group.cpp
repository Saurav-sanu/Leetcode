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
class Solution {
public:
ListNode* kthNode(ListNode* head,int k){
    ListNode* temp=head;
    k--;
    while(temp!=NULL && k--){
        temp=temp->next;
    }
    return temp;
}

ListNode* reverse(ListNode* head,int k){
    ListNode* curr=head;
    ListNode* prev=NULL;
    int count=0;
    while(curr!=NULL && k--){
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* newHead=head;
        while(curr!=NULL){
            ListNode* kth=kthNode(curr,k);
            if(kth==NULL){
                if(prev){
                    prev->next=curr;
                    break;
                }
            }
           ListNode* nextNode=kth->next;
           kth->next=NULL;
           ListNode* rev=reverse(curr,k);
        
       

 if (!prev) {
            newHead = rev;
        } else {
            prev->next = rev;
        }

        prev = curr; // after reversal, curr is now tail
        curr = nextNode;

        }
        return newHead;
      
    }
};