#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

int n, m, k;
vector<int> a[maxn];
int ds[maxn];
int de[maxn];
int ks[maxn];
bool appear = false;

void init() {
    cin >> n  >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        ks[x] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (ks[x] && ks[y])
            appear = true;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

int check[maxn];
vector<int> q;
void bfs(int s, int* d) {
    q.clear();
    memset(check, 0, sizeof(check));
    q.push_back(s);
    check[s] = 1;
    int o = 0;
    while (o < q.size()) {
        int u = q[o];
        for (int v : a[u]) {
            if (!check[v]) {
                d[v] = d[u] + 1;
                check[v] = 1;
                q.push_back(v);
            }
        }
        o++;
    }
}

void solve() {
    int ans = n + 1;
    for (int i = 1; i <= n; ++i)
        if (ds[i] + de[i] < ans)
            ans = ds[i] + de[i];
    if (appear) {
        cout << ans << endl;
        return;
    }
    int dsp[2];
    int dsm[2];
    int dep[2];
    int dem[2];
    memset(dsm, 0, sizeof(dsm));
    memset(dem, 0, sizeof(dem));
    for (int i = 1; i<= n; ++i)
        if (ks[i]) {
            if (ds[i] > dsm[0]) {
                dsm[1] = dsm[0];
                dsp[1] = dsp[0];
                dsm[0] = ds[i];
                dsp[0] = i;
            } else if (ds[i] > dsm[1]) {
                dsm[1] = ds[i];
                dsp[1] = i;
            }
            if (de[i] > dem[0]) {
                dem[1] = dem[0];
                dep[1] = dep[0];
                dem[0] = de[i];
                dep[0] = i;
            } else if (de[i] > dem[1]) {
                dem[1] = de[i];
                dep[1] = i;
            }
        }
    int pans = ans;
    ans = 0;
    for (int i = 1; i<=n; ++i)
        if (ks[i]) {
            int a1 = 0, a2 = 0;
            if (i != dep[0]) {
                a1 = ds[i] + 1 + dem[0];
            } else {
                a1 = ds[i] + 1 + dem[1];
            }
            if (i != dsp[0]) {
                a2 = dsm[0] + 1 + de[i];
            } else {
                a2 = dsm[1] + 1 + de[i];
            }
            ans = max(ans, min(a1, a2));
        }
    cout << min(ans, pans) << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    bfs(1, ds);
    bfs(n, de);
    solve();

    return 0;
}
