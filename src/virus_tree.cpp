#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

struct combination {
  vector<mint> fact, ifact;
  combination(int n): fact(n+1), ifact(n+1){
    assert(n < mod);
    fact[0] = 1;
    for (int i=1; i<=n; ++i)fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
  }
  mint operator()(int n, int k){
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n-k];
  }
}comb(100005);

mint f(int n, int k){
  if(n<0) return 0;
  mint res = comb(n, k);
  res *= comb.fact[k];
  return res;
}
int k;
mint ans;
vector<int> to[100005];
void dfs(int v, int p=-1){
  for(int u: to[v]){
    if(u==p) continue;
    dfs(u, v);
  }
  int nk = (p==-1) ? k: k-2;
  int c = (p==-1) ? to[v].size() + 1: to[v].size() - 1;
  ans *= f(nk, c);
}
int main() {
  int n;
  cin >> n >> k;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  ans = 1;
  dfs(0);
  cout << ans << endl;
  return 0;
}
