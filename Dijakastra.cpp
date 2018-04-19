#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second

using namespace std;

vector<int>path;
vector<int>adj[100009];
int cost[10009][10009];
int d[100009];
int val,loc=0;

int dijakastra(int s)
{
    priority_queue<pii>pq;
    pq.push(make_pair(s,0));
    d[s] = 0;

    while(!pq.empty())
    {
        int u = pq.top().f;
        //cout<<u<<endl;
        pq.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            //cout<<d[u]<<endl<<cost[u][adj[u][i]]<<endl;

            if(d[u]+cost[u][adj[u][i]]<d[adj[u][i]])
            {
                path.push_back(adj[u][i]);
                d[adj[u][i]] = d[u]+cost[u][adj[u][i]];
                pq.push(make_pair(adj[u][i],d[u]));
            }
        }
    }
}
int main()
{
    int node,edge,i;
    cin>>node>>edge;
    cost[node+1][edge+1];
    for(i=1; i<=edge; i++)
    {
        int x,y,cst;
        cin>>x>>y>>cst;
        adj[x].push_back(y);
        cost[x][y] = cst;
    }
    int q;
    cin>>q;
    for(i=1; i<=node; i++)
        d[i] = 1e8;
    dijakastra(1);


    for(i=0; i<path.size(); i++)
        cout<<path[i]<<" ";

    cout<<endl;
}
