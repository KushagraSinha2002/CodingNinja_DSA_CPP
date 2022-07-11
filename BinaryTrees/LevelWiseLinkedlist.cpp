/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> v;
    if(root==NULL){
        return v;
    }
    Node<int>* head=NULL,*tail=NULL;
    queue<BinaryTreeNode<int> *> previousnode;
    previousnode.push(root);
    previousnode.push(NULL);
    while(previousnode.size()!=0){
        BinaryTreeNode<int> * front=   previousnode .front();
        previousnode.pop();
        if(front==NULL){
            v.push_back(head);
            head=NULL;
            tail=NULL;
            if(previousnode.empty()){
                break;
            }

            previousnode.push(NULL);  

        }
        else{
            if(front->left!=NULL){
                previousnode.push(front->left);}
            if(front->right!=NULL){
                previousnode.push(front->right); }

            Node<int>* n1=new Node<int>(front->data); 
            if(head==NULL){
                head=n1; tail=n1;
            }
            else{
                tail->next=n1;
                tail=n1;
            }


        }

    }

    return v;



}