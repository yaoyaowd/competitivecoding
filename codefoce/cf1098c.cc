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

int n;
ll s;
vector<ll> smax;
vector<ll> smin;

void prepare(int m) {
    for (int i = 0; i <= n; ++i) {
        smax[i] = 0;
        smin[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        ll s = i + 1;
        smax[i] = s * (long long)i / 2;
    }

    ll x = 1;
    ll sx = 0;
    ll d = 0;
    ll ss = 0;
    while (sx < n) {
        if (sx + x <= n) {
            d++;
            for (int i = sx + 1; i <= sx + x; ++i) {
                smin[i] = ss + (long long)(i - sx) * d;
            }
            sx += x;
            ss += x * d;
            x *= m;
        } else {
            d++;
            for (int i = sx + 1; i <= n; ++i) {
                smin[i] = ss + (long long)(i - sx) * d;
            }
            ss += (n - sx) * d;
            sx = n;
        }
    }
}

vector<int> ans;
void special_work(int b, int c, int n) {
    // cout << c << " " << n << endl;
    for (int i = c + 1; i < c + n; ++i) {
        int fa = (i - c - 1) / b;
        ans[i] = fa + c;
    }
}

// b branch.
// start from c.
// n node.
// s sum
void work(int b, int c, int n, ll s) {
    // cout << c << " " << n << " " << s << endl;
    if (s == smin[n]) {
        special_work(b, c, n);
        return;
    }
    int l = (n - 1) / b;
    int r = (n - 1);
    int m = 0;
    while (l < r) {
        m = (l + r) / 2;
        ll mins = smin[m];
        ll maxs = smax[m];
        
        ll nleft = n - 1 - m;
        int nb = nleft / (b - 1);
        int nl = nleft % (b - 1);
        mins += n + smin[nb] * (b - 1 - nl) + smin[nb + 1] * nl;
        maxs += n + smin[nb] * (b - 1 - nl) + smin[nb + 1] * nl;

        if (mins <= s && maxs >= s) {
            break;
        } else if (maxs < s) {
            l = m + 1;
        } else if (mins >= s) {
            r = m;
        }
    }
    m = (l + r) / 2;
    ll mins = smin[m];
    ll maxs = smax[m];
    ll nleft = n - 1 - m;
    int nb = nleft / (b - 1);
    int nl = nleft % (b - 1);
    s -= n + smin[nb] * (b - 1 - nl) + smin[nb + 1] * nl;
    ans[c + 1] = c;
    work(b, c + 1, m, s);

    int newc = c + m + 1;
    for (int i = 1; i < b; ++i) {
        int nn = nb;
        if (i <= nl) nn += 1;
        ans[newc] = c;
        special_work(b, newc, nn);
        newc = newc + nn;
    }
}

void solve() {
    smax.resize(n + 10);
    smin.resize(n + 10);
    int l = 1, r = n, m = 0;
    while (l < r) {
        m = (l + r) / 2;
        prepare(m);
        if (smin[n] > s) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    m = (l + r) / 2;
    if (m >= n) {
        cout << "No" << endl;
        return;
    }

    prepare(m);
    ans.resize(n + 10);
    if (smin[n] <= s && smax[n] >= s) {
        cout << "Yes" << endl;
        work(m, 1, n, s);
        for (int i = 2; i <= n; ++i) cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin >> n;
    cin >> s;
    solve();
    return 0;
}