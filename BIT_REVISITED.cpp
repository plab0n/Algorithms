#include <bits/stdc++.h>
using namespace std;

int tree[100009],n;
int JugFol(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(int idx,int val)
{
   // cout<<n<<endl;
    while(idx<=n)
    {
        tree[idx]+=val;
       // cout<<tree[idx]<<endl;
        idx+=(idx&(-idx));
    }
}
int query(int i,int j)
{
    return abs(JugFol(i-1)-JugFol(j));
}
