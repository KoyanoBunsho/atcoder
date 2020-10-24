#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        siz.assign(sz_, 1LL);  // assign: 再代入
        par.resize(sz_);  // resize: 再確保
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int>a(m), b(m);
  vector<int> ans(m);
  ans[m-1] = n * (n - 1) / 2;
  rep(i, m){
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  UnionFind uf(n);
  for (int i=m-1; i>0; --i){
    if(uf.issame(a[i], b[i])) ans[i-1] = ans[i];
    else{
      ans[i-1] = ans[i] - (uf.size(a[i]) * uf.size(b[i]));
      uf.merge(a[i], b[i]);
    }
  }
  rep(i, m) cout << ans[i] << endl;
  return 0;
}
