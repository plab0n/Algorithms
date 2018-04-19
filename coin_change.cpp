#include <iostream>
#include <cstdio>
using namespace std;
int dp[6][7489];
int make;
int poisa[6] = {50,25,10,5,1};
int coin(int i,int amount)
{
    cout<<"am here"<<endl;
    if(make==0)
        return 1;
        if(dp[i][amount]!=0)
            return dp[i][amount];
            if(i>=5)
            {
                if(amount==make)
                    return 1;
            }
        int ret1 = 0;
        int ret2 = 0;
        if(amount+poisa[i]<=make)
            ret1 = amount+coin(i,amount+poisa[i]);

            ret2 = coin(i+1,amount);

        dp[i][amount] = ret1+ret2;

        return dp[i][amount];
}

int main ()
{
    while(scanf("%d", &make)!=EOF)
    {
        printf("%d\n", coin(0,0));
    }
}
