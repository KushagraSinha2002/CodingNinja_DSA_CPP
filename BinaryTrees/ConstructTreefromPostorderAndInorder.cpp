/***********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    if(postLength==0)
    {
        return NULL;
    }
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(postorder[postLength-1]);

    int i=0;
    for(i=0;i<postLength;i++)
    {
        if(inorder[i]==root->data)
        {
            break;
        }
    }
    
    root->left  = buildTree(postorder,i,inorder,i);
    root->right = buildTree(postorder+i,postLength-i-1,inorder+i+1,inLength-i-1);
    return root;
    
}