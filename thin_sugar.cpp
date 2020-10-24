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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int res = 0;
  int right = 0;
  set<int> member;
  rep(left, n){
    while(right < n && !member.count(a[right])){
      member.insert(a[right]);
      ++right;
    }
    res = max(res, right-left);
    if(left == right) ++right;
    else{
      member.erase(a[left]);
    }
  }
  cout << res << endl;
  return 0;
}
