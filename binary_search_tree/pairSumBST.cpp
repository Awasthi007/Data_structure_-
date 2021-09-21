Pair sum in a BST
Send Feedback
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7




..........................////////////////////////.............................................////////////////////////////////////.......................

/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input BST
and H is the height of the input BST
*/
#include <stack>
int countNodes(BinaryTreeNode<int> *root) {
if (root == NULL) {
return 0;
}
return countNodes(root->left) + countNodes(root->right) + 1;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
if (root == NULL) {
return;
}
int totalCount = countNodes(root);
int count = 0;
stack<BinaryTreeNode<int> *> inorder;
stack<BinaryTreeNode<int> *> revInorder;
BinaryTreeNode<int> *currentNode = root;
while (currentNode != NULL) {
inorder.push(currentNode);
currentNode = currentNode->left;
}
currentNode = root;
while (currentNode != NULL) {
revInorder.push(currentNode);
currentNode = currentNode->right;
}
while (count < totalCount - 1) {
BinaryTreeNode<int> *inorderTop = inorder.top();
BinaryTreeNode<int> *revInorderTop = revInorder.top();
if (inorderTop->data + revInorderTop->data == s) {
cout << inorderTop->data << " " << revInorderTop->data << endl;
BinaryTreeNode<int> *top = inorderTop;
inorder.pop();
count++;
if (top->right != NULL) {
top = top->right;
while (top != NULL) {
inorder.push(top);
top = top->left;
}
}
top = revInorderTop;
revInorder.pop();
count++;
if (top->left != NULL) {
top = top->left;
while (top != NULL) {
  revInorder.push(top);
top = top->right;
}
}
} else if (inorderTop->data + revInorderTop->data > s) {
BinaryTreeNode<int> *top = revInorderTop;
revInorder.pop();
count++;
if (top->left != NULL) {
top = top->left;
while (top != NULL) {
revInorder.push(top);
top = top->right;
}
}
} else {
BinaryTreeNode<int> *top = inorderTop;
inorder.pop();
count++;
if (top->right != NULL) {
top = top->right;
while (top != NULL) {
inorder.push(top);
top = top->left;
}
}
}
}
}
