#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const int inf = 1e8;
const int mod = 1000000007;

int t;
int n, m, a, b;
ll c[maxn];
ll tree[maxn << 2];
vector<int> e[maxn];

void init() {
    cin >> n >> m >> a >> b;
    a -= 1;
    b -= 1;
    for (int i = 0; i < maxn; ++i) 
        e[i].clear();
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p >> c[i];
        if (p != 0) {
            e[p - 1].push_back(i);
            e[i].push_back(p - 1);
        }
    }
    for (int i = 0; i < maxn << 2; ++i) {
        tree[i] = -1;
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

int critical_path[maxn];
int length;
bool dfs(int a, int fa) {
    // cout << a << " " << fa << " " << length << endl;
    critical_path[length] = a;
    length += 1;
    if (a == b) {
        return true;
    }

    for (int i = 0; i < e[a].size(); ++i) {
        if (e[a][i] != fa) {
            if (dfs(e[a][i], a)) {
                return true;
            }
        }
    }

    length -= 1;
    return false;
}

void dfs2(int p, int fa1, int fa2, int base, int d) {
    ll v = cost(0, 0, length, d);
    if (v == -1) {
        return;
    }
    if (c[p] != 0 && m > d - base) {
        insert(0, 0, length, base, base + m - d + base, v + c[p]);
    }

    for (int i = 0; i < e[p].size(); ++i)
        if (e[p][i] != fa1 && e[p][i] != fa2) {
            dfs2(e[p][i], p, -1, base, d + 1);
        }
}

void work() {
    length = 0;
    memset(critical_path, 0, sizeof(critical_path));
    dfs(a, -1);

    for (int i = 0; i < length; ++i) {
        if (i == 0) {
            insert(0, 0, length, 0, m, 0);
        } else {
            ll v = cost(0, 0, length, i);
            if (v == -1) {
                cout << -1 << endl;
                return;
            }
            int p = critical_path[i];
            if (c[p] != 0) {
                insert(0, 0, length, i, i + m, v + c[p]);    
            }
            dfs2(p, critical_path[i - 1], critical_path[i + 1], i, i);
        }
    }
    ll ans = cost(0, 0, length, length - 1);
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
