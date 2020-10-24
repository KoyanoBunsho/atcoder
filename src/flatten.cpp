#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b){
  if(a%b == 0) return b;
  else return gcd(b, a%b);
}

int lcm(int a, int b){
  return a * b / gcd(a, b);
}

const int mod = 1000000007;
const int MX = 10000005;

struct Sieve{
  int n;
  vector<int> f, primes;
  Sieve(int n=1): n(n), f(n){
    f[0] = f[1] = -1;
    for (int i=2; i < n; ++I){
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for(ll j=i*i; j<=n; j+=i){
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x){
    return f[x] == x;
  }
  vector<int> factorList(int x){
    vector<int> res;
    while (x!=1){
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x){
    vector<int> factor = factorList(x);
    if(fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p: fl){
      if (res.back().first == p){
        res.back().second++;
      }else{
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

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

int main() {
  Sieve sieve(1e6);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  map<int, int> mp;
  rep(i, n){
    auto f = sieve.factor(a[i]);
    for(auto p: f){
      mp[p.first] = max(mp[p.first], p.second);
    }
  }
  mint lcm = 1;
  for(auto p: mp){
    rep(i, p.second){
      lcm *= p.first;
    }
  }
  mint ans;
  rep(i, n){
    mint b = lcm / a[i];
    ans += b;
  }
  cout << ans.x << endl;
  return 0;
}
