Bellman-Ford Algorithm
Send Feedback
you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line1: contain two space-separated integers N and M denoting the number of vertex and number of edges in graph respectively.
Line2: contain two space-separated integers src, des.
Next M line will contain three space-separated integers a, b, wt representing the edge from a to b with weight wt.
Output Format:
For each test case print the distance of des from src in new line.
Note: In case of no path is found print (10 ^ 9) in that case.
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= min(800, N*(N-1))
1 <= a,b <= N
-10^5 <= wt <= 10^5
Sample Input:
1
3 6
3 1
3 1 -2
1 3 244
2 3 -2
2 1 201
3 2 220
1 2 223
Sample output:
-2
  
  
  
   IT TAKES CARE OF THE NEGATIVE EDGES AS WELL WHICH WAS THE PROBLEM WITH DIJSKTRA ALGORITHM
   
   
   #include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1000000000

class edge{
  public:
    ll v1;
    ll v2;
    ll w;
};

void bellman_ford(edge* graph, ll n, ll m, ll src, ll des)
{
    ll* weight = new ll[n+1];
    for(ll  i=0; i<=n; i++)
    {
        weight[i] = inf;
    }
    weight[src] = 0;
    
    for(ll i=1; i <= n-1; i++)   // we have to traverse n-1 times;
    {
        for(ll j=0; j<m; j++)  // we have to traverse on each and every edge taking at most edges
        {
            ll u = graph[j].v1;
            ll v = graph[j].v2;
            ll d = graph[j].w;
            
            if(weight[u] != inf && (weight[v] > weight[u] + d)) // keep updating the weights if they can be updated
            {
                weight[v] = weight[u] + d;
            }
        }
    }
    
    cout<<weight[des]<<endl;
}


int main(){
    
    // write your code here
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        
        ll src,des;
        cin>>src>>des;
        
        edge* graph = new edge[m];
        for(ll i=0; i<m; i++)
        {
            cin>>graph[i].v1>>graph[i].v2>>graph[i].w;
        }
        
        bellman_ford(graph, n, m, src, des);
    }
    return 0;
}
   
   
   
   
   
   
   
