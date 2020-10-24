#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<ll> enumDivisor(ll n){
  vector<ll> res;
  for(ll i=1; i*i<=n; ++i){
    if (n % i != 0) continue;
    res.push_back(i);
    if (i*i != n) res.push_back(n/i);
  }
  return res;
}
