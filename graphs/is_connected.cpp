Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Print "true" or "false" for each test case in new line
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
1
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
1
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
  
  
  
  
  
  
  
  
  
  
  
  
  #include<bits/stdc++.h>
using namespace std;

void dfs(int** graph, int v, int sv, bool* visited)
{
    visited[sv] = true;
    
    for(int i=0; i<v; i++)
    {
        if(graph[sv][i] == 1 && !visited[i])
        {
            dfs(graph, v, i, visited);
        }
    }
    return;
}

int main()
{
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        
        int** graph = new int*[v];
        for(int i=0; i<v; i++)
        {
            graph[i] = new int[v];
            for(int j=0; j<v; j++)
            {
                graph[i][j] = 0;
            }
        }
        
        for(int i=0; i<e; i++)
        {
            int a,b;
            cin>>a>>b;
            
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        
        bool* visited = new bool[v];
        for(int i=0; i<v; i++)
        {
            visited[i] = false;
        }
        
        dfs(graph, v, 0, visited);
        bool flag = true;
        for(int i=0; i<v; i++)
        {
            if(!visited[i])
                flag = false;
        }
        
        if(flag)
        {
            cout<<"true"<<endl;
        }
        else
            cout<<"false"<<endl;
    }
    return 0;
}
  
  
  
  
  
  
  
