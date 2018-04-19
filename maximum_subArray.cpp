#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[1009];
    int n,i;

    cin>>n;

    for(i=0; i<n; i++)
        cin>>arr[i];
        int p;
        for(i=0; i<n; i++)
        {
            int s = max(arr[i],s+arr[i]);
             p = max(s,p);
        }
        cout<<p<<endl;
}
