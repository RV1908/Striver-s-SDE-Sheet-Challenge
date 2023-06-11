void deleteNode(LinkedListNode<int> * node) {
    if(node==NULL){
        return;
    }

    //coping the value of next node
    node->data=node->next->data;

    //deleting the next node
    node->next=node->next->next;
}
