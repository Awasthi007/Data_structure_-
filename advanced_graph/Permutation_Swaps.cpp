Permutation Swaps
Send Feedback
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.
He also believes that there are M good pairs of integers (ai, bi). Kevin can perform following operation with his permutation:
Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.
Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
Time Limit: 1 second
Sample Input 1:
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
Sample Output 1:
NO 
YES

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >&graph, int start, bool* visited, int n, vector<int> &output)
{
    visited[start] = true;
    output.push_back(start);
    
    // for(int i=1; i<=n; i++)
    // {
    //     if(!visited[i] && graph[start][i] == 1)
    //     {
    //      	dfs(graph, i, visited, n, output);   
    //     }
    // }
    
    for(int i=0;i<graph[start].size();i++){
        int curr_vertex = graph[start][i];
        if(!visited[curr_vertex]){
            dfs(graph,curr_vertex,visited,n,output);
        }
    }
}


vector<vector<int> > connected(vector<vector<int> >&graph, int n)
{
    bool* visited = new bool[n+1]();
    vector<vector<int> >  ans;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
             vector<int> output;
             dfs(graph, i, visited, n, output);
             ans.push_back(output);
            
        }
    }
    return ans;
}

int main()
{
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        vector<int> p(n+1);
        for(int i=1; i<=n; i++)
        {
//             int x;
//             cin>>x;
            
//             p.push_back(x);
            cin>>p[i];
        }
        
        vector<int> q(n+1);
        for(int i=1; i<=n; i++)
        {
//             int x;
//             cin>>x;
            
//             q.push_back(x);
            cin>>q[i];
        }
        
        // int** graph = new int*[n+1];
        // for(int i=0; i<=n; i++)
        // {
        //     graph[i] = new int[n+1]();
        // }
        
        vector<vector<int> > graph(n+1,vector<int>());
     
        
        for(int i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            
            // graph[x][y] = 1;
            // graph[y][x] = 1;
            
            graph[x].push_back(y);
            graph[y].push_back(x);
            
            
        }
        
        vector<vector<int> >vec = connected(graph, n);
        
        // for(int i=0;i<vec.size();i++){
        //     for(int j=0;j<vec[i].size();j++){
        //         cout<<vec[i][j]<< " ";
        //     }
        //     cout<<endl;
        // }
       
        //vector<vector<int>*>::iterator it = vec->begin();
        
        // unordered_set<int> s1;
        // unordered_set<int> s2;
        bool flag = true;
        
        /*
        while(it != vec->end())
        {
            vector<int>* current = *it;
            for(int i=0; i<current->size(); i++)
            {
                s1.insert(p[current->at(i)]);
                s2.insert(q[current->at(i)]);
                
            }
            if(s1 != s2)
            {
                flag = false;
                break;
            }
            it++;
        }
        */
        
        for(int i=0; i < vec.size(); i++)
        {
             unordered_set<int> s1;
            unordered_set<int> s2;
            for(int j=0; j < vec[i].size(); j++)
            {
               s1.insert(p[vec[i][j]]);
               s2.insert(q[vec[i][j]]);
                    
            }
            if(s1 != s2)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
         
    }
    return 0;
}
