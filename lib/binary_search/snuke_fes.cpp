#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b(n);
  rep(i, n) cin >> b[i];
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  ll ans = 0;
  rep(i, n){
    auto a_tmp = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    auto c_tmp = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
    ans += a_tmp * (n-c_tmp);
  }
  cout << ans << endl;
  return 0;
}
