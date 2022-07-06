/*
Structurally identical

Given two generic trees, return true if they are structurally identical. Otherwise return false.

Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the
same way, then the trees are called identical.  

Input format :
The first line of input contains data of the nodes of the first tree in level order form.
The order is: data for root node, number of children to root node, data of each of child nodes
and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line of input contains data of the nodes of the second tree in level order form.
The order is: data for root node, number of children to root node, data of each of child nodes
and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format :
The first and only line of output contains true, if the given trees are structurally identical
and false, otherwise.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
true

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0

Sample Output 2:
false

Sample Input 3 :
1 3 20 3 40 1 90 2 50 6 1 100 1 150 17 1000 2000 3000 4000 5000 6000 7000 85 86 87 88 89 92 93 94 95 96 1 80 1 83 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 3 2 3 4 1 6 1 5 1 7 0 0 1 8 0

Sample Output 3:
false

Sample Input 4 :
1 10 10 20 30 40 50 60 70 80 90 100 1 110 1 120 1 130 1 140 1 150 1 160 1 170 1 180 1 190 1 200 1 220 0 0 0 0 0 0 0 0 0 1 230 1 270 2 300 390 0 0
1 1 2 2 30 4 1 5 1 60 1 70 1 8 1 9 1 100 0 0

Sample Output 4:
false

Sample Input 5 :
1 3 10 15 30 0 1 62 1 90 1 70 2 82 100 1 80 0 0 0
1 3 10 15 30 0 1 62 1 90 1 70 2 82 100 1 80 0 0 0

Sample Output 5:
true

*/

#include <iostream>
#include <queue>
#include <vector>
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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    bool child = true;
    if(root1->data != root2->data){
        return false;
    }
    if(root1->children.size() != root2->children.size()){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        child = areIdentical(root1->children[i],root2->children[i]);
        if(child==false){
            return child;
        }
    }
    return child;
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
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}