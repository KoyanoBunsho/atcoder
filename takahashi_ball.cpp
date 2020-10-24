#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  long double left = 0, right = 1000;
  rep(i, 50){
    long double mid = (left + right) / 2;
    if (a * mid + b * sin(c * mid * M_PI) < 100) left = mid;
    else right = mid;
  }
  cout << fixed << setprecision(15) << left << endl;
  return 0;
}
