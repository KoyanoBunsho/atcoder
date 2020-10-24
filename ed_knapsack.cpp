#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll dp[105][100005];

const int mod = 1000000007;
int main() {
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  rep(i, n){
    cin >> w[i] >> v[i];
  }
  rep(i, n+1){
    rep(j, W+1){
      if(j < w[i]) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
    }
  }
  cout << dp[n][W] << endl;
  return 0;
}
