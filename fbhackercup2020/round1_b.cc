#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const int inf = 1e8;
const int mod = 1000000007;

int t;
ll n, m, k, s;
vector<ll> p;
vector<ll> q;

void init() {
    cin >> n >> m >> k >> s;
    p.clear();
    q.clear();

    for (int i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        p.push_back(x);
    }
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = k; i < n; ++i) {
        ll x = ((a * p[i - 2] + b * p[i - 1] + c) % d) + 1;
        p.push_back(x);
    }

    for (int i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        q.push_back(x);
    }
    cin >> a >> b >> c >> d;
    for (int i = k; i < m; ++i) {
        ll x = ((a * q[i - 2] + b * q[i - 1] + c) % d) + 1;
        q.push_back(x);
    }
}

bool check(ll v) {
    int st = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(p[i] - q[st]) > v) {
            continue;
        }

        if (p[i] > q[st]) {
            int ed = st;
            while (ed + 1 < m && q[ed + 1] < p[i]) {
                ed += 1;
            }
            while (ed + 1 < m && (
                (q[ed + 1] - p[i]) * 2 + p[i] - q[st] <= v || 
                (p[i] - q[st]) * 2 + q[ed + 1] - p[i] <= v)) {
                ed += 1;
            }
            st = ed;
        } else {
            while (st + 1 < m && q[st + 1] - p[i] <= v) {
                st += 1;
            }
        }

        st += 1;
        if (st == m) {
            return true;
        }
    }

    return false;
}

void work() {
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    ll st = 0, ed = (max(p[n - 1], q[m - 1]) - min(p[0], q[0])) * m;
    ll mid;
    while (ed > st) {
        mid = (ed + st) / 2;
        if (check(mid)) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    mid = (ed + st) / 2;
    cout << mid << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; ++i) {
        init();
        cout << "Case #" << i + 1 << ": ";
        work();
    }

    return 0;
}
