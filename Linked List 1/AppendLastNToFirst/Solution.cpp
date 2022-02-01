Node *appendLastNToFirst(Node *head, int n)
{
    if(head == NULL || n == 0){
        return head;
    }
    Node *temp = head;
    int len = 1;
    while(temp -> next != NULL){
        temp = temp -> next;
        len++;
    }
	temp -> next = head;
    n = len-n;
    len = 1;
    temp = head;
    while(len != n){
        temp = temp -> next;
        len++;
    }
    head = temp -> next;
    temp -> next = NULL;
    return head;
}