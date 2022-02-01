Node *deleteNodeRec(Node *head, int pos) {
    if(head == NULL){
        return head;
    }
    if(head -> next != NULL && pos == 1){
        Node *a = head -> next;
        Node *b = a -> next;
        delete a;
        return head -> next = b;
    }
    if(head -> next != NULL && pos == 0){
        Node *a = head;
        delete a;
        return head = head -> next;
    }
    Node *temp = deleteNodeRec(head->next, pos-1);
    return head;
}