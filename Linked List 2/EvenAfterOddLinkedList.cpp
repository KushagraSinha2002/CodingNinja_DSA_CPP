Node *evenAfterOdd(Node *head)
{
    if(head == NULL || head->next==NULL){
        return head;
    }
    
    Node *temp = head, *oddHead=NULL, *oddTail=NULL, *evenHead=NULL, *evenTail=NULL;
    int count = 1;
    
    while(temp != NULL){
        if(temp->data % 2 != 0 && oddHead == NULL){ // ODD
            oddHead = temp;
            oddTail = temp;
            temp = temp->next;
        }
        else if(temp->data % 2 == 0 && evenHead ==NULL){ // EVEN
            evenHead = temp;
            evenTail = temp;
            temp = temp->next;
        }
        
        if(temp->data%2 != 0 && oddHead != NULL ){ // ODD
            oddTail->next = temp;
            oddTail = oddTail->next;
        }
        if(temp->data%2 == 0 && evenHead != NULL ){ // EVEN
            evenTail->next = temp;
            evenTail = evenTail->next;
        }
        
        temp = temp->next;
    }
    
    if(oddTail != NULL && evenHead != NULL){
        oddTail->next = evenHead;
    	evenTail->next = NULL;
    }
    
    
    if(oddHead==NULL){
        return evenHead;
    }
    else{
        return oddHead;
    }
}