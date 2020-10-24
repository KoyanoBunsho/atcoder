#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<set<int>> is(26);
  rep(i, n) is[s[i]-'a'].insert(i);
  rep(i, q){
    int type;
    cin >> type;
    if(type==1){
      int i;
      char c;
      cin >> i >> c;
      i--;
      is[s[i]-'a'].erase(i);
      s[i] = c;
      is[s[i]-'a'].insert(i);
    }else{
      int l, r;
      cin >> l >> r;
      l--;
      int ans = 0;
      rep(i, 26){
        auto it = is[i].lower_bound(l);
        if (it != is[i].end() && *it < r) ++ans;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
