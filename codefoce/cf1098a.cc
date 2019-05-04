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
vector<vector<int>> a;
vector<int> s;
vector<ll> v;

bool solve(int cs, int r) {
    bool success = true;
    if (s[r] != -1) {
        v[r] = s[r] - cs;
        if (v[r] < 0) return false;
        for (int i = 0; i < a[r].size(); ++i) {
            success &= solve(s[r], a[r][i]);
        }
    } else if (a[r].size() > 0) {
        int minsr = -1;
        for (int i = 0; i < a[r].size(); ++i) {
            if (minsr == -1 || s[a[r][i]] < minsr) {
                minsr = s[a[r][i]];
            }
        }
        if (minsr < cs) return false;
        v[r] = minsr - cs;
        s[r] = minsr;
        for (int i = 0; i < a[r].size(); ++i) {
            success &= solve(s[r], a[r][i]);
        }
    } else {
        s[r] = cs;
        v[r] = 0;
    }
    return success;
}

int main() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        a[x].pb(i);
    }
    s.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    v.resize(n + 1);
    bool success = solve(0, 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += v[i];
    }
    if (success) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}