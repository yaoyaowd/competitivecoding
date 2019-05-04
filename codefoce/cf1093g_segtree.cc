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
#define maxn 200010
#define maxk 101
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

namespace segtree {
    struct data {
        vector<int> ma, mi;
        data() {}
        data(int k) {
            ma.resize(k, -mod);
            mi.resize(k, mod);
        }
        data(const vector<int>& p) {
            int k = p.size();
            ma.resize((1<<k), -mod);
            mi.resize((1<<k), mod);
            for (int i = 0; i < (1 << k); ++i) {
                int v = 0;
                for (int j = 0; j < k; ++j)
                    v += ((i >> j) & 1) ? p[j] : -p[j];
                ma[i] = max(ma[i], v);
                mi[i] = min(mi[i], v);
            }
        }
        void init(const vector<int>& p) {
            int k = p.size();
            ma.resize(1<<k);
            mi.resize(1<<k);
            for (int i = 0; i < (1<<k); ++i) ma[i] = -mod;
            for (int i = 0; i < (1<<k); ++i) mi[i] = mod;
            for (int i = 0; i < (1 << k); ++i) {
                int v = 0;
                for (int j = 0; j < k; ++j)
                    v += ((i >> j) & 1) ? p[j] : -p[j];
                ma[i] = max(ma[i], v);
                mi[i] = min(mi[i], v);
            }
        }
        void resize(int k) {
            ma.resize(k);
            mi.resize(k);
            for (int i = 0; i < k; ++i) ma[i] = -mod;
            for (int i = 0; i < k; ++i) mi[i] = mod;
        }
    };
    data a[maxn + maxn + maxn + maxn];
    void merge(const data& l, const data& r, data& o) {
        o.resize(l.ma.size());
        for (int i = 0; i < o.ma.size(); ++i) {
            o.ma[i] = max(o.ma[i], l.ma[i]);
            o.ma[i] = max(o.ma[i], r.ma[i]);
            o.mi[i] = min(o.mi[i], l.mi[i]);
            o.mi[i] = min(o.mi[i], r.mi[i]);
        }
    }
    void build(int l, int r, const vector<vector<int>> &p, int c=0) {
        if (r - l == 1) {
            a[c].init(p[l]);
            return;
        }
        build(l, (l + r) >> 1, p, c + c + 1);
        build((l + r) >> 1, r, p, c + c + 2);
        merge(a[c + c + 1], a[c + c + 2], a[c]);
    }
    void modify(int l, int r, int z, const vector<int>&p, int c=0) {
        if (r - l == 1) {
            a[c].init(p);
            return;
        }
        if (z < (l + r) >> 1)
            modify(l, (l + r) >> 1, z ,p, c + c + 1);
        else
            modify((l+r) >> 1, r, z, p, c + c + 2);
        merge(a[c + c + 1], a[c + c + 2], a[c]);
    }
    void query(int l, int r, int ql, int qr, data& ans, int c=0) {
        if (l >= ql && r <= qr) { 
            for (int i = 0; i < a[c].ma.size(); ++i) {
                ans.ma[i] = max(ans.ma[i], a[c].ma[i]);
                ans.mi[i] = min(ans.mi[i], a[c].mi[i]);
            }
            return;
        }
        if (qr <= (l + r) >> 1) {query(l, (l + r) >> 1, ql, qr, ans, c + c + 1); return;}
        if (ql >= (l + r) >> 1) {query((l + r) >> 1, r, ql, qr, ans, c + c + 2); return;}
        query(l, (l +r) >> 1, ql, qr, ans, c + c + 1);
        query((l + r) >> 1, r, ql, qr, ans, c + c + 2);
    }
}

int n, k;
vector<vector<int> > p;

void init() {
    cin >> n >> k;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        p[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> p[i][j];
        }
    }
}

int q;
vector<int> b;
segtree::data res;

void work() {
    b.resize(k);
    segtree::build(0, n, p);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int z;
            cin >> z;
            z--;
            for (int j = 0; j < k; ++j) cin >> b[j];
            segtree::modify(0, n, z, b);
        } else {
            int l, r;
            cin >> l >> r;
            res.resize(1 << k);
            segtree::query(0, n, l - 1, r, res);
            int ans = 0;
            for (int j =0; j < (1 <<k); ++j) ans = max(ans, res.ma[j] - res.mi[j]);
            cout << ans << endl;
        }
    }
}

int main(){
    init();
    work();
    return 0;
}