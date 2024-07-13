#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int vis[N];
int dp[N];
vector<int>vt[N];
void dfs(int node)
{
    dp[node]=0;
    vis[node]=1;
    for(int child : vt[node])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
        dp[node]=max(dp[node],dp[child]+1);

    }

}
int main()
{
   int n,m;
   cin>>n>>m;
     for(int i=0;i<m;i++)
     {
         int v,u;
         cin>>v>>u;
         vt[v].push_back(u);
     }
     for(int i=1;i<=n;i++)
     {
         if(vis[i]==0)
         {
             dfs(i);
         }
     }
     int ans=0;
     for(int i=1;i<=n;i++)
     {
         ans=max(ans,dp[i]);
     }
     cout<<ans<<endl;

}
