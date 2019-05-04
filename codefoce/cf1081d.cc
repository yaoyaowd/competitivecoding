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
#define maxn 100010
#define maxk 101
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, k;
vector<pair<int, pair<int, int> > > edges;
int fa[maxn];
int weight[maxn];

int f(int u) {
    if (u != fa[u]) {
        fa[u] = f(fa[u]);
    }
    return fa[u];
}

int merge(int u, int v) {
    u = f(u);
    v = f(v);
    if (v != u) {
        fa[v] = u;
        weight[u] += weight[v];
    }
}

int solve() {
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; ++i) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (f(u) != f(v)) {
            merge(u, v);
        }
        if (weight[fa[u]] == k || weight[fa[v]] == k) {
            return edges[i].first;
        }
    }
    return -1;
}

void init() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n +1; ++i) fa[i] = i;
    memset(weight, 0, sizeof(weight));
    for (int i = 0; i < k; ++i) {
        int t;
        scanf("%d", &t);
        weight[t] = 1;
    }
    for (int i =0; i < m; ++i) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        edges.pb(mp(w, mp(x, y)));
    }
}

int main(){
    init();
    int ans = solve();
    for (int i = 0; i < k; ++i) {
        if (i != 0) cout << " ";
        cout << ans;
    }
    cout << endl;
    return 0;
}