#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> s(n);
  rep(i, n) cin >> s[i];
  rep(i, n){
    if(s[i] == 0){
      cout << n << endl;
      return 0;
    }
  }
  int res = 0;
  int right = 0;
  ll mul = 1;
  rep(left, n){
    while(right < n && mul * s[right] <= k){
      mul *= s[right];
      ++right;
    }
    res = max(res, right-left);
    if(left == right) ++ right;
    else mul /= s[left];
  }
  cout << res << endl;
  return 0;
}
