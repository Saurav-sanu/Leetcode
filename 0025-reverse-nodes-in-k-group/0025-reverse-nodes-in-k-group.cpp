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
 int getLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }

        //one case reverse
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* newNode=curr->next;
        int pos=0;
        int len = getLength(head);
        if(len < k) {
            return head;
        }
        while(pos<k){
            newNode=curr->next;
            pos++;  
            curr->next=prev;
            prev=curr;
            curr=newNode;
        }
        ListNode* recursionans=NULL;
        if(newNode!=NULL){
            recursionans=reverseKGroup(newNode,k);
            head->next=recursionans;
        }
        return prev;
    }
};