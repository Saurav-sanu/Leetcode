/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        Node* newHead=NULL;
        Node* prev=NULL;

        while(curr){
            Node * temp=new Node(curr->val);
            mp[curr]=temp;

            if(newHead==NULL){
                newHead=temp;
                prev=newHead;
            }
            else{
                prev->next=temp;
                prev=temp;
            }

            curr=curr->next;
        }

        //random pointer
        curr=head;
        Node* newCurr=newHead;

        while(curr){
            if(curr->random==NULL){
                newCurr->random=NULL;
            }
            else{
                newCurr->random=mp[curr->random];
            }
            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;


    }
};