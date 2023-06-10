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
    //approach two
    /*void reverse(ListNode* &head,ListNode* curr,ListNode* prev){
        if(curr==NULL){
            head=prev;
            return;
        }
       
        reverse(head,curr->next, curr);
        curr->next=prev;

    }*/

    ListNode* reverseList(ListNode* head) {
        //APPROACH ONE
        
        /*if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* newhead = NULL;
        ListNode* nxt;
        while(head!=NULL){
            nxt=head->next;
            head->next=newhead;
            newhead=head;
            head=nxt;
            
        }

        return newhead;*/



        //APPROACH TWO
        /*ListNode* curr=head;
        ListNode* prev=NULL;
        reverse(head,curr,prev);
        return head;*/



        //APPROACH THREE
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* newhead = reverseList(head->next);

        head->next->next=head;
        head->next = NULL;

        return newhead;
    }
};
