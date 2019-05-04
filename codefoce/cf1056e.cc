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
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define mod 998244353
#define maxn 1000010
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;
string t;
vector<ull> h;
vector<ull> b;
int sc[2];

bool check(int l0) {
    if (t.length() <= l0 * sc[0])
        return false;
    if ((t.length() - l0 * sc[0]) % sc[1] != 0)
        return false;
    int l1 = (t.length() - l0 * sc[0]) / sc[1];

    ull h0 = 0, h1 = 0;
    ull b0 = 0, b1 = 0;
    bool h0e = false, h1e = false;
    int cur = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0' && h0e) {
            if ((h[cur + l0] + mod - h[cur]) % mod != (h0 * b[cur-b0]) % mod) {
                return false;
            }
            cur += l0;
        } else if (s[i] == '0') {
            h0 = (h[cur + l0] + mod - h[cur]) % mod;
            b0 = cur;
            h0e = true;
            cur += l0;
        } else if (s[i] == '1' && h1e) {
            if ((h[cur + l1] + mod - h[cur]) % mod != (h1 * b[cur-b1]) % mod) {
                return false;
            }
            cur += l1;
        } else if (s[i] == '1') {
            h1 = (h[cur + l1] + mod - h[cur]) % mod;
            b1 = cur;
            h1e = true;
            cur += l1;
        }
    }
    if ((h0 * b[b1]) % mod == (h1 * b[b0]) % mod) return false;
    return true;
}

int main(){
    cin >> s;
    cin >> t;
    for (int i = 0; i < s.length(); ++i) sc[s[i]-'0']++;

    h.pb(0);
    b.pb(1);
    ull base = 1;
    ull hend = 0;
    for (int j = 0; j < t.length(); ++j) {
        ull v = t[j] - 'a' + 2;
        hend = (v * base + hend) % mod;
        h.pb(hend);
        base = (base * 10) % mod;
        b.pb(base);
    }

    int ans = 0;
    for (int i = 1; i <= t.length() / sc[0]; i++)
        if (check(i)) ans++;
    cout << ans << endl;
    return 0;
}