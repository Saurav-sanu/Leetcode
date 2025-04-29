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
ListNode* mergetwolist(ListNode* list1,ListNode*list2){
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    
    if(list1->val<=list2->val){
        list1->next=mergetwolist(list1->next,list2);
        return list1;
    }
    else{
        list2->next=mergetwolist(list1,list2->next);
        return list2;

    }
}
ListNode* partition(int s,int e,vector<ListNode*>& lists){
    if(s>e){
        return NULL;
    }
   if(s==e){
    return lists[s];
   }

   int mid=s+(e-s)/2;

   ListNode *L=partition(s,mid,lists);
   ListNode *H=partition(mid+1,e,lists);

    return mergetwolist(L,H);


}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int start=0;
        int n=lists.size();
        int end=n-1;

        return partition(start,end,lists);
    }
};
