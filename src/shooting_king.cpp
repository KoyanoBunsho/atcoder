#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  vector<ll> h(n), s(n);
  rep(i, n) cin >> h[i] >> s[i];
  ll left = 0, right = INF;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    bool ok = true;
    vector<ll> t(n, 0);
    rep(i, n){
      if(mid < h[i]) ok = false;
      else t[i] = (mid - h[i]) / s[i];
    }
    sort(t.begin(), t.end());
    rep(i, n){
      if (t[i] < i) ok = false;
    }
    if(ok) right = mid;
    else left = mid;
  }
  cout << right << endl;
  return 0;
}
