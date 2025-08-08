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
ListNode* curr;
bool recur(ListNode* head){
    if(head==NULL){
        return true;
    }

    bool ans = recur(head->next);

    if(head->val!=curr->val){
        return false;
    }
    curr=curr->next;
    return ans;

    
}
    bool isPalindrome(ListNode* head) {
        curr=head;
        return recur(head);
    }
};