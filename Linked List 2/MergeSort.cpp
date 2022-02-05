/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *getMidPoint(Node *head)
{
    Node *slow = head, *fast = head->next, *temp = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoSortedLL(Node *head1, Node*head2){
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    
    Node *tempH, *tempT, *temp1=head1, *temp2=head2;
    if(head1->data <= head2->data){
        tempH = head1;
        tempT = head1;
        temp1 = head1->next;
    }
    else if(head2->data < head1->data){
        tempH = head2;
        tempT = head2;
        temp2 = head2->next;
    }
    
	while(temp1 != NULL && temp2 !=NULL){
        if(temp1->data <= temp2->data){
            tempT->next = temp1;
            tempT = temp1;
            temp1 = temp1->next;
        }
        else if(temp2->data < temp1->data){
            tempT->next = temp2;
            tempT = temp2;
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

Node *mergeSort(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
	Node *midPoint = getMidPoint(head), *temp = head, *breakMidPoint = midPoint->next;
	midPoint->next = NULL;
	Node *head1 = mergeSort(temp);
	Node *head2 = mergeSort(breakMidPoint);
	Node *sortHead = mergeTwoSortedLL(head1, head2);
    
    return sortHead;
}