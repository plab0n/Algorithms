#include <bits/stdc++.h>
using namespace std;
int in[105];
vector<int>adj[105];
void topSort(int n)
{
    queue<int>Q;
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            Q.push(i);
        }
    }
    while(!Q.empty())
    {
        int u = Q.front();
        printf("%d ",u);
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            in[adj[u][i]]--;
            if(in[adj[u][i]]==0)
                Q.push(adj[u][i]);
        }
    }
    printf("\b\n");
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)return 0;
        memset(in,0,sizeof(in));
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            in[v]++;
        }
        topSort(n);
    }
}
