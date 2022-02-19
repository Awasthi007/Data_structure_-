Floyd-Warshall Algorithm
Send Feedback
You are given an undirected weighted graph G with n vertices. And Q queries, each query consists of two integers a and b and you have print the distance of shortest path between a and b.
Note: If there is no path between a and b print 10^9
Input Format:
First line of Input will contain T(number of test cases), each test case follows as.
Line1: contains two space-separated integers N and M denoting the number of vertex and edge in graph.
Next M line contain three space-separated integers a, b, c denoting the edge between a and b with weight c.
Next line will contain Q (number of queries)
Next Q lines will contain two space-separated integers a and b.
Output Format:
For each query of each test case print the answer in a newline.
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= M <= 10^4
1 <= Q <= 10^4
1 <= wt <= 10^5 (for each edge)
Note: Graph may contain multiple edges.
Sample Input:
1
3 6
3 1 4
1 3 17
2 3 2
1 3 7
3 2 11
2 3 15
3
1 1 
2 2 
2 3 
Sample output:
0
0
2
  
  
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  #include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
typedef long long int ll;

void floyd(ll** graph, ll** distance, int n)
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(distance[i][k] != inf && distance[k][j] != inf && (distance[i][k] + distance[k][j] < distance[i][j]))
                {
                    distance[i][j] = distance[i][k] + distance[k][j] ;
                }
            }
        }
    }
}


int main()
{
    
    // write your code here
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n,m;
		cin>>n>>m;
        
        ll** graph = new ll*[n+1];
        for(int i=0; i<=n; i++)
        {
            graph[i] = new ll[n+1];
            fill(graph[i], graph[i]+n+1, inf);
            
        }
        
        
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            
            if(graph[x][y] == inf)
            {
                graph[x][y] = w;
            }
            else
            {
                if(graph[x][y] > w)
                {
                    graph[x][y] = w;
                }
            }
            
            
            
            if(graph[y][x] == inf)
            {
                graph[y][x] = w;
            }
            else
            {
                if(graph[y][x] > w)
                {
                    graph[y][x] = w;
                }
            }
        }
        for(int i=0; i<=n; i++)
        {
            graph[i][i] = 0;
        }
        
        ll** distance = new ll*[n+1];
            for(int i=0; i<=n; i++)
            {
                distance[i] = new ll[n+1];
                for(int j=0; j<=n; j++)
                {
                    distance[i][j] = graph[i][j];
                }
            }
            
        floyd(graph, distance, n);
        
        ll q;
        cin>>q;
        
        while(q--)
        {
         	
            
            int a,b;
            cin>>a>>b;
            cout<<distance[a][b]<<endl;
            
        }
    }
    return 0;
}
  
