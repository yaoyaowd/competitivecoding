#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

string s;
int64_t a[27];
int64_t c[27 * 27];

void solve() {
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < 26; ++j)
            c[j * 26 + s[i] - 'a'] += a[j];
        a[s[i] - 'a']++;
    }
    int64_t ans = 0;
    for (int i = 0; i < 26; ++i)
        ans = max(ans, a[i]);
    for (int i = 0; i < 26 * 26; ++i)
        ans = max(ans, c[i]);
    cout << ans << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    solve();

    return 0;
}
