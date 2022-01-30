void printIthNode(Node *head, int i)
{
    Node *temp = head;
    int count = 0;
    int index = i;
    
    while(temp != NULL){
        if(count == index){
            cout << (temp -> data) << endl;
            return;
        }
        else{
            count++;
            temp = temp -> next;
        }
    }
    
}