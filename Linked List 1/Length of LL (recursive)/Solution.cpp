int length(Node *head) {
    if(head == NULL){
        return 0;
    }
    return length(head -> next)+1;
}