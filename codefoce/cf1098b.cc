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
#define maxn 500010
#define maxk 101
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<string> tem{"AG", "AC", "AT", "GA", "GC", "GT", "CA", "CG", "CT", "TA", "TG", "TC"};

int n, m;
vector<string> s;
vector<int> a;
vector<int> b;
int f[300010][13];
int g[300010][13];
int ansa, ansb;

void solvea() {
    a.resize(n);
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 12; j++) {
            int diff = 0;
            for (int t = 0; t < s[i].length(); ++t)
                if (s[i][t] != tem[j][t%2])
                    diff++;
            if (i == 0) f[i][j] = diff;
            else {
                int ans = -1;
                for (int t = 0; t < 12; t++)
                    if (tem[j][0] != tem[t][0] && tem[j][0] != tem[t][1] && tem[j][1] != tem[t][0] && tem[j][1] != tem[t][1]) {
                        if (ans == -1 || f[i-1][t] < ans) {
                            ans = f[i-1][t];
                            g[i][j] = t;
                        }
                    }
                f[i][j] = ans + diff;
            }
        }
    }
    ansa = f[n-1][0];
    int ansg = 0;
    for (int i = 0; i < 12; i++)
        if (ansa > f[n-1][i]) {
            ansa = f[n-1][i];
            ansg = i;
        }
    int i = n - 1;
    while (i >= 0) {
        a[i] = ansg;
        ansg = g[i][ansg];
        i--;
    }
}

void solveb() {
    b.resize(m);
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 12; j++) {
            int diff = 0;
            for (int t = 0; t < n; ++t)
                if (s[t][i] != tem[j][t%2])
                    diff++;
            if (i == 0) f[i][j] = diff;
            else {
                int ans = -1;
                for (int t = 0; t < 12; t++)
                    if (tem[j][0] != tem[t][0] && tem[j][0] != tem[t][1] && tem[j][1] != tem[t][0] && tem[j][1] != tem[t][1]) {
                        if (ans == -1 || f[i-1][t] < ans) {
                            ans = f[i-1][t];
                            g[i][j] = t;
                        }
                    }
                f[i][j] = ans + diff;
            }
        }
    }
    ansb = f[m-1][0];
    int ansg = 0;
    for (int i = 0; i < 12; i++)
        if (ansb > f[m-1][i]) {
            ansb = f[m-1][i];
            ansg = i;
        }
    int i = m - 1;
    while (i >= 0) {
        b[i] = ansg;
        ansg = g[i][ansg];
        i--;
    }
}

int main(){
    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    solvea();
    solveb();
    if (ansa < ansb) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << tem[a[i]][j % 2];
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << tem[b[j]][i % 2];
            }
            cout << endl;
        }
    }
}