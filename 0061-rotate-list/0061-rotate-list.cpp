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
    ListNode* temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
ListNode* kth(ListNode* head,int k){
    ListNode* temp=head;
    while(temp!=NULL && --k){
        temp=temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
          if (!head || !head->next || k == 0) return head;

        int l = len(head);
        k = k % l;
        if (k == 0) return head;

       ListNode* curr = head;
        ListNode* newhead = head;
        ListNode* nextNode = NULL;

        ListNode* ki = kth(head, l-k);
        nextNode = ki->next;
        ki->next = NULL;

        // Find last node of second part
        ListNode* temp = nextNode;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newhead;

        return nextNode;
    }
    
};