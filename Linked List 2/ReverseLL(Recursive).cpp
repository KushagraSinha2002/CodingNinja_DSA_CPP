Node *reverseLinkedListRec(Node *head)
{
    if(head == NULL ||head->next == NULL){
        return head;
    }
    Node *smallCal = reverseLinkedListRec(head->next), *temp = smallCal;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallCal;
}