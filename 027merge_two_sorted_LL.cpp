Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL){
        return second;
    }

    if(second==NULL){
        return first;
    }

    Node<int>* newhead;

    if(first->data<=second->data){
        newhead = first;
        first=first->next;
    }
    else{
        newhead=second;
        second=second->next;
    }

    Node<int>* curr=newhead;
    while(first!=NULL && second!=NULL){
        if(first->data<=second->data){
            curr->next=first;
            first=first->next;
        }
        else{
            curr->next=second;
            second=second->next;
        }
        curr=curr->next;
    }

    if(first!=NULL){
        curr->next=first;
    }
    else{
        curr->next=second;
    }

    return newhead;
}
