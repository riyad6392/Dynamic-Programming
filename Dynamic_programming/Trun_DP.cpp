//https://codeforces.com/contest/1418/problem/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int ar[200005];
int dp[200005][2];
int n;

int ok(int pos,int trun)
{
    if(pos>=n) return 0;
    if(dp[pos][trun]!=-1) return dp[pos][trun];
    int res=INT_MAX;
    if(trun==0)
    {
        res=min(res,ok(pos+1,1));
        res=min(res,ok(pos+2,1));
    }
    else
    {
        res=min(res,ar[pos]+ok(pos+1,0));
        res=min(res,ar[pos]+ar[pos+1]+ok(pos+2,0));
    }
    return dp[pos][trun]=res;

}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>ar[i];

       }

       ar[n]=0;
       memset(dp,-1,sizeof(dp));
       cout<<ok(0,1)<<endl;

   }

}
