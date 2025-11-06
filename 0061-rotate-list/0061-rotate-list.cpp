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
int len(ListNode* head){
    int count=0;
    ListNode* temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}


    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }

        int length=len(head);
        k=k%length;
        if (k == 0) return head;

        ListNode* newTail=head;

        for(int i=1;i<length-k;i++){
            newTail=newTail->next;
        }

        ListNode* newHead=newTail->next;

        newTail->next=NULL;

        ListNode* tail=newHead;

        while(tail && tail->next){
            tail=tail->next;
        }

        tail->next=head;


        return newHead;


    }
};