#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const int inf = 1e8;
const int mod = 1000000007;

int t;
int n, m;
ll c[maxn];
ll tree[maxn << 2];

void init() {
    cin >> n >> m;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
}

ll cost(int v, int tl, int tr, int k) {
    ll ans = -1;
    // cout << v << " " << tree[v] << " " << tl << " " << tr << " " << k << endl;
    if (ans == -1 || (tree[v] != -1 && tree[v] < ans)) {
        ans = tree[v];
    }

    if (tl == tr) {
        return ans;
    }

    int m = (tl + tr) / 2;
    ll o = -1;
    if (k <= m) {
        o = cost(v * 2 + 1, tl, m, k);
    } else {
        o = cost(v * 2 + 2, m + 1, tr, k);
    }
    if (ans == -1 || (o != -1 && o < ans)) {
        ans = o;
    }
    return ans;
}

void insert(int v, int tl, int tr, int l, int r, ll val) {
    // cout << "insert: " << v << " " << tl << " " << tr << " " << l << " " << r << " " << val << endl;
    if (tr < l || r < tl) {
        return;
    }
    if (l <= tl && tr <= r) {
        if (tree[v] == -1 || tree[v] > val) 
            tree[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    insert(v * 2 + 1, tl, tm, l, r, val);
    insert(v * 2 + 2, tm + 1, tr, l, r, val);
}

void work() {
    for (int i = 0; i < maxn << 2; ++i) {
        tree[i] = -1;
    }
    
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            insert(0, 0, n, 0, m, 0);
        } else if (c[i] != 0) {
            ll v = cost(0, 0, n, i);
            if (v == -1) {
                cout << -1 << endl;
                return;
            }
            insert(0, 0, n, i, i + m, v + c[i]);
        }
        // cout << i << " " << cost(0, 0, n, i) << endl;
    }
    ll ans = cost(0, 0, n, n - 1);
    cout << ans << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; ++i) {
        init();
        cout << "Case #" << i + 1 << ": ";
        work();
    }

    return 0;
}
