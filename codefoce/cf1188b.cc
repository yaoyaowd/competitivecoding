#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 7;
const int maxv = 63;

int n, p, k;
map<int, int> mp;

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += p;
    return s % p;
}

int pw(int x) {
    x = (ll)x * (ll)x % p;
    x = (ll)x * (ll)x % p;
    return x;
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n >> p >> k;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int val = sub(pw(x), (ll)k * (ll)x % p);
        ans += mp[val];
        mp[val] += 1; 
    }
    cout << ans << endl;
    return 0;
}