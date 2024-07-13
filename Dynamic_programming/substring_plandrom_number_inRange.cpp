#include<bits/stdc++.h>
#define ll long long int
#define  enl          '\n'
using namespace std;
int pref[5001][5001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
   string s;
   cin>>s;
   int sz=s.size();
   for(int k=0;k<sz;k++)
   {
       for(int i=k,j=k;i>=0 and j<sz;i--,j++)
       {
            if(s[i]!=s[j]) break;
             pref[i+1][j+1] = 1;
       }
        for(int i=k,j=k+1;i>=0 and j<sz;i--,j++)
       {
            if(s[i]!=s[j]) break;
             pref[i+1][j+1] = 1;
       }

   }
       for(int i=1;i<=sz;i++) {
        for(int j=1;j<=sz;j++) {
            pref[i][j] += pref[i][j-1];
        }

    }
        for(int j=1;j<=sz;j++) {
        for(int i=1;i<=sz;i++) {
            pref[i][j] += pref[i-1][j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<pref[r][r]-pref[l-1][r]-pref[r][l-1]+pref[l-1][l-1]<<enl;

    }

}
