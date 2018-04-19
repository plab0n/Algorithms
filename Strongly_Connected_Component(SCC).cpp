#include <bits/stdc++.h>
using namespace std;

const int lim = 10005;
vector<int>soja[lim];
vector<int>ulta[lim];
stack<int>stk;
int vis[lim];
void dfs(int s)
{
    vis[s] = 1;
    for(int i=0; i<soja[s].size(); i++)
    {
        if(!vis[soja[s][i]])
        dfs(soja[s][i]);
    }
    stk.push(s);
}
void dfs2(int s)
{
    //cout<<s<<endl;
  //  if(vis[s])return ;
    vis[s] = 1;
    for(int i=0; i<soja[s].size(); i++)
    {
        //cout<<s<<" "<<ulta[s][i]<<endl;
        if(!vis[soja[s][i]])
            dfs2(soja[s][i]);
    }
}
int main()
{
    int t;
    int cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            soja[u].push_back(v);
            //ulta[v].push_back(u);
        }
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        int cnt = 0;
        memset(vis,0,sizeof(vis));
        while(!stk.empty())
        {
            int i = stk.top();
            stk.pop();
            if(!vis[i])
            {
                ++cnt;
                dfs2(i);
            }
        }
        for(int i=1; i<=n; i++)
        {
            soja[i].clear();
           // ulta[i].clear();
        }
        printf("Case %d: %d\n",cas++,cnt);
    }
}
