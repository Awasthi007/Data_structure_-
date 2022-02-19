Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
1 <= T <= 10
2 <= V, E <= 10^3
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  #include<bits/stdc++.h>
using namespace std;

int findminDistance(bool* visited, int* distance, int n)
{
    int vertex = -1;
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i] &&(vertex == -1 || distance[vertex] > distance[i]))
        {
            vertex = i;
        }
    }
    
    return vertex;
}


void dijkstra(int** graph, int n)
{
    bool* visited = new bool[n]();
    int* distance = new int[n];
    fill(distance, distance+n, INT_MAX);
    
    distance[0] = 0;
    
    for(int i=0; i<n-1; i++)
    {
        int minD = findminDistance(visited, distance, n);
        visited[minD] = true;
        
        for(int j=0; j<n; j++)
        {
            if(graph[minD][j] != 0 && !visited[j])
            {
                if(distance[j] > (distance[minD] + graph[minD][j]))
                {
                    distance[j] = (distance[minD] + graph[minD][j]);
                }
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
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
            else
            {
                if(graph[x][y] > w)
                {
                    graph[x][y] = w;
            		graph[y][x] = w;
                }
            }
        }
        
        dijkstra(graph, n);
        
        
    }
    return 0;
}
