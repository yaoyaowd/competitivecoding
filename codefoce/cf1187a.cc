#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;
const int MAXV = 3 * MAXN;

int n,s,t;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> n >> s >> t;
        s = min(s, t);
        cout << n + 1 - s << endl;    
    }
    
    return 0;
}