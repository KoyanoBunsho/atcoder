#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

string a[11];

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<n;i++)
    cin>>a[i];
  int ans=1e9;
  for(int mask=0;mask<(1<<(n-1));mask++){
    vector<int> p;
    p.push_back(0);
    for(int i=1;i<n;i++)
      if(mask>>(i-1)&1)
        p.push_back(i);
    p.push_back(n);
    int cur=p.size()-2;
    int l=0;
    int r=0;
    while(l<m){
      vector<int> c(p.size()-1);
      while(r<m){
        for(int t=0;t<p.size()-1;t++)
          for(int i=p[t];i<p[t+1];i++)
            c[t]+=(a[i][r]=='1');
        if(*max_element(c.begin(),c.end())>k)
          break;
        r++;
      }
      if(l==r){
        cur=1e9;
        break;
      }
      l=r;
      cur+=l<m;
    }
    ans=min(cur,ans);
  }
  cout<<ans<<endl;
  return 0;
}
