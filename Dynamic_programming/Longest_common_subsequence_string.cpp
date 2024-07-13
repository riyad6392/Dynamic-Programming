//https://atcoder.jp/contests/dp/tasks/dp_f
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }

        }
    }
   // cout<<dp[n][m]<<endl;
   string ans;
   int i=n,j=m;
   while(i && j)
   {
       if(s[i-1]==t[j-1])
       {
           ans+=s[i-1];
           i--;
           j--;

       }
       else if(dp[i][j-1]>=dp[i-1][j])
       {
           j--;
       }
       else
       {
           i--;
       }

   }
   reverse(ans.begin(),ans.end());
   cout<<ans<<endl;

}
