//APPROACH ONE

ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* temp = head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }

        int mid = cnt/2;

        while(mid--){
            head=head->next;
        }

        return head;
    }


//APPROACH TWO

Node *findMiddle(Node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    }

    if(head->next->next==NULL){
        return head->next;
    }

    Node* slow=head;
    Node* fast=head->next;
    
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }

    return slow;
}
