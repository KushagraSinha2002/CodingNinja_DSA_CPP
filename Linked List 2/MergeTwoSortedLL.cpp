Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    Node *tempH = NULL, *tempT = NULL, *temp1 = NULL, *temp2 = NULL, *store = NULL;
    if(head1->data <= head2->data){
        
        tempH = head1;
        tempT = head1;
        temp1 = head1->next;
        temp2 = head2;
    }
    else {
        tempH = head2;
        tempT = head2;
        temp1 = head1;
        temp2 = head2->next;
    }
    
    while(temp1 != NULL && temp2 != NULL){
    	if(temp1->data <= temp2->data){
            tempT->next = temp1;
            tempT = tempT->next;
            temp1 = temp1->next;
        }
        else if(temp2->data < temp1->data){
            tempT->next = temp2;
            tempT = tempT->next;
            temp2 = temp2->next;
        }
    }
    
    if(temp1 != NULL){
        tempT->next = temp1;
    }
    else if(temp2 != NULL){
        tempT->next = temp2;
    }
    return tempH;
}