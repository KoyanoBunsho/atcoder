#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
const int MX = 100005;
const ll LINF = 1000000000000000000ll
ll a[MX];
ll b[MX];

ll f(ll x){
  ll res = 0;
  rep(i, n){
    ll d = x / a[i];
    int p = lower_bound(b, b+n, d+1) - b;
    res += p;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  sort(a, a+n);
  sort(b, b+n);
  ll l = -1, r = LINF, c;
  while(l+1 < r){
    c = (l+r) >> 1;
    if (f(c) < k) l = c;
    else r = c;
  }
  cout << r << endl;
  return 0;
}
