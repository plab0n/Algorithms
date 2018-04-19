#include <bits/stdc++.h>
#define mx 100009
using namespace std;

int arr[mx];
int tree[mx*3];
int n,l,r;
int sum(int node, int start,int end){
   // cout<<l<<" "<<r<<" "<<start<<" "<<end<<endl;
    if(l>end || r<start)
        return 0;
    if(start>=l && end<=r)
        return tree[node];

    int left = node*2;
    int right = node*2+1;
    int mid = (start+end)/2;
    int p1 = sum(left,start,mid);
    int p2 = sum(right,mid+1,end);
    //cout<<p1<<" "<<p2<<endl;
    return p1+p2;
}
void init(int node,int start,int end)
{
    if(start==end)
    {
        tree[node] = arr[start];
        return ;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (start+end)/2;
    init(left,start,mid);
    init(right,mid+1,end);
    tree[node] = tree[left]+tree[right];

}
void update(int node,int start,int end,int i,int val)
{
     if(i>end || i<start)
        return ;
     if(start>=i && end<=i){
         tree[node] = val;
        return ;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (start+end)/2;
    update(left,start,mid,i,val);
    update(right,mid+1,end,i,val);
    tree[node] = tree[left]+tree[right];
}
int main()
{
    cin>>n;
    for(int i =1; i<=n; i++)
        cin>>arr[i];
    init(1,1,n);
    for(int i=1; i<=n*3; i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    for(int i=1; i<=n; i++)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            cin>>l>>r;
            cout<<sum(1,1,n)<<endl;
        }
        if(q==2)
        {
            cin>>l>>r;
            update(1,1,n,l,r);
        }
    }
    cout<<endl;
}
