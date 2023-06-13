ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* entry=head;
        while(fast->next!=NULL && fast->next->next!=NULL ){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                while(entry!=slow){
                    slow=slow->next;
                    entry=entry->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
