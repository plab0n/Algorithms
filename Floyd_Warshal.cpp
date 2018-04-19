#include <bits/stdc++.h>
#define inf 1000000
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int dist[505][505];
    int cas = 1;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dist[i][j] = inf;
        for(int i=1; i<=m; i++)
        {
            int u,v,cst;
            scanf("%d%d%d",&u,&v,&cst);
            dist[u][v] = cst;
            dist[v][u] = cst;
        }
        int t;
        scanf("%d",&t);
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        printf("Case %d:\n",cas++);
        for(int i=0; i<n; i++)
        {
            if(dist[i][t]==inf)
                printf("Impossible\n");
            else
                printf("%d\n",dist[i][t]);
        }
    }
}
