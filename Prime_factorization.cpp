#include <bits/stdc++.h>
using namespace std;
vector<int>prime;
int mark[1000009];
long long cnt,n,m;
void sieve(int n)
{
    long long i,j,limit = sqrt(sqrt(n*1.)*1.),temp;

    prime.push_back(2);
    int sq = sqrt(n*1.);
    for(i=3; i<=sq; i+=2)
    {
        if(!mark[i])
            {
                prime.push_back(i);
                if(i<=limit)
                {
                    for(j=i*i; j<=sq; j+=i*2)
                    {
                        mark[j] = 1;
                    }
                }
            }
    }
}
vector<int>factors;
void factorize( int n ) {
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                factors.push_back(prime[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        factors.push_back(n);
    }
}

