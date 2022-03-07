Maximum XOR Subarray
Send Feedback
Given an array of N integers, find the subarray whose XOR is maximum.
Input Format:
First line of input contains an integer N, representing number of elements in array.
Next line contains N space-separated integers.
Constraints:
1 <= N <= 10^6
1 <= A[i] <=10^5 
Output Format:
Print XOR of the subarray whose XOR of all elements in subarray is maximum over all subarrays.
Sample Input 1:
4
1 2 3 4
Sample Output 1:
7
  
  
  
  // define ctrl m to break infinite loop
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
#define vi vector<int>

class trieNode
{
public:
	trieNode* left;
	trieNode* right;
    
    trieNode()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(int n, trieNode* head)
{
	trieNode* cur = head;

	for (int i = 31; i >= 0; i--)
	{
		int bit = (n >> i) & 1;

		if (bit == 0)
		{
			if (!cur->left)
			{
				cur->left = new trieNode();
			}
			cur = cur->left;
		}
		else
		{
			if (!cur->right)
			{
				cur->right = new trieNode();
			}
			cur = cur->right;
		}
	}
}


// int MaxXor(trieNode* head, int* arr, int n)
// {
// 	int max_xor = INT_MIN;
// 	for (int i = 0; i < n; i++)
// 	{
// 		trieNode* cur = head;
// 		int cur_xor = 0;
// 		int val = arr[i];
// 		for (int j = 31; j >= 0; j--)
// 		{
// 			int bit = (val >> j) & 1;
// 			if (bit == 0)
// 			{
// 				if (cur->right)
// 				{
// 					cur_xor += pow(2, j);
// 					cur = cur->right;
// 				}
// 				else
// 				{
// 					cur = cur->left;
// 				}

// 			}
// 			else
// 			{
// 				if (cur->left)
// 				{
// 					cur_xor += pow(2, j);
// 					cur = cur->left;
// 				}
// 				else
// 				{
// 					cur = cur->right;
// 				}
// 			}
// 		}
// 		max_xor = max(cur_xor, max_xor);
// 	}
// 	return max_xor;
// }

int MaxXor(trieNode* head, int val)
{
    int ans = 0;
    trieNode* cur = head;
    if (head == NULL)
        return 0;
    for(int j=31; j>=0; j--)
    {
        int bit = (val>>j)&1;
        
        // if(!cur)
        // {
        //     return 0;
        // }
        
        if(bit == 0)
        {
            if(cur->right != NULL)         // 
            {
                cur = cur->right;
                ans += pow(2,j);
            }
            else
            {
                cur = cur->left;
            }
        }
        else
        {
            if(cur->left != NULL)
            {
                ans += pow(2,j);
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
    }
    return ans;
}



int main()
{


// #ifndef ONLINE_JUDGE
// 	//for getting input from input1.txt
// 	freopen("input1.txt", "r", stdin);
// 	//for getting output to output1.txt
// 	freopen("output1.txt", "w", stdout);
// #endif

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);


	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	trieNode* head = new trieNode();
    
	
    int Max_xor = INT_MIN;
    int cur = arr[0];
    insert(cur, head);
    for(int i=1; i<n; i++)
    {
        cur = cur ^ arr[i];
        
    	Max_xor = max(Max_xor, MaxXor(head, cur));
        insert(cur, head);
    }
    
    cout<<Max_xor<<endl;


	return 0;
}

