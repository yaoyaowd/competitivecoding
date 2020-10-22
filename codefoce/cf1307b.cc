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
    sort(a.begin(), a.end());
    int ans = d / a[n - 1];
    if (d == ans * a[n - 1])
        cout << ans << endl;
    else if (ans > 0 && d > ans * a[n - 1])
        cout << ans + 1 << endl;
    else if (d < a[n - 1]) {
        for (int i = 0; i < n; ++i)
            if (a[i] == d) {
                cout << 1 << endl;
                return;
            }
        cout << 2 << endl;
    }
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
