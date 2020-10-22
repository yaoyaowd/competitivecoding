#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

vector<int> a;
int n, d;

void solve() {
    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = a[0];
    for (int i = 1; i < n; ++i) {
        ans += min(a[i], d / i);
        d -= min(a[i], d / i) * i;
    }
    cout << ans << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();

    return 0;
}
