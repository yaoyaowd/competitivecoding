#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 7;
const int mod = 998244353;

ll n, k;
ll m;
vector<ll> a;
ll p;
ll c;
ll last;
int ans = 0;

void locate(ll v) {
    if (v < last)
        return;
    else {
        p = last;
        p += (v - p) / k * k;
        last = p + k;
        if (v >= last) {
            p += k;
            last += k;
        }
    }
}

void remove() {
    ans++;
    ll new_last = last;
    while (c < m && a[c] < last) {
        c++;
        new_last++;
    }
    last = new_last;
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;
    a.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    c = 0;
    p = 1;
    last = k + 1;
    while (c < m) {
        locate(a[c]);
        remove();
    }
    cout << ans << endl;
    return 0;
}