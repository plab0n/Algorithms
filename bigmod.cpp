#include <iostream>
using namespace std;

int bigmod(long long a, long long b, long long m)
{
    if(b==0)
        return 1%m;
    int x = bigmod(a,b/2,m);

    x = (x*x)%m;
    if(b%2==1)
            x = (x*a)%m;

            return x;
}
int main ()
{
    long long a,b,m;

    while(cin>>a>>b>>m)
    {
        cout<<bigmod(a,b,m)<<endl;
    }
}
