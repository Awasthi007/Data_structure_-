Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input BST
and H is the height of the input BST
*/
 
#include <climits>
class bstSubtreeReturn {
public:
int max;
int min;
int height;
bool isBST;
};
bstSubtreeReturn largestBSTSubtreeHelper(BinaryTreeNode<int> *root) {
if (root == NULL) {
bstSubtreeReturn ans;
ans.max = INT_MIN;
ans.min = INT_MAX;
ans.isBST = true;
ans.height = 0;
return ans;
}
bstSubtreeReturn left = largestBSTSubtreeHelper(root->left);
bstSubtreeReturn right = largestBSTSubtreeHelper(root->right);
if (!(right.isBST && right.min > root->data)) {
right.isBST = false;
}
if (!(left.isBST && left.max < root->data)) {
left.isBST = false;
}
bstSubtreeReturn ans;
if (!left.isBST || !right.isBST || root->data < left.max || root->data > right.min) {
if (left.height > right.height) {
left.isBST = false;
return left;
} else {
right.isBST = false;
return right;
}
}
ans.isBST = true;
ans.min = min(left.min, min(right.min, root->data));
ans.max = max(left.max, max(right.max, root->data));
ans.height = max(left.height, right.height) + 1;
return ans;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
return largestBSTSubtreeHelper(root).height;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

***********************************************************/
#include<bits/stdc++.h>

class ans
{
  public:
    int mini;
    int maxi;
    bool isBST;
    int h;
};

ans helper(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        ans a;
        a.mini = INT_MAX;
        a.maxi = INT_MIN;
        a.isBST = true;
        a.h = 0;
        return a;
    }
    ans leftans = helper(root->left);
    ans rightans = helper(root->right);
    
    ans temp;
     temp.mini = min(root->data,min(leftans.mini,rightans.mini));
     temp.maxi = max(root->data,max(leftans.maxi,rightans.maxi));
     temp.isBST = root->data > leftans.maxi && root->data <= rightans.mini && leftans.isBST && rightans.isBST;
     if(temp.isBST)
     {
         temp.h = max(leftans.h,rightans.h)+1;
     }
    else
         temp.h = max(leftans.h,rightans.h);
    
    return temp;
        
}


int largestBSTSubtree(BinaryTreeNode<int> *root) 
{
    // Write your code here
    ans a = helper(root);
    return a.h;
}

