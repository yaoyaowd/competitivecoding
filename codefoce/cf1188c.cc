#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 7;
const int mod = 998244353;

int n, k;
vector<int> a;
int f[1010][1010];

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 1; i <= a[n - 1] - a[0]; ++i) {
        if (i * (k - 1) + a[0] > a[n - 1])
            break;
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        f[0][1] = 1;
        int c = -1;
        for (int j = 1; j < n; ++j) {
            while (a[j] - a[c + 1] >= i) {
                c++;
            }
            f[j][0] = 1;
            f[j][1] = (1 + f[j - 1][1]) % mod;
            for (int t = 2; t <= k; ++t) {
                f[j][t] = f[j - 1][t];
                if (c >= 0) {
                    f[j][t] = (f[j][t] + f[c][t - 1]) % mod;
                }
                cout << j << " " << c << " " << t << " " << f[j][t] << endl;
            }
        }
        ans = (ans + f[n - 1][k]) % mod;
    }

    cout << ans << endl;
    return 0;
}