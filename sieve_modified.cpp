#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>
using namespace std;
vector<int>prime;
int mark[1000009];
long long cnt,n,m;
void sieve()
{
    long long i,j,limit = sqrt(1000000*1.),temp;

    for(i=4; i<=1000000; i+=2)
    {
        mark[i] = 1;
    }

    prime.push_back(2);
    for(i=3; i<=1000000; i+=2)
    {
        if(!mark[i])
            {
                prime.push_back(i);
                if(i<=limit)
                {
                    for(j=i*i; j<=1000000; j+=i*2)
                    {
                        mark[j] = 1;
                    }
                }
            }
    }


}
int main ()
{
    sieve();
}
