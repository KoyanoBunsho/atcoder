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
  vector<int> x(n), y(n), z(n), w(n);
  rep(i, n){
    cin >> x[i] >> y[i];
  }
  rep(i, n){
    z[i] = x[i] + y[i];
    w[i] = x[i] - y[i];
  }
  int z_max = *max_element(z.begin(), z.end());
  int z_min = *min_element(z.begin(), z.end());
  int w_max = *max_element(w.begin(), w.end());
  int w_min = *min_element(w.begin(), w.end());
  int ans = max(z_max - z_min, w_max - w_min);
  cout << ans << endl;
  return 0;
}
