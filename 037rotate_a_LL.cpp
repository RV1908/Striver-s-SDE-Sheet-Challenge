ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==nullptr){
            return head;
        }

        int len=1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }

        //making a circular linked list
        temp->next=head;
        //to find the value of k if k>len
        k=k%len;

        //remaining shoe=ws the number of steps we need to move
        int remaining=len-k;
        while(remaining--){
            temp=temp->next;
        }


        //int the example of 1 2 3 4 5 
        //temp->val=3
        //hence the operations below are performed
        head=temp->next;
        temp->next=nullptr;

        return head;
    }
