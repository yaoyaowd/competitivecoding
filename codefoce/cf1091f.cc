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

int n;
vector<ll> a;
string s;

ll solve() {
    ll ans = 0;
    ll w = 0, g = 0;
    bool havew = false, haveg = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            ans += a[i];
            
            ll d = min(w, a[i]);
            w -= d;
            a[i] -= d;
            ans += d;

            d = min(g, a[i]);
            a[i] -= d;
            g -= d;
            ans += d * 2;

            if (havew) {
                d = a[i];
                a[i] -= d;
                ans += 3 * d;
            }
            if (haveg) {
                d = a[i];
                a[i] -= d;
                ans += 5 * d;
            }
        } else if (s[i] == 'W') {
            ans += a[i] * 2;
            w += a[i];
            havew = true;
        } else if (s[i] = 'G') {
            ll d = min(a[i], w);
            ans += d * 2;
            a[i] -= d;
            g += d * 2;
            w -= d;

            ans += a[i] * 3;
            g += a[i];
            haveg = true;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> s;
    cout << solve() << endl;
    return 0;
}