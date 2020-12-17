#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

template<typename T>
void chmin(T& a, const T& b) { a = min(a, b);}

int main() {
  const int INF = 1001001001;
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  auto dp = vector(n+1, vector(m+1, INF));
  dp[0][0] = 0;
  rep(i,n+1)rep(j,m+1) {
    if (i < n) chmin(dp[i+1][j], dp[i][j]+1);
    if (j < m) chmin(dp[i][j+1], dp[i][j]+1);
    if (i < n && j < m) {
      int co = 0;
      if (a[i] != b[j]) co = 1;
      chmin(dp[i+1][j+1], dp[i][j]+co);
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}