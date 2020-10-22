#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

vector<int> a;
int n;
int c[1010];

int mex(const vector<int>& a) {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i)
        c[a[i]] = 1;
    for (int i = 0; i < n + 1; ++i)
        if (c[i] == 0)
            return i;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> as;
    for (int i = 0; i < n; ++i) {
        int v = mex(a);
        if (v < n) {
            as.push_back(v + 1);
            a[v] = v;
        } else {
            for (int j = 0; j < n; ++j) {
                if (a[j] != j) {
                    as.push_back(j + 1);
                    a[j] = n;
                    v = mex(a);
                    as.push_back(v + 1);
                    a[v] = v;
                    break;
                }
            }
        }
    }

    int ans = as.size();
    cout << ans << endl;
    for (int i = 0; i < ans; ++i)
        cout << as[i] << " ";
    cout << endl;
}


int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
