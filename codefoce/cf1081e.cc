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

int n;
vector<ll> a;

void init() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n /2; ++i) cin >> a[i+i];
}

bool find_minimal(ll s, ll x, ll& c) {
    for (ll i = 1; i*i <= x; ++i) {
        if (x % i == 0) {
            ll b = (x/i +i) / 2;
            ll a = (x/i -i) / 2;
            if (b * b - a * a != x) continue;
            if (a * a <= s) continue;
            c = a * a - s;
        }
    }
    return c != -1;
}

bool solve() {
    ll s = 0;
    for (int i = 1; i <= n /2; ++i) {
        ll c = -1;
        if (!find_minimal(s, a[i+i], c)) {
            return false;
        } else {
            a[i+i-1] = c;
            s += c;
            s += a[i + i];
        }
    }
    return true;
}

int main(){
    init();
    bool s = solve();
    if (s) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; ++i) {
            if (i != 1) cout << " ";
            cout << a[i];
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}