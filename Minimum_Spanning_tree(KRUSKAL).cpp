#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,cost;
     bool operator<(const Edge& p) const
    {
        return cost < p.cost;
    }
};
int cost[105];
int n;
vector<Edge>vec;
    int a,b,par[100],r;
    int find(int r)
    {
        if(par[r]==r)
            return r;

            par[r] = find(par[r]);
            return par[r];
    }
int kruskal(int n)
{
    sort(vec.begin(),vec.end());
    for(int i=1; i<=n; i++)
    {
        par[i] = i;
    }
    int cnt = 0,sum=0;
    int sz = vec.size();
    for(int i=0; i<sz; i++)
    {
        int p1 = find(vec[i].u);
        int p2 = find(vec[i].v);
        if(p1!=p2)
        {
            par[p2] = p1;
            cnt++;
            sum+=vec[i].cost;
            cost[vec[i].v] = vec[i].cost;
            if(cnt==n-1)
                break;
        }
    }
    return sum;
}
int main()
{
    int e;
    cin>>n>>e;

    for(int i=1; i<=e; i++)
    {
        Edge tut;
        int a,b,c;
        cin>>a>>b>>c;
        tut.u = a;
        tut.v = b;
        tut.cost = c;
        vec.push_back(tut);
    }
    kruskal(n);
    for(int i=0; i<n; i++)
        cout<<cost[i]<<endl;
}
