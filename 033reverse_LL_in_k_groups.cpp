int getlen(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next=head;

        ListNode* pre=dummy;
        ListNode* curr;
        ListNode* nxt;

        int n=getlen(head);

        while(n>=k){
            curr=pre->next;
            nxt=curr->next;
            //for k-1 iterations
            for(int i=1; i<k; i++){
                curr->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                nxt=curr->next;
            }
            pre=curr;
            n=n-k;
        }
        return dummy->next;
    }
