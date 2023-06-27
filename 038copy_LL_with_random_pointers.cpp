Node* copyRandomList(Node* head) {
        //APPROACH ONE
        /*using map tc-O(n), sc-O(n)*/


LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    map<LinkedListNode<int> *,LinkedListNode<int> *> mp;
    //map of original node to its clone node
    
    LinkedListNode<int> *temp = head;
    
    while(temp!=NULL){
        LinkedListNode<int> * nodey = new LinkedListNode<int>(temp->data);
        mp[temp]=nodey;
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(temp->next){
            mp[temp]->next = temp->next;
        } 
        else{
            mp[temp]->next=NULL;
        }

        if(temp->random){
            mp[temp]->random = temp->random;
        }
        else{
            mp[temp]->random = NULL;
        }

        temp=temp->next;
    }

    LinkedListNode<int> * ans = mp[head];
    
    return ans;
}


        

        //APPROACH TWO
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
