#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n=0):n(n), d(n+1){}
  void add(int i, T x=1){
    for(i++; i<=n; i+=i&-i){
      d[i] += x;
    }
  }
  T sum(int i){
    T x = 0;
    for (i++; i; i-=i&-i){
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r){
    return sum(r-1) - sum(l-1);
  }
};
