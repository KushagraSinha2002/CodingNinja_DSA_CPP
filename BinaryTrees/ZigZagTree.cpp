/**********************************************************
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

#include<bits/stdc++.h>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    while(s1.size()!=0)
    {
        while(s1.size()!=0)
        {
        BinaryTreeNode<int>* top=s1.top();
        s1.pop();
        if(top!=NULL)
        {
            cout<<top->data<<" ";
            if(top->left!=NULL)
            {
                s2.push(top->left);
            }
            if(top->right!=NULL)
            {
                s2.push(top->right);
            }
        }
        }
        cout<<"\n";
        while(s2.size()!=0)
        {
            BinaryTreeNode<int>* top=s2.top();
            s2.pop();
            if(top!=NULL)
            {
                cout<<top->data<<" ";
                if(top->right!=NULL)
                {
                    s1.push(top->right);
                }
                if(top->left!=NULL)
                {
                    s1.push(top->left);
                }
            }
        }
        cout<<"\n";
    }
    
}