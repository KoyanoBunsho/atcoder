#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
ll l, t;
vector<ll> x;
vector<int> w;

const int mod = 1000000007;
int main() {
  cin >> n >> l >> t;
  x.resize(n);
  w.resize(n);
  rep(i, n) cin >> x[i] >> w[i];
  vector<ll> tmp(n);
  rep(i, n){
    if(w[i]==1)tmp[i] = (x[i]+t)%l;
    else (tmp[i] = (x[i]-t)%l + l)%l;
  }
  sort(tmp.begin(), tmp.end());
  ll cnt = 0;
  rep(i, n){
    if(w[i]==1)cnt -= (t - (l - x[i]) + l) / l;
    else cnt += ((t - x[i] + 1) + l) / l;
  }
  cnt = (cnt % n + n) % n;
  vector<ll> res(n);
  rep(i, n) res[(i+cnt)%n] = tmp[i];
  rep(i, n) cout << res[i] << endl;
  return 0;
}
