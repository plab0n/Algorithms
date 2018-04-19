#include <bits/stdc++.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int vis[100][100];
char str[100][100];
int d_r,d_c,s_r,s_c;
int r,c,d[100][100];
void bfs(int a, int b)
{
    int i,j;
    memset(d,0,sizeof(vis[100]));
    memset(vis,0,sizeof(d[100]));
    pii node;
    node = make_pair(a,b);
    queue <pii>Q;
    vis[a][b] = 1;
    Q.push(node);

    while(!Q.empty())
    {
        pii u = Q.front();
        Q.pop();

        for(int i=0; i<4; i++)
        {
            int tx = u.first+fx[i];
            int ty = u.second+fy[i];
            cout<<tx<<" "<<ty<<endl;
            if((tx>=0 && tx<r) && (ty>=0 && ty<c) && str[tx][ty]!='m'&&str[tx][ty]!='#' && vis[tx][ty]==0)
            {
                 cout<<str[tx][ty]<<endl;
                vis[tx][ty] = 1;
                d[tx][ty] = d[tx][ty]+1;
                Q.push(pii(tx,ty));
            }
        }
    }
}

int main()
{
    int i,j,s_c1,s_c2,s_c3,s_r1,s_r2,s_r3,t,s_r4,s_c4;
    int d1[5];
    cin>>t;
    int cas = 1;
    while(t--){
    cin>>r>>c;

    for(i=0; i<c; i++)
    {
        for(j=0; j<r; j++)
        {
            cin>>str[i][j];
            if(str[i][j]=='a')
            {
                s_r1 = i;
                s_c1 = j;
            }
            if(str[i][j]=='b')
            {
                s_r2 = i;
                s_c2 = j;
            }
            if(str[i][j]=='c')
            {
                s_r3 = i;
                s_c3 = j;
            }
            if(str[i][j]=='h')
            {
                s_r4 = i;
                s_c4 = j;
            }
        }
    }
    bfs(s_r4,s_c4);
    cout<<d[s_r1][s_c1]<<endl<<d[s_r2][s_c2]<<endl<<d[s_r3][s_c3]<<endl;
    int res = max(max(d[s_r1][s_c1],d[s_r2][s_c2]),d[s_r3][s_c3]);
    cout<<res<<endl;
    }
    return 0;
}
