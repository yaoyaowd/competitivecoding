#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define pb push_back
#define mp make_pair
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define mod 998244353
#define maxn 1000010
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
int m;
int t;
vector<vector<int>> a;
vector<int> b;
vector<int> c;

void init() {
    cin >> n >> m;
    a.clear();
    a.resize(n + 1);
    b.clear();
    b.resize(n + 1);
    c.clear();
    c.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
}

void dfs(int u, int& c0, int& c1) {
    c[u] = 1;
    if (b[u] == 0) c0++;
    else c1++;
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (!c[v]) {
            b[v] = 1 - b[u];
            dfs(v, c0, c1);
        }
    }
}

ll pow2(int b) {
    ll ret = 1;
    for (int i = 0; i < b; ++i) {
        ret = (ret + ret) % mod;
    }
    return ret;
}

void solve() {
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 0) {
            int b0 = 0, b1 = 0;
            dfs(i, b0, b1);
            ll tmp = (pow2(b0) + pow2(b1)) % mod;
            ans = (ans * tmp) % mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < a[i].size(); ++j)
            if (b[i] == b[a[i][j]]) {
                cout << 0 << endl;
                return;
            }
    }
    cout << ans << endl;
}

int main(){
    cin >> t;
    for (int i = 0 ; i < t; ++i) {
        init();
        solve();
    }
    return 0;
}