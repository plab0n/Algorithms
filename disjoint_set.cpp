
#include <iostream>
using namespace std;

class disjoint_set{
public:
    int a,b,par[100],r;
    void take_in()
    {
        int n,i;
        cin>>n;
        for(i=0; i<n; i++){
            cin>>r;
            par[r] = r;
            }
    }
    int union_(int a,int b)
    {
        int u = find(a);
        int v = find(b);

        if(u==v)
            cout<<"ek kam koibar kormu"<<endl;
            else
                par[u] = v;
    }
    int find(int r)
    {
        if(par[r]==r)
            return r;

            par[r] = find(par[r]);
            return par[r];
    }
};

int main ()
{
    disjoint_set obj;
    obj.take_in();
}
