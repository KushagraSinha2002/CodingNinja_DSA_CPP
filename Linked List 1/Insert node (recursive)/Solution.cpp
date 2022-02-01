Node* insertNode(Node *head, int i, int data) {
    if(head != NULL && i == 0){
		Node *newNode = new Node(data);
        newNode -> next = head;
        return head = newNode;
    }
    if(head != NULL && i == 1){
        Node *newNode = new Node(data);
        newNode -> next = head -> next;
        head -> next = newNode;
        return head;
    }
    if(head == NULL){
        return head;
    }
    Node *temp = insertNode(head -> next, i-1, data);
    return head;
}