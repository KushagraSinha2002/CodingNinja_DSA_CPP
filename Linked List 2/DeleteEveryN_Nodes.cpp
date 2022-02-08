Node *skipMdeleteN(Node *head, int M, int N)
{
    if(head == NULL || head->next ==NULL || N==0){
        return head;
    }
    if(M==0){
        return NULL;
    }
	Node *temp = head;
    int c1 = 1, c2 = 0;
    
    while(temp != NULL){
        if(c1==M){
            c1= 1;
            Node *connect = temp;
            temp=temp->next;
            while(c2!=N && temp!=NULL){
                Node* store = temp;
                temp=temp->next;
                delete store;
                c2++;
            }
            c2=0;
            connect->next = temp;
        }
        c1++;
        if(temp!=NULL)
        temp=temp->next;
    }
    return head;
}