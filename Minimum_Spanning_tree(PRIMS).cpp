#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    memset(marked,false,sizeof(marked));
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    int t;
    //int cas = 1;
    cin>>t;

    for(int i=1; i<=t; i++){

//           char c,a;
//           scanf("%c%c",&c,&a);
    //cout<<t<<endl;
    long long weight, minimumCost,k;
    cin >> nodes >> edges>>k;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
//        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(k);
    cout<<"Case "<<i<<": ";
    if(minimumCost>0)
    cout << minimumCost << endl;
    else
        cout<<"impossible"<<endl;
        for(int i=0; i<nodes; i++)
            adj[i].clear();

    }
     return 0;
}
