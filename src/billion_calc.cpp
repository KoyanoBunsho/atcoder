#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    vector<int> b(n);
    rep(i, n)cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    ll L=0, R=1e18;
    while(R-L>1){
        ll M = (L+R)/2;
        ll K = k;
        rep(i, n)K-=upper_bound(b.begin(), b.end(), M/a[i])-b.begin();
        if(K>0)L=M;
        else R=M;
    }
    cout << R << endl;
    return 0;
}