int findNode(Node *head, int n){
    if(head == NULL){
        return -1;
    }
    if(head -> data == n){
        int index = 0;
        return index;
    }
    int ans = findNode(head->next,n);
    if(ans == -1){
        return ans;
    }
    else{
        return ans+1;
    }
}