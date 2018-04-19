#include <bits/stdc++.h>
using namespace std;
int status[1000009];
vector<int>prime;
bool check(int n,int pos)
{
    return (bool)(n&(1<<pos));
}
bool setBit(int n,int pos)
{
    return (bool)(n|=(1<<pos));
}
void sieve(){

    int i,j,lim=sqrt(50000000*1.);
    prime.push_back(2);
    for(i=3; i<=lim; i+=2)
    {
        prime.push_back(i);

        if(check(status[i/32],i%32)==0)
        {
            for(j=i*i; j<=50000000; j+=(i*2))
            {
                cout<<j<<endl;
                status[j/32] = setBit(status[j/32],j%32);
            }
            }
        }
}
int main()
{
    sieve();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<prime[n-1]<<endl;
    }
}
