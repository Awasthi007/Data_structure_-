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


int MaxXor(trieNode* head, int* arr, int n)
{
	int max_xor = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		trieNode* cur = head;
		int cur_xor = 0;
		int val = arr[i];
		for (int j = 31; j >= 0; j--)
		{
			int bit = (val >> j) & 1;
			if (bit == 0)
			{
				if (cur->right)
				{
					cur_xor += pow(2, j);
					cur = cur->right;
				}
				else
				{
					cur = cur->left;
				}

			}
			else
			{
				if (cur->left)
				{
					cur_xor += pow(2, j);
					cur = cur->left;
				}
				else
				{
					cur = cur->right;
				}
			}
		}
		max_xor = max(cur_xor, max_xor);
	}
	return max_xor;
}



int main()
{


#ifndef ONLINE_JUDGE
	//for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
	//for getting output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	trieNode* head = new trieNode();
	for (int i = 0; i < n; i++)
	{
		insert(arr[i], head);
	}
	cout << MaxXor(head, arr, n);


	return 0;
}
