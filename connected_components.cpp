#include <bits/stdc++.h>
using namespace std;
int vis [10009],nd,edge,temp,temp2;
vector <int> adj[10009];
void bfs(int node)
{
    queue <int>Q;
    Q.push(node);
    vis[node] = 1;
    nd = 0;
    edge = 0;
    while(!Q.empty())
    {
        nd++;
        int u = Q.front();
        Q.pop();
       // cout<<"Node: "<<u<<" "<<adj[u].size() <<endl;
        edge+=(adj[u].size());
        for(int k = 0; k<adj[u].size(); k++)
        {
            if(!vis[adj[u][k]])
            {
                int v = adj[u][k];
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
   //cout<<nd<<" "<<edge/2<<endl;
    if(edge/2==temp)
    {
        if(nd<temp2)
        {
            temp2 = nd;
        }
    }
    if(edge/2>temp)
    {
        temp = edge/2;
        temp2 = nd;
    }
}
int main ()
{
    int n,e;
    int t;
    int cas = 1;
    cin>>t;

    while(t--){
    cin>>n>>e;
    temp = 0;
    temp2 = 0;
    for(int i = 1; i<=e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(vis,0,sizeof(vis));
    for(int i=0; i<=n; i++)
    {
        if(!vis[i])
        {
            bfs(i);
        }
    }
    cout<<"Case "<<cas++<<": "<<temp<<" "<<temp2<<endl;
    for(int i=0; i<=n; i++)
    {
        adj[i].clear();
    }
    }
}
