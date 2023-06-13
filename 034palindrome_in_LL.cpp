/*not needed
    ListNode* reversell(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }*/

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        /*note: do not just reverse the LL, rather make a deepcopy of it 
        i.e. create a new LL with values stored in reverse order as that of original LL*/

        ListNode *revhead = NULL;
        ListNode *ptr = head;

        while(ptr!=NULL){
            ListNode *temp = new ListNode(ptr->val);
            temp ->next = revhead;
            revhead = temp;

            ptr = ptr->next;
        }

        while(head && revhead){
            if(head->val != revhead->val){
                return false;
            }
            head = head->next;
            revhead = revhead->next;
        }
        return true;
    }
