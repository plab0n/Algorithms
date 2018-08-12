#include <bits/stdc++.h>
using namespace std;
vector<int>prime;
int composit[100009];
void linear_Sieve(int n)
{
    fill(composit,composit+n,0);
    for(int i=2; i<=n; i++)
    {
        if(!composit[i])
            prime.push_back(i);
            for(int j=0; j<prime.size() && i*prime[j]<=n; j++)
            {
                composit[i*prime[j]] = 1;
                if(i%prime[j]==0)break;
            }

    }
    for(int i=0; i<prime.size(); i++)
        cout<<prime[i]<<" ";
        cout<<endl;
}
int main()
{
    linear_Sieve(20);
}
