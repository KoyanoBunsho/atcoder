#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
int main() {
  ll r, b;
  cin >> r >> b;
  ll x, y;
  cin >> x >> y;
  ll left = 0, right=min(r, b) + 1;
  while(right-left>1){
    ll mid = (left + right) / 2;
    if ((r-mid)/(x-1) + (b-mid)/(y-1) >= mid) left = mid;
    else right = mid;
  }
  cout << left << endl;
  return 0;
}
