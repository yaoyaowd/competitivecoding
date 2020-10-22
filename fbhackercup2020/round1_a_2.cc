#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const int inf = 1e8;
const int mod = 1000000007;

int t;
ll n, k;
vector<ll> l;
vector<ll> w;
vector<ll> h;

void init() {
    l.clear();
    w.clear();
    h.clear();

    cin >> n >> k;
    
    for (int i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        l.push_back(x);
    }
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = k; i < n; ++i) {
        ll x = ((a * l[i - 2] + b * l[i - 1] + c) % d) + 1;
        l.push_back(x);
    }

    for (int i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        w.push_back(x);
    }
    cin >> a >> b >> c >> d;
    for (int i = k; i < n; ++i) {
        ll x = ((a * w[i - 2] + b * w[i - 1] + c) % d) + 1;
        w.push_back(x);
    }

    for (int i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        h.push_back(x);
    }
    cin >> a >> b >> c >> d;
    for (int i = k; i < n; ++i) {
        ll x = ((a * h[i - 2] + b * h[i - 1] + c) % d) + 1;
        h.push_back(x);
    }
}

map<pair<ll, ll>, ll> seg;

void work() {
    seg.clear();

    ll p = 0;
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        // cout << i << " " << l[i] << " " << l[i] + w[i] << " " << h[i] << endl;
        if (i == 0) {
            p = (w[i] + w[i] + h[i] + h[i]);
            seg.emplace(make_pair(l[i], l[i] + w[i]), h[i]);
        } else {
            auto s = make_pair(l[i], l[i] + w[i]);
            auto after = seg.lower_bound(s);
            if (after == seg.end()) {
                after--;
            }

            ll addition_p = w[i] + w[i];
            ll l_bound = s.first;
            ll r_bound = s.second;
            bool merge = false;
            bool removed = false;
            bool boundray = true;
            while (after != seg.begin() && after->first.first > s.first) {
                --after;
            }

            if (after->first.first <= s.first) {
                // cout << after->first.first << " " << after->first.second << endl;
                if (after->first.second >= s.second) {
                    removed = true;
                } else if (after->first.second >= s.first) {
                    l_bound = after->first.first;
                    boundray = false;
                    addition_p -= (after->first.second - s.first) * 2;
                    merge = true;
                    auto tbd = after;
                    ++after;
                    seg.erase(tbd);
                } else {
                    ++after;
                }
            }

            while (!removed && after != seg.end()) {
                // Maybe merge with right.
                // cout << after->first.first << " " << after->first.second << endl;
                if (after->first.first <= s.second) {
                    if (after->first.second >= s.second) {
                        r_bound = after->first.second;
                        boundray = false;
                        addition_p -= (s.second - after->first.first) * 2;
                        if (merge) {
                            p = p - h[i] - h[i];
                        }
                        merge = true;
                        auto tbd = after;
                        ++after;
                        seg.erase(tbd);
                        break;
                    } else {
                        addition_p -= (after->first.second - after->first.first) * 2;
                        boundray = false;
                        if (merge) {
                            p = p - h[i] - h[i];
                        }
                        merge=true;
                        auto tbd = after;
                        ++after;
                        seg.erase(tbd);
                    }
                } else {
                    break;
                }
            }

            if (!removed) {
                seg.emplace(make_pair(l_bound, r_bound), h[i]);
                // cout << "added: " << addition_p << " " << boundray << endl;
                p += addition_p;
                if (boundray) p += h[i] + h[i];
            }
        }
        // cout << "per: " << p << endl;
        ans = (ans * (p % mod)) % mod;
    }
    cout << ans << endl;
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
