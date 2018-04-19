#include <bits/stdc++.h>
using namespace std;
int arr[1000009],a[1000009],cnt,n;
void merge_sort(int start,int mid,int end)
{
    int p = start,q = mid+1;
    int i,k=1;
    for(i=start; i<=end; i++)
    {
        if(p>n || q>n)
            break;
        if(p>mid){
            arr[k++] = a[q++];
        }
       else if(q>end)
            arr[k++] = a[p++];
        if(a[p]<a[q])
            arr[k++] = a[p++];
        else if((a[p]>a[q])){
               // cout<<a[p]<< " "<<a[q]<<endl;
            arr[k++] = a[q++];
            ++cnt;
        }
    }
    for(i=1; i<=end; i++)
    {
        a[start++] = arr[i];
    }
}
void mTree(int start,int end)
{
    if(start>=end)
        return ;
    int midpoint = (start+end)/2;
    mTree(start,midpoint);
    //cout<<end<<" "<<midpoint<<endl;
    mTree(midpoint+1,end);

    merge_sort(start,midpoint,end);

}

int main()
{

            cin>>n;
            for(int i=1; i<=n; i++)
            {
               cin>>a[i];
            }
            mTree(1, n);
            for (int i = 1; i <= n; i++)
                cout<<a[i]<<" ";
                cout<<endl;
}
