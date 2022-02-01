Node *deleteNode(Node *head, int pos)
{
    Node *temp = head, *a = head, *b = head;
    int count = 0;
    if(head == NULL){
        return 0;
    }
    
    if(pos == 0){
        head = head -> next;
        delete temp;
        return head;
    }
    
    while(temp -> next != NULL && count < pos-1){
        count++;
        temp = temp -> next;
    }
    
    if(temp -> next != NULL ){
        a = temp -> next;
        b = a -> next;

        temp -> next = b;
        delete a;
    }
    return head;
}
