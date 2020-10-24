#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, n){
    if (a[i] > x){
      ans += a[i] - x;
      a[i] = x;
    }
  }
  for (int i=0; i+1<n; ++i){
    if (a[i] + a[i+1] > x){
      ans += a[i] + a[i+1] - x;
      a[i+1] = x - a[i];
    }
  }
  cout << ans << endl;
  return 0;
}
