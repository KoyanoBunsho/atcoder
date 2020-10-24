#include <bits/stdc++.h>
using namespace std;

int K, N;
double w[2100], p[2100];

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> w[i] >> p[i];
  }
  double lo = 0.0, hi = 100.0;
  for (int i = 0; i < 50; ++i) {
    double mi = (lo + hi) / 2;
    vector<double> tmp(N);
    for (int j = 0; j < N; ++j) {
      tmp[j] = (p[j] - mi) * w[j];
    }
    sort(tmp.begin(), tmp.end(), greater<double>());
    double sum = 0.0;
    for (int j = 0; j < K; ++j) sum += tmp[j];
    if (sum < 0.0) hi = mi;
    else lo = mi;
  }
  cout << fixed << setprecision(9) << hi << endl;
}
