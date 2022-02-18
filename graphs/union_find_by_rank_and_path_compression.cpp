int parent[100000];
int rank[100000];

void makeSet(){
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// 7->6->4->3  

int findPar(int node)
{
    if(node == parent[node])
    {
        return node;
    }

    return parent[node] = findPar(parent[node]);  // does the path compression
}

void union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = v;
        rank[u]++;
    }
}



void main()
{
    makeSet();
    int m;
    cin>>m;

    while(m--)
    {
        int u,v;
        union(u,v);
    }
    // if 2 and 3 belong to the same component

    if(findPar(2) != findPar(3)){
        cout<<"different"<<endl;
    }
    else
        cout<<"same";
}
