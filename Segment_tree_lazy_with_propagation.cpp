#include <bits/stdc++.h>
#define mx 100009
typedef long long i64;
using namespace std;

i64 arr[mx];
int l,r;
struct info{
    i64 sum,prop;
}tree[mx*2];

void init(int node,int start,int end)
{
    if(start==end)
    {
        tree[node].sum = arr[start];
    }
    int mid = (start+end)/2;
    int left = node*2;
    int right = node*2+1;

    init(left,start,mid);
    init(right,mid+1,end);
    tree[node].sum = tree[left].sum+tree[right].sum;
}
void update(int node,int start,int end,int val)
{
    if(l>end || r<start)
        return ;
    if(start>=l && end<=r)
    {
        tree[node].sum = val*(end-start+1);
        tree[node].prop += val;
        return ;
    }
    int mid = (start+end)/2;
    int left = node*2;
    int right = node*2+1;
    update(left,start,mid,val);
    update(right,mid+1,end,val);
    tree[node].sum = tree[left].sum+tree[right].sum+(tree[node].prop*(end-start+1));
}
i64 Query(int node,int start,int end,int carry =0)
{
    if(l>end || r<start)
        return 0;
    if(start>=l && end<=r)
    {
        return tree[node].sum+(carry*(end-start+1));
    }
    int mid = (start+end)/2;
    int left = node*2;
    int right = node*2+1;
    i64 p1 = Query(left,start,mid,carry+tree[left].prop);
    i64 p2 = Query(right,mid+1,end,carry+tree[right].prop);
    return p1+p2;
}
int main()
{
    int t,n,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(int i=1; i<=n*2; i++){
            tree[i].sum = 0;
            tree[i].prop = 0;
        }
            int type,v;
        while(q--)
        {
            scanf("%d",&type);
            if(type==0)
            {
               scanf("%d%d%d",&l,&r,&v);
                update(1,1,n,v);
            }
            else{
                scanf("%d%d",&l,&r);
                printf("%lld\n",Query(1,1,n,0));
            }
        }
    }
}
