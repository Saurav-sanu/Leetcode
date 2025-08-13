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
class comparator{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator>pq;
        for(int i=0;i<lists.size();i++){
            ListNode* head=lists[i];
            if(head!=NULL){
                pq.push(head);
            }
        }

        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!pq.empty()){
            ListNode* topNode=pq.top();
            pq.pop();
            if(head==NULL){
                head=topNode;
                tail=topNode;
                if(tail->next!=NULL){
                    pq.push(tail->next);
                }
            }
            else{

            tail->next=topNode;
            tail=topNode;
             if(tail->next!=NULL){
                pq.push(tail->next);
            }
            }
        }
        return head;

    }
};