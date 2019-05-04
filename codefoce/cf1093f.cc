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

int n, k, len;
int a[maxn];
int f[maxn][maxk];
bool s[maxn][maxk];
int g[maxn];
int l[maxn];

int calc(int p, int k) {
    if (p < 0) {
        return 1;
    }
    return (g[p] - f[p][k]) % mod;
}

void prepare() {
    memset(s, 0, sizeof(s));
    for (int i = 1; i < k+1; ++i) {
        memset(l, 0, sizeof(l));
        if (a[0] == i || a[0] == -1) {
            l[0] = 1;
        } else {
            l[0] = 0;
        }
        for (int j = 1; j < n; ++j) {
            if (a[j] == i || a[j] == -1) {
                l[j] = l[j-1] + 1;
            } else {
                l[j] = 0;
            }
        }
        for (int j = 0; j < n; ++j) s[j][i] = (l[j] >= len);
    }
}

int solve() {
    if (len == 1) {
        return 0;
    }
    prepare();

    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            if (i == 0) {
                f[i][a[i]] = 1;
            } else {
                f[i][a[i]] = g[i-1];
            }
            if (i + 1 >= len && s[i][a[i]]) {
                f[i][a[i]] = (f[i][a[i]] - calc(i - len, a[i])) % mod;
            }

            if (f[i][a[i]] < 0) {
                f[i][a[i]] += mod;
            }
            g[i] = f[i][a[i]];
        } else {
            for (int j = 1; j <= k; ++j) {
                if (i == 0) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = g[i-1];
                }
                if (i + 1 >= len && s[i][j]) {
                    f[i][j] = (f[i][j] - calc(i - len, j)) % mod;
                }

                if (f[i][j] < 0) {
                    f[i][j] += mod;
                }
                g[i] = (g[i] + f[i][j]) % mod;
                if (g[i] < 0) g[i] += mod;
            }
        }
    }
    return g[n-1];
}

int main(){
    cin >> n >> k >> len;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << solve() << endl;
    return 0;
}