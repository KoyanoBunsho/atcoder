#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  ll d, a;
  cin >> n >> d >> a;
  vector<P> p(n);
  rep(i, n){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  d = d*2;
  ll tot = 0;
  queue<pair<ll, ll>> q;
  ll ans = 0;
  rep(i, n){
    ll x = p[i].first;
    ll h = p[i].second;
    while(q.size() && q.front().first < x){
      tot -= q.front().second;
      q.pop();
    }
    h -= tot;
    if(h>0){
      ll num = (h+a-1) / a;
      ans += num;
      ll damage = num * a;
      tot += damage;
      q.emplace(x+d, damage);
    }
  }
  cout << ans << endl;
  return 0;
}
