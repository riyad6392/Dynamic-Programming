#include<bits/stdc++.h>
using namespace std;
const int N=1000;
vector<int>vt(N+1);
int Dp[1000];
vector<int>index(N+1);
int lis(int n,vector<int>&vt)
{
    int an=0;
    if(Dp[n]!=-1) return Dp[n];
    for(int i=n+1;i<vt.size();i++)
    {
        if(vt[i]>vt[n])
        {
            int sub=lis(i,vt);
           if(sub>an)
           {
               an=sub;
               index[n]=i;
           }

        }
    }
    Dp[n]=an+1;
    return Dp[n];

}

int main()
{
    int n;
    cin>>n;
    vt.resize(n);
    index.resize(n);
    for(int i=0;i<=n;i++)
    {
        Dp[i]=-1;
        index[i]=-1;
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

    int start_index = -1;
     for(int i = 0;i<vt.size();i++) {
      int result = lis(i,vt);
      if (result > ans) {
          ans = result;
          start_index = i;
      }
  }

    vector<int> liss;
     while(start_index != -1) {
      liss.push_back(vt[start_index]);
      start_index =index[start_index];
    }
    for(int i=0;i<liss.size();i++)
    {
        cout<<liss[i]<<" ";
    }
    cout<<endl;


}

