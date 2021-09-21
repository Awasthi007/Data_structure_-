Pair Sum Binary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output Format :
Print each pair in a new line, as described in the task. 
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1
  
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  ***********************************************************/
#include<bits/stdc++.h>

void flatten(BinaryTreeNode<int> *root,vector<int>& tree)
{
    if(root == NULL)
		return;
    
    tree.push_back(root->data);
    flatten(root->left, tree);
    flatten(root->right, tree);
    return;
}


void pairSum(BinaryTreeNode<int> *root, int sum) 
{
    // Write your code here
    vector<int> tree; 
    flatten(root, tree);
    sort(tree.begin(),tree.end());
    
    int i=0;int j = tree.size()-1;
    
    while(i<j)
    {
        int temp = tree[i] + tree[j];
        if(temp > sum)
        {
            j--;
        }
        else if(temp < sum)
        {
            i++;
        }
        else
        {
            cout<<tree[i]<<" "<<tree[j]<<endl;
            i++;j--;
        }
    }
}
