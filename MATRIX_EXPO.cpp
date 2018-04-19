#include <bits/stdc++.h>
using namespace std;

struct matrix{
    int v[5][5];
    int row,col;
};

matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;
  //  cout<<r.row<<" "<<r.col<<endl;
    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            int sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum+= a.v[i][k]*b.v[k][j];
            }
            //cout<<sum<<endl;
            r.v[i][j] = sum;
        }
    }
    return r;
}
matrix power(matrix mat,int po)
{
    if(po==1)return mat;
    matrix x = power(mat,po/2);
    x = multiply(x,x);
    if(po%2)  x = multiply(mat,x);
    return x;
}
int main()
{
    matrix a;
    a.row = 2;
    a.col = 2;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin>>a.v[i][j];
        }
    }
    matrix val = power(a,2);
    for(int i=0; i<val.row; i++)
    {
        for(int j=0; j<val.col; j++)
            cout<<val.v[i][j]<<" ";
        cout<<endl;
    }
}
