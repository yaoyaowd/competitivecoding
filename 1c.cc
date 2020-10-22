#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const int inf = 1e8;
const int mod = 1000000007;

int t;
ll n, k;
string s;
vector<int> e;

void init() {
    cin >> n >> k;
    cin >> s;
    
    e.clear();
    e.push_back(0);
    e.push_back(1);
    for (int i = 2; i < 2 + k; ++i) {
        int x;
        cin >> x;
        e.push_back(x);
    }

    ll aa, bb, cc;
    cin >> aa >> bb >> cc;
    for (int i = 2 + k; i <= n; ++i) {
        int x = ((aa * e[i - 2] + bb * e[i - 1] + cc) % (i - 1)) + 1;
        e.push_back(x);
    }
}

int siz[maxn];
int f[maxn];
int cnt[maxn];

int fa(int a) {
    if (f[a] != a) {
        f[a] = fa(f[a]);
        return f[a];
    }
    else
        return a;
}

void merge(int a, int b) {
    a = fa(a);
    b = fa(b);
    if (a != b) {
        if (siz[a] > siz[b]) {
            f[b] = a;
            siz[a] += siz[b];
        } else {
            f[a] = b;
            siz[b] += siz[a];
        }
    }
}

// a normal, b covid.
vector<ll> new_edge[maxn];
void edge(int a, int b) {
    a = fa(a);
    b = fa(b);
    cnt[a] += 1;
    new_edge[a].push_back(b);
    new_edge[b].push_back(a);
}

vector<pair<ll, ll>> final;
vector<ll> infect;
ll ans0, ans1;
int check[maxn];

void dfs1(int u, int depth) {
    check[u] = 1;
    for (int i = 0; i < new_edge[u].size(); ++i) {
        int v = new_edge[u][i];
        if (!check[v]) {
            dfs1(v, depth + 1);
        }
    }
    if (siz[u] == final[1].first && s[u - 1] == '*') {
        ans1 += depth * final[0].first * final[1].first;
    }
}

void case0() {
    ans0 = (final[0].first + final[1].first) * (final[0].first + final[1].first - 1) / 2;
    for (int i = 1; i <= n; ++i)
        if (f[i] == i && siz[i] == final[0].first && s[i - 1] == '*') {
            dfs1(i, 0);
            break;
        }
    cout << ans0 << " " << ans1 << endl;
}

ll large_cnt = 0;

ll dfs2(int u, int depth) {
    ll local_large = 0;

    check[u] = 1;
    for (int i = 0; i < new_edge[u].size(); ++i) {
        int v = new_edge[u][i];
        if (!check[v]) {
            local_large += dfs2(v, depth + 1);
        }
    }

    if (f[u] == u && siz[u] == final[0].first && s[u - 1] == '*') {
        // cout << depth << endl;
        local_large += 1;
    }

    ans1 += local_large * final[0].first * (large_cnt - local_large) * final[0].first;

    return local_large;
}

void case1() {
    ans0 = (final[0].first + final[1].first) * (final[0].first + final[1].first - 1) / 2;
    for (int i = 0; i < final.size(); ++i)
        if (final[i].first == final[0].first) {
            large_cnt += 1;
        }

    for (int i = 1; i <= n; ++i)
        if (f[i] == i && siz[i] == final[0].first && s[i - 1] == '*') {
            dfs2(i, 0);
            break;
        }
    cout << ans0 << " " << ans1 << endl;
}

void work() {
    ans0 = 0;
    ans1 = 0;
    large_cnt = 0;
    memset(siz, 0, sizeof(siz));
    memset(f, 0, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    memset(check, 0, sizeof(check));
    
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        siz[i] = 1;
    }
    for (int i = 1; i <= maxn; ++i) {
        new_edge[i].clear();
    }

    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] == '*' && s[e[i] - 1] == '*')
            merge(i, e[i]);
    }

    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] == '*' && s[e[i] - 1] == '#') {
            edge(i, e[i]);
        } else if (s[i - 1] == '#' && s[e[i] - 1] == '*') {
            edge(e[i], i);
        } else if (s[i - 1] == '#' && s[e[i] - 1] == '#') {
            edge(i, e[i]);
        }
    }

    final.clear();
    infect.clear();
    for (int i = 1; i <= n; ++i)
        if (f[i] == i && s[i - 1] == '*') {
            final.push_back(make_pair(siz[i], cnt[i]));
        } else if (f[i] == i)
            infect.push_back(siz[i]);

    sort(final.rbegin(), final.rend());
    if (final.size() == 0) {
        cout << 0 << " " << (n - 1) * (n - 1) << endl;
    } else if (final.size() == 1) {
        ll s = final[0].first;
        ll c = final[0].second;
        ll l = n - s - c;
        ll o = 0;
        for (int i = 0; i < infect.size(); ++i) {
            o += infect[i] * (n - s - infect[i]);
        }
        cout << final[0].first * (final[0].first - 1) / 2 << " " << o + s * (c + l) + (s - 1) * (s - 1) << endl;
    } else {
        if (final[0].first != final[1].first) {
            // cout << "c2" << endl;
            case0();
        } else {
            // cout << "c3" << endl;
            case1();
        }
    }
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
