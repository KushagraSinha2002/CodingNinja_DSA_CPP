/*
Node with maximum child sum

Given a generic tree, find and return the node for which sum of its data and data of all its
child nodes is maximum. In the sum, data of the node and data of its immediate child nodes
has to be taken.

Input format :
The first line of input contains data of the nodes of the tree in level order form.
The order is: data for root node, number of children to root node, data of each of
child nodes and so on and so forth for each node. The data of the nodes of the tree is
separated by space. 

Output format :
The first and only line of output contains the data of the node with maximum sum, as described
in the task.

Constraints:

Time Limit: 1 sec

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

Sample Output 1 :
1

Sample Input 2 :
5 0

Sample Output 2 :
5

Sample Input 3 :
1 1 2 1 3 1 4 1 5 0

Sample Output 3 :
4

Sample Input 4 :
6 3 4 10 9 2 3 2 1 1 3 12 7 5 0 0 2 11 8 0 0 0 0 0

Sample Output 4 :
9
*/


#include <iostream>
#include <queue>
#include <vector>
#include<climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

template <typename T>
class MaxNode{
    public:
    TreeNode<T>* node;
    int sum;
};
MaxNode<int>* MaxNodeHelper(TreeNode<int>* root){
    if(root==NULL){
        MaxNode<int>* pair = new MaxNode<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
    }
    // Get Sum of the root node with immediate children
    int sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum += root->children[i]->data;
    }
    // Get Sum of the next node with immediate children
    MaxNode<int>* ans = new MaxNode<int>();
    ans->node = root;
    ans->sum = sum;
    for(int i=0;i<root->children.size();i++){
        MaxNode<int>* child = new MaxNode<int>();
        // call recursion
        child = MaxNodeHelper(root->children[i]);
        if(child->sum > ans->sum){
            ans->node = child->node;
        }
    }
    return ans;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    return MaxNodeHelper(root)->node;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}