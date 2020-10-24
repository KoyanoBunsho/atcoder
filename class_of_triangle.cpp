#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const double PI = acos(-1.0);
const double EPS = 1e-10;
long long N;
double x[2100], y[2100];
int main() {
  cin >> N;
  rep(i, N) cin >> x[i] >> y[i];
  long long don = 0, tyo = 0;
  rep(i, N) {
    vector<double> args;
    rep(j, N) {
      if (j == i) continue;
      double targ = atan2(y[j] - y[i], x[j] - x[i]);
      args.push_back(targ);
      args.push_back(targ + PI*2);
    }
    sort(args.begin(), args.end());
    rep(j, N) {
      if (j == i) continue;
      double targ = atan2(y[j] - y[i], x[j] - x[i]);
      int left = lower_bound(args.begin(), args.end(), targ + PI/2.0 - EPS) - args.begin();
      if (abs(args[left] - targ - PI/2.0) < EPS) {
        ++tyo;
        ++left;
      }
      int right = lower_bound(args.begin(), args.end(), targ + PI*3.0/2.0 - EPS) - args.begin();
      if (abs(args[right] - targ - PI*3.0/2.0) < EPS) {
        ++tyo;
      }
      don += max(right - left, 0);
    }
  }
  tyo /= 2;
  don /= 2;
  cout << N*(N-1)*(N-2)/6 - don - tyo << " " << tyo << " " << don << endl;
}
