Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  #include<bits/stdc++.h>
using namespace std;




class edge{
  public:
    int v1;
    int v2;
    int weight;
};

bool cmp(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

int parentFinder(int parent[], int v)
{
    if(parent[v] == v)
        return v;
    else{
        while(parent[v] != v)
        {
            v = parent[v];
        }
    }
    
    return v;
}

void mst(edge* input, edge *output, int e, int n, int parent[])
{
 	int count = 0;
    
    int i=0;  // to carry on the with the count
    //int j=0; // to iterate in the output so that we can store at desired index
    
    while(count < n-1 && i < e)
    {
        int p1 = parentFinder(parent, input[i].v1);
        int p2 = parentFinder(parent, input[i].v2);
        if(p1 != p2)
        {
            output[count] = input[i];
            //j++;
            count++;
            parent[p1] = p2;
        }
        i++;
    }
    return;
}



int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        edge input[e];
        for(int i=0; i<e; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            input[i].v1 = a;
            input[i].v2 = b;
            input[i].weight = c;
        }
        sort(input, input+e, cmp);
        
    	edge output[v-1];
        int parent[v];
        for(int i=0; i<v; i++)
        {
            parent[i] = i;
        }
        mst(input, output, e, v, parent);
        
        long long int sum = 0;
        
        for(int i=0; i<v-1; i++)
        {
           //cout<<output[i].weight<<endl;
            sum += output[i].weight;
            //cout<<sum<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
