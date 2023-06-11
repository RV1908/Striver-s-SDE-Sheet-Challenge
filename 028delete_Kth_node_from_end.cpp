ListNode* removeNthFromEnd(ListNode* head, int n) {
        //A dummy linkedlist is used to get it started
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* fast = start;
        ListNode* slow = start;

        for(int i=1; i<=n; i++){
            fast=fast->next;
        }

        while(fast->next!=NULL){
            fast=fast->next;
            //now slow reaches Nth node from the end
            slow=slow->next;
        }

        ListNode* temp = slow->next;
        slow->next=slow->next->next;
        delete temp;

        return start->next;
    }
