#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  int root(int x) {
    if (d[x] < 0) return x;
    else return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

ll solve(int n, int m, vector<int> x, vector<int> y, vector<int> z){
  UnionFind uf(n);
  for (int i=0; i<m; ++i) uf.unite(x[i], y[i]);
  set<int> se;
  for (int i=0; i<n; i++)se.insert(uf.root(i));
  return (int)se.size();
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int>x(m), y(m), z(m);
  rep(i, m){
    cin >> x[i] >> y[i] >> z[i];
    --x[i]; --y[i];
  }
  cout << solve(n, m, x, y, z) << endl;
  return 0;
}
