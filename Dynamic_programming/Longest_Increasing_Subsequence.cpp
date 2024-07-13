#include<bits/stdc++.h>
using namespace std;
const int N=10000;
vector<int>vt(N+1);
int Dp[10000];
int lis(int n)
{
    int an=1;
    if(Dp[n]!=-1) return Dp[n];
    for(int i=0;i<n;i++)
    {
        if(vt[n]>vt[i])
        {
            an=max(an,lis(i)+1);
        }
    }
    return Dp[n]=an;

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        Dp[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>vt[i];
    }
    // lis(n-1) aita holo last index ar jonno but poro array ar jonno loop use korte hobe
    //test case
    // 7
    // 2 1 2 3 7 8 3
    // O(n^2)
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,lis(i));
    }
    cout<<ans<<endl;


}
