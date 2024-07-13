//https://atcoder.jp/contests/dp/tasks/dp_h
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;

int main()
{
    ll n,m;
    cin>>n>>m;
    char  ar[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
   // vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
   ll dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ar[i][j]!='#')
            {
                if(i-1>=0)
                {
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]=dp[i][j]%mod;
                }
                if(j-1>=0)
                {
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]=dp[i][j]%mod;
                }
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;


}
