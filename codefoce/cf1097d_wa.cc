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
#define mod 1000000007
#define maxn 100010
#define maxk 101
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll n, k;
vector<ll> a;
vector<vector<ll>> d;
vector<ll> p;

ll inverse(ll s) {
    int x = mod - 2;
    ll base = s;
    ll ans = 1;
    while (x > 0) {
        if (x % 2 == 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        x /= 2;
    }
    return ans;
}

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

void solve() {
    for (ll i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            a.pb(i);
            if (n / i != i) a.pb(n / i);
        }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        d.pb(vector<ll>());
        for (int j = 0; j <= i; ++j)
            if (a[i] % a[j] == 0) d[i].pb(j);
    }
    
    p.resize(a.size());
    ll base = d[0].size();
    for (int j = 0; j < a.size(); ++j)
        base = (base * d[j].size()) / gcd(base, d[j].size());
    ll s = base;
    for (int j = 0; j < a.size(); ++j)
        p[j] = s / a.size();

    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < a.size(); ++j) {
            ll w = (p[j] * (base / d[j].size())) % mod;
            p[j] = 0;
            for (int t = 0; t < d[j].size(); ++t) {
                p[d[j][t]] = (p[d[j][t]] + w) % mod;
            }
        }
        s = (s * base) % mod;
    }

    ll sp = 0;
    for (int i = 0; i < p.size(); ++i) sp = (sp + a[i] * p[i] % mod) % mod;
    if (sp < 0) sp += mod;

    cout << sp * inverse(s) % mod << endl;
}

int main() {
    cin >> n >> k;
    solve();
    return 0;
}