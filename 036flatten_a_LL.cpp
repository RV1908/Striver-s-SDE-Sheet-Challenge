Node* merge(Node* a, Node* b){
    Node* dummy = new Node(0);
    Node* res = dummy;
    
    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            dummy->bottom=a;
            a=a->bottom;
            dummy=dummy->bottom;
        }
        else{
            dummy->bottom = b;
            b = b->bottom;
            dummy=dummy->bottom;
        }
    }
    
    if(a){
        dummy->bottom=a;
    }
    else{
        dummy->bottom=b;
    }
    
    return res->bottom;
}
    
Node *flatten(Node *root)
{

    if(root==NULL || root->next==NULL){
        return root;
    }
    
    root->next = flatten(root->next);
    
    root = merge(root,root->next);
    
    root->next=NULL;
    
    return root;
}

