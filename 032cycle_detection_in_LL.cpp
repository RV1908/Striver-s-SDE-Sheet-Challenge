bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        bool flag = false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL ){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        return flag;
    }
