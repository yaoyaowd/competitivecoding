#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 7;
const int mod = 998244353;

int n;
vector<pair<int, int>> a;
int x_axis[maxn];
map<int, int> x_map;
ll tree[maxn * 8];
bool check[maxn];
ll ans = 0;

void inc(int root, int l, int r, int x) {
    tree[root] += 1;
    if (l == r - 1)
        return;
    else {
        int m = (l + r) / 2;
        if (x < m) {
            inc(root * 2 + 1, l, m, x);
        } else {
            inc(root * 2 + 2, m, r, x);
        }
    }
}

ll sum(int root, int l, int r, int ll, int rr) {
    // if (root >= 0) {
    //     cout << root << " " << l << " " << r << " " << ll << " " << rr << endl;
    // }
    if (ll >= rr) {
        return 0;
    }
    if (l == ll && r == rr) {
        return tree[root];
    }
    int m = (l + r) / 2;
    if (rr <= m) {
        return sum(root * 2 + 1, l, m, ll, rr);
    } else if (ll >= m) {
        return sum(root * 2 + 2, m, r, ll, rr);
    } else {
        return sum(root * 2 + 1, l, m, ll, m) + sum(root * 2 + 2, m, r, m, rr);
    }
}

void solve(int st, int ed) {
    ll l = sum(0, 0, n, 0, x_map[a[st].second]);
    ll ret = l * (l + 1) / 2;
    for (int i = st; i < ed; ++i) {
        if (i + 1 < ed) {
            ll r = sum(0, 0, n, x_map[a[i].second] + 1, x_map[a[i + 1].second]);
            ret += r * (r + 1) / 2;
        } else {
            ll r = sum(0, 0, n, x_map[a[i].second] + 1, n);
            ret += r * (r + 1) / 2;
        }
        if (!check[x_map[a[i].second]]) {
            inc(0, 0, n, x_map[a[i].second]);
            check[x_map[a[i].second]] = 1;
        }
    }
    ll m = tree[0];
    ans += m * (m + 1) / 2;
    ans -= ret;
    cout << m << " " << ans << " " << ret << endl;
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    memset(tree, 0, sizeof(tree));
    cin >> n;
    a.clear();
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        y = -y;
        x_axis[i] = x;
        a.push_back(make_pair(y, x));
    }
    sort(a.begin(), a.end());
    sort(x_axis, x_axis + n);
    for (int i = 0; i < n; ++i)
        x_map[x_axis[i]] = i;

    int c = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == n || a[i].first > a[c].first) {
            solve(c, i);
            c = i;
        }
    }
    cout << ans << endl;
    return 0;
}