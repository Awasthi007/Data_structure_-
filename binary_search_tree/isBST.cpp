Check if a Binary Tree is BST
Send Feedback
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
  
  ................................................................................................................................
  ................................................................................................................................
  
  ***********************************************************/
#include<bits/stdc++.h>
/*
int maximum(BinaryTreeNode<int> *root)
{
    if(root == NULL)
        return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) 
{
	// Write your code here
    if(root == NULL)
        return true;
    int maxx = maximum(root->left);
    int minn = minimum(root->right);
    
    return (root->data >= maxx && root->data <= minn && isBST(root->left) && isBST(root->right)); 
}
*/
/*
class temp
{
    public:
    int minimum;
    int maximum;
    bool bst;
};

temp bsthelper(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        temp ans;
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        ans.bst = true;
        
        return ans;
    }
    
    temp leftans = bsthelper(root->left);
    temp rightans = bsthelper(root->right);
    temp ans;
    ans.minimum = min(root->data,min(leftans.minimum,rightans.minimum));
    ans.maximum = max(root->data,max(leftans.maximum,rightans.maximum));
    ans.bst = root->data >= leftans.maximum && root->data <= rightans.minimum && leftans.bst && rightans.bst;
    return ans;
}


bool isBST(BinaryTreeNode<int> *root) 
{
    temp t = bsthelper(root);
    return t.bst;
    
}

*/
bool bsthelper(BinaryTreeNode<int>* root,int min,int max)
{
    if(root == NULL)
        return true;
    if(root->data < min || root->data > max)
        return false;
    bool isleftok = bsthelper(root->left,min,root->data-1);
    bool isrightok = bsthelper(root->right,root->data,max);
    
    return isleftok && isrightok;
}

bool isBST(BinaryTreeNode<int> *root) 
{
	return bsthelper(root,INT_MIN,INT_MAX);
}


