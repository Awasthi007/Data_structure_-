Search Engine
Send Feedback
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
Input Format:
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. 
Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.
Next q lines follow, each line having a string t, which needs to be completed.
Constraints:
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
Total length of all strings in database entries ≤ 10^6
Total length of all query strings ≤ 10^6
Output Format:
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
Sample Input 1:
2 1
potential 10
potent 8
pot
Sample Output 1:
10
  
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  #include<bits/stdc++.h>
using namespace std;

class trieNode
{
    public:
        trieNode** children;
        int weight;
        
        trieNode()
        {
            children = new trieNode*[26];
            for(int i=0; i<26; i++)
            {
                children[i] = 0;
            }
            weight = 0;
        }
};


void insert(trieNode* root,int weight, string s)
{
    if(s.empty())
        return;
    trieNode* child;
    int index = s[0] - 'a';
    
    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new trieNode();
         root->children[index] = child;
    }
    
    if(root->weight < weight)
    {
        root->weight = weight;
    }
    
    insert(child, weight, s.substr(1));
}

int SearchBest(trieNode* root, string s)
{
   trieNode* current = root;
   
   for(int i=0; i<s.length(); i++)
   {
       int index = s[i] - 'a';
       trieNode* temp = current->children[index];
       
       if(temp)
       {
           current = temp;
       }
       else
        return -1;
   }
   return current->weight;
}


int main()
{
    int n,q;
    cin>>n>>q;
    
    trieNode* root = new trieNode();
    
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        
        int weight;
        cin>>weight;
        
        insert(root, weight,s);
    }
    
    for(int i=0; i<q; i++)
    {
        string pre;
        cin>>pre;
        
        cout<<SearchBest(root, pre)<<endl;
    }
 
    return 0;
}
