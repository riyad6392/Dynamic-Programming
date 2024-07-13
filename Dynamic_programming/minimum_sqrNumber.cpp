// given a number you have to find minimum number of square which sum is equal n
#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
int dp[2002];
int minsqr(int n)
{
    if(n==1 || n==2 || n==3 || n==0) return n;
    if(dp[n]!=-1) return dp[n];

    int res=N;
    for(int i=1;i*i<=n;i++)
    {
        res=min(res,1+minsqr(n-i*i));
    }
    return dp[n]=res;
}
int main()
{
    for(int i=0;i<=2000;i++)
    {
        dp[i]=-1;
    }
   int n;
   cin>>n;
   int ans=minsqr(n);
   cout<<ans<<endl;
}
