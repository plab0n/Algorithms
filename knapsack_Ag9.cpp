#include <iostream>
using namespace std;

int DP[10000][10000];
int cost[10000];
int weight[10000];
int cap,n,profit1,profit2,i;
int max(int pro,int pro2)
{
    if(pro>pro2)
        return pro;
        else
            return pro2;
}
int knapsack(int i,int w)
{
    if(i==n)
        return 0;
        if(DP[i][w]!=0)
            return DP[i][w];

            if(w+weight[i]<=cap)
                profit1 = cost[i] + knapsack(i+1,w+weight[i]);
            else
                profit1 = 0;

                profit2 = knapsack(i+1,w);

                DP[i][w] = max(profit1,profit2);

                return DP[i][w];
}
int main ()
{
    cin>>n>>cap;

    for(i=0; i<n; i++)
    {
        cin>>weight[i]>>cost[i];
        //cost[i] = weight[i]*cost[i];
    }

    cout<<knapsack(0,0)<<endl;
}
