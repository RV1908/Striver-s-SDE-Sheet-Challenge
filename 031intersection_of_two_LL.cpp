//APPROACH ONE
    //based on different length
    /*int getlen(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }*/

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        

        //APPROACH ONE
        /*int lena=getlen(headA);
        int lenb=getlen(headB);

        while(lena>lenb){
            headA=headA->next;
            lena--;
        }
        while(lena<lenb){
            headB=headB->next;
            lenb--;
        }

        while(headA && headB){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }

        return NULL;*/



        //APPROACH TWO
        //using two dummy nodes 
        if(headA==NULL || headB==NULL){
            return NULL;
        }

        ListNode* dummya=headA;
        ListNode* dummyb=headB;

        while(dummya!=dummyb){
            
            if(dummya==NULL){
                dummya=headA;
            }
            else{
                dummya=dummya->next;
            }

            if(dummyb==NULL){
                dummyb=headB;
            }
            else{
                dummyb=dummyb->next;
            }
        }

        return dummya;
    }
