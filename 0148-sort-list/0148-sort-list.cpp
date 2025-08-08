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
ListNode *merge(ListNode* left,ListNode* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy;

    while(left!=NULL && right!=NULL){
        if(left->val<=right->val){
            temp->next=left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;

        }
        temp=temp->next;
    }
    if(left!=NULL){
        temp->next=left;
    }
    else{
        temp->next=right;
    }

    return dummy->next;
    
}
ListNode * middle(ListNode* head){
    if(head==NULL ||head->next==NULL){
        return head;
    }

    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;

}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* midle=middle(head);
        //divide 
        ListNode* right=midle->next;
        midle->next=NULL;
        ListNode* left=head;

        //sort
        ListNode* lft=sortList(left);
        ListNode* rght=sortList(right);

        return merge(lft,rght);

    }
};