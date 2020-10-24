#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  map<string, int>week;
  week["Monday"] = 5;
  week["Tuesday"] = 4;
  week["Wednesday"] = 3;
  week["Thursday"] = 2;
  week["Friday"] = 1;
  string day;
  cin >> day;
  cout << week[day] << endl;
  return 0;
}
