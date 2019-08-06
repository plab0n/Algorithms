#include <bits/stdc++.h>
using namespace std;

#define mx 100009
typedef long long i64;
using namespace std;

i64 arr[mx];
int l,r;
struct info{
    i64 sum,prop;
}tree[mx*4];

void update(int node,int start,int end,int val)
{
    if(l>end || r<start)
        return ;
    if(start>=l && end<=r)
    {
        tree[node].sum += val*(end-start+1);
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
    i64 p1 = Query(left,start,mid,carry+tree[node].prop);
    i64 p2 = Query(right,mid+1,end,carry+tree[node].prop);
    return p1+p2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int c[100009];
    int h[100009];
    int cnt[100009];
    int cntH[100009];
    cin>>t;

    while(t--){
        memset(cnt, 0, sizeof(cnt));
        memset(cntH, 0, sizeof(cntH));
        int n;
        cin>>n;

        for(int i=1; i<=n+n+n; i++){
            tree[i].sum  = 0;
            tree[i].prop = 0;
        }

        for(int i=1; i<=n; i++)cin>>c[i];
        for(int i=1; i<=n; i++){
            cin>>h[i];
            if(h[i]>n)continue;
            cntH[h[i]]++;
        }

        for(int i=1; i<=n; i++){
            l = max(i-c[i], 1);
            r = min(i+c[i], n);
           // cout<<l<<" "<<r<<endl;
            update(1, 1, n, 1);
        }
        for(int i=1; i<=n; i++){
            l = i;
            r = i;
         //   cout<<Query(1,1,n,0)<<endl;
            cnt[Query(1, 1, n, 0)]++;
        }
        int res = 0;
        bool loc = true;
        for(int i=1; i<=n; i++){
            if(h[i]>n){
                loc = false;
                break;
            }
            if(cnt[h[i]]!=cntH[h[i]]){
                loc = false;
                break;
            }
        }
        //cout<<res<<endl;
        if(loc){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}
