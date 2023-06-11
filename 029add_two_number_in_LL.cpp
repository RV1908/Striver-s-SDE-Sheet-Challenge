ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }

        if(l2==NULL){
            return l1;
        }

        ListNode* sumnode=new ListNode();
        ListNode* temp = sumnode;

        int carry =0;
        
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }

            sum+=carry;
            carry=sum/10;

            ListNode* nodey = new ListNode(sum%10);
            temp->next=nodey;
            temp=temp->next;
        }

        //hence the sumnode was used just to keep tab on the head of the solution as temp kept moving forward
        return sumnode->next;
    }
