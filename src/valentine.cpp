#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
const int mod = 1000000007;

int n, m, p, q, r;
int gift[21][21];

int main() {
  cin >> n >> m >> p >> q >> r;
  memset(gift, 0, sizeof(gift));
  rep(i, r){
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    gift[x][y] = z;
  }
  int res = 0;
  for(int bit = (1<<p)-1, BX, BY; bit<(1<<n); BX = bit&-bit, BY=bit+BX, bit=((bit&~BY)/BX>>1)|BY){
    int tmp = 0;
    vector<int> danshi;
    rep(j, m){
      int sum = 0;
      rep(i, n){
        if (bit & (1<<i)) sum += gift[i][j];
      }
      danshi.push_back(sum);
    }
    sort(danshi.begin(), danshi.end(), greater<int>());
    rep(j, q) tmp += danshi[j];
    chmax(res, tmp);
  }
  cout << res << endl;
  return 0;
}
