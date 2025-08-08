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
    // int getlength(ListNode* head){
    //     int len=0;
    //     ListNode* temp=head;
    //     while(temp!=NULL){
    //         len++;
    //         temp=temp->next;
    //     }
    //     return len;
    // }
    ListNode* middleNode(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                //main yha keh skta hu k fast 2 step chal liye h
                //ab slow ko bhi chaloa ek step
                slow=slow->next;
            }

        }
        return slow;


        // int n=getlength(head);
        // int position=n/2 + 1;
        // int currPos=1;
        // ListNode* temp=head;
        // while(currPos!=position){
        //     currPos++;
        //     temp=temp->next;
        // }
        // return temp;
    }
};