Node *removeDuplicates(Node *head)
{
    if(head == NULL){
        return head;
    }
    Node *temp = head;
    Node *a = temp -> next;
    Node *b = NULL;
    
    while(a != NULL){
        if(temp -> data == a -> data){
            b = a;
            a = a -> next;
            temp -> next = a;
            delete b;
        }
        else{
        	temp = temp -> next;
        	a = a -> next;
        }
    }
    return head;
}