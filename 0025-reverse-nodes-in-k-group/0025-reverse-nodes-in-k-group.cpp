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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (!head) return nullptr;

        // Step 1: Check if there are at least k nodes remaining
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // not enough nodes to reverse
            temp = temp->next;
        }


        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }


        head->next = reverseKGroup(curr, k);


        return prev;
    }
};