#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
const int MX = 200005;

int main() {
  int n;
  vector<int> a(n), b(n);
  rep(i, n){
    cin >> a[i];
  }
  rep(i, n){
    cin >> b[i];
  }
  vector<int> c(MX);
  priority_queue<P> q;
  rep(i, MX) if (c[i]) q.emplace(c[i], i);
  if (q.top(), fi > n) dame;
  return 0;
}
