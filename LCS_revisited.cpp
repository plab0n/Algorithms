#include <bits/stdc++.h>
using namespace std;
string str1,str2;
int dp[105][105];
int calcLCS(int i,int j)
{
    if(str1[i]=='\0'||str2[j]=='\0') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    if(str1[i]==str2[j]) ans = 1+calcLCS(i+1,j+1);
    else{
        ans = max(calcLCS(i,j+1),calcLCS(i+1,j));
    }
   // visited[i][j] = 1;
    return dp[i][j] = ans;
}
string str;
void printLCS(int i,int j)
{
    if(str1[i]=='\0'||str2[j]=='\0'){
        cout<<str<<endl;
        return ;
    }
    //if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j]){
        str+=str1[i];
        printLCS(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])printLCS(i+1,j);
        else
            printLCS(i,j+1);

    }

}
string p;
void printAll(int i,int j)
{
    if(str1[i]=='\0'||str2[j]=='\0'){
        cout<<p<<endl;
        return ;
    }
    //if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j]){
        p+=str1[i];
        printAll(i+1,j+1);
        p.erase(p.end()-1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])printAll(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1])printAll(i,j+1);
        else{
            printAll(i+1,j);
            printAll(i,j+1);
        }
    }
}
int main()
{
    int cas =1;
    while(getline(cin,str1))
    {
       // getchar();
        memset(dp,-1,sizeof(dp));
        if(str1[0]=='#')return 0;
        getline(cin,str2);
       // getchar();
       str = "";
       p = "";
       int res = calcLCS(0,0);
       //if(res>1)
        cout<<"Case #"<<cas++<<": "<<"you can visit at most "<<res<<" cities."<<endl;
        printLCS(0,0);
        printAll(0,0);
//        else{
//            cout<<"Case #"<<cas++<<": "<<"you can visit at most "<<res<<" city."<<endl;
//        }

    }
}
