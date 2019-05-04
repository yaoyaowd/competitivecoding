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
vector<int> a;
bool check[maxn];
int incr[maxn], decr[maxn];
int incx[maxn], decx[maxn];

int solve1(vector<int>* ans) {
    memset(incr, 0, sizeof(incr));
    memset(decr, 0, sizeof(decr));
    memset(incx, 0, sizeof(incx));
    memset(decx, 0, sizeof(decx));
    int maxinc = 0, maxdec = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (!check[a[i]]) {
            if (maxinc == 0 && maxdec == 0) {
                incx[0] = a[i];
                decx[0] = a[i];
                incr[i] = 1;
                decr[i] = 1;
                maxinc++;
                maxdec++;
            } else {
                if (a[i] > incx[maxinc-1]) {
                    incx[maxinc] = a[i];
                    maxinc++;
                    incr[i] = maxinc;
                } else {
                    int l = 0, r = maxinc;
                    while (l < r) {
                        int m = (l + r) >> 1;
                        if (a[i] > incx[m]) {
                            l = m + 1;
                        } else {
                            r = m;
                        }
                    }
                    incx[l] = a[i];
                    incr[i] = l + 1;
                }
                if (a[i] < decx[maxdec-1]) {
                    decx[maxdec] = a[i];
                    maxdec++;
                    decr[i] = maxdec;
                } else {
                    int l = 0, r = maxdec;
                    while (l < r) {
                        int m = (l + r) >> 1;
                        if (a[i] < decx[m]) {
                            l = m + 1;
                        } else {
                            r = m;
                        }
                    }
                    decx[l] = a[i];
                    decr[i] = l + 1;
                }
            }
        }
    }

    if (maxinc > maxdec) {
        int select = n + 1;
        int selectx = maxinc;
        for (int i = a.size() - 1; i >= 0; --i) {
            if (!check[a[i]] && incr[i] == selectx && a[i] < select) {
                select = a[i];
                selectx--;
                check[a[i]] = true;
                ans->pb(a[i]);
            }
        }
    } else {
        int select = -1;
        int selectx = maxdec;
        for (int i = a.size() - 1; i >= 0; --i) {
            if (!check[a[i]] && decr[i] == selectx && a[i] > select) {
                select = a[i];
                selectx--;
                check[a[i]] = true;
                ans->pb(a[i]);
            }
        }
    }
    return ans->size();
}

int tot;
vector<int> l;

void solve() {
    int len = 0;
    memset(check, 0, sizeof(check));
    vector<vector<int>> anss;
    anss.pb(vector<int>());
    len += solve1(&anss[anss.size() - 1]);
    while (len < n) {
        anss.pb(vector<int>());
        len += solve1(&anss[anss.size() - 1]);
    }
    // if (tot != 4000) {
        cout << anss.size() << endl;
        for (int i = 0; i < anss.size(); ++i) {
            cout << anss[i].size();
            for (int j = 0; j < anss[i].size(); ++j) cout << " " << anss[i][anss[i].size() - j - 1];
            cout << endl;
        }
    // }
}

int main() {
    int t;
    cin >> t;
    tot = t;
    while (t > 0) {
        t--;
        cin >> n;
        l.pb(n);
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        solve();
    }
    return 0;
}