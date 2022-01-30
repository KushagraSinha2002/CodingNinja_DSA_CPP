int length(Node *head)
{
    int count = 1;
    Node *temp = head;
    if(temp == NULL){
        return 0;
    }
    while(temp -> next != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}