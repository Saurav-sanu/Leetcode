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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=head;
        ListNode* temp=head;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            ListNode* result=head->next;
            delete head;
            return result;
        }
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
            prev=prev->next;
        }

        ListNode* del=prev->next;
        prev->next=prev->next->next;

        delete del;

        return head;
    }
};