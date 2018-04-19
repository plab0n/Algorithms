#include <iostream>
#include <cstdio>
using namespace std;
int flag[25][25];
int row,column;
char str[25][25];
int cnt;
int floodFill(int i,int j)
{
    if(i<0 || j<0 || i>=row || j>=column)
        return 0;

                //cout<<"Baire: "<<str[i][j]<<" "<<i<<" "<<j<<endl;
                if((str[i][j]=='@' || str[i][j]=='.') && flag[i][j]==0)
                {
                    //cout<<"VItore:"<<str[i][j]<<" "<<i<<" "<<j<<endl;
                    cnt++;
                    flag[i][j] = 1;
                    floodFill(i,j+1);
                    floodFill(i+1,j);
                    floodFill(i,j-1);
                    floodFill(i-1,j);
                   // cout<<cnt<<endl;
                }

                return cnt;
}
int main ()
{
    int i,j,cas=1,st_r,st_c,t;
    FILE *fp = freopen("flood.txt","r",stdin);
    FILE *fp2 = freopen("fl_out.txt","w",stdout);
    cin>>t;

    while(t--){
     cin>>row>>column;
    for(i=0; i<column; i++)
    {
        for(j=0; j<row; j++)
        {
            cin>>str[i][j];
            if(str[i][j]=='@' )
                {
                    //str[i][j] = '@';
                    st_r = i;
                    st_c = j;
                }
        }
    }
    for(i=0; i<25; i++)
        for(j=0; j<25; j++)
            flag[i][j] = 0;

    cnt = 0;
    int res = floodFill(st_c,st_r);
    cout<<"Case "<<cas++<<": "<<res<<endl;
    }


}
