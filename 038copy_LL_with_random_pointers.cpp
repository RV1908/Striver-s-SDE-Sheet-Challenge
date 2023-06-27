Node* copyRandomList(Node* head) {
        /*TC-O(n) and SC-O(1)
        1. we create a deep copy node and insert it in between of original nodes
           such that original--copy--original--copy--NULL is attained
        2. now coping the random pointers using
           itr->next->random = itr->random->next
        3. now seperating the deep copy and original LL
        */

        Node* temp =head;

        //step1
        while(temp!=NULL){
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp=temp->next->next;
        }

        //step2
        Node* itr = head;
        while(itr!=NULL){
            if(itr->random!=NULL){
                itr->next->random = itr->random->next;
            }
            itr=itr->next->next;
        }

        //step 3
        Node* dummy = new Node(0);
        temp=dummy;
        itr=head;
        Node* fast;

        while(itr!=NULL){
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp=temp->next;
            itr=fast;
        }

        return dummy->next;
    }
