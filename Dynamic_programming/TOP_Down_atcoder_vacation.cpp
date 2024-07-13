#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll ar[n+1][4];
    for(int i=1;i<=n;i++)
    {
       int a,b,c;
       cin>>a>>b>>c;
       ar[i][1]=a;
       ar[i][2]=b;
       ar[i][3]=c;
    }
    ll br[n+1][4];
    br[1][1]=ar[1][1];
    br[1][2]=ar[1][2];
    br[1][3]=ar[1][3];
    for(int i=2;i<=n;i++)
    {
        br[i][1]=max(br[i-1][2]+ar[i][1],br[i-1][3]+ar[i][1]);
        br[i][2]=max(br[i-1][1]+ar[i][2],br[i-1][3]+ar[i][2]);
        br[i][3]=max(br[i-1][1]+ar[i][3],br[i-1][2]+ar[i][3]);
    }
    ll ans=max(br[n][1],max(br[n][2],br[n][3]));
    cout<<ans<<endl;


}
