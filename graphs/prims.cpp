Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.
Input Format :
First line will contain T(number of test case), each test case follows as. 
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Weight of MST for each test case in new line.
Constraints :
1 <= T <= 10
2 <= V, E <= 10^5
1 <= wt <= 10^4
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
  
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  #include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool* visited, int* weight, int n)
{
    int minVertex = -1;
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && ((minVertex == -1) || weight[minVertex] > weight[i]))  // have done a mistake here --> to inclose last two conditions inside a bracket so that both two of them checked
        {
            minVertex = i;
        }
    }
    return minVertex;
}


long long int prims(int** graph, int n)
{
    bool* visited = new bool[n]();
    int* parent = new int[n];
    int* weight = new int[n];
    
    for(int i=0; i<n; i++)
    {
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    
    for(int i=0; i<n-1; i++)
    {
        // get minVertex which is unvisited vertex with minimum weight
        int minVertex = getMinVertex(visited, weight, n);
        visited[minVertex] = true;
        
        // explore all the neighbours of minvertex and update parent and weight array accordingley
        for(int j=0; j<n; j++)
        {
            if(graph[minVertex][j] != 0 && !visited[j])
            {
                if(weight[j] > graph[minVertex][j])
                {
                    weight[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
                
        }
        
    }
    long long int sum = 0;
    for(int i=1; i<n; i++)
    {
        //int x = 
        sum += weight[i];
    }
    return sum;
}

int main()
{
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        
        int** graph = new int*[n];
        for(int i=0; i<n; i++)
        {
            graph[i] = new int[n];
            for(int j=0; j<n; j++)
            {
                graph[i][j] = 0;
            }
        }
        
        for(int i=0; i<e; i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            
            if(graph[x][y] == 0)
            {
                graph[x][y] = w;
            	graph[y][x] = w;
            }
            else        // have done a error here--> consider the case where there can be two edges between the two same vertices
            {
                if(graph[x][y] > w)
                {
                    graph[x][y] = w;
            		graph[y][x] = w;
                }
            }
        }
        
        cout<<prims(graph, n)<<endl;
    }
    return 0;
}
