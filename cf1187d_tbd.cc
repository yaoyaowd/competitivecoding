#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 7;

int n;
int a[maxn];
int b[maxn];
map<int, int> m1, m2;

void init() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
}

void solve() {
    m1.clear();
    m2.clear();
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (m1.size() > 0 && m1.begin()->first == b[i]) {
            m1.begin()->second -= 1;
            if (m1.begin()->second == 0) {
                m1.erase(m1.begin());
            }
            if (m1.empty()) {
                m1 = m2;
                m2.clear();
            }
        } else if (m2.size() > 0 && m2.begin()->first == b[i] && m1.begin()->first > b[i]) {
            m2.begin()->second -= 1;
            if (m2.begin()->second == 0) {
                m2.erase(m2.begin());
            }
        } else {
            if (m1.size() == 0) {
                while (c < n) {
                    m1[a[c]] = m1[a[c]] + 1;
                    c += 1;
                    if (m1.begin()->first == b[i])
                        break;
                }
            } else {
                for (auto it : m2) {
                    m1[it.first] += it.second;
                }
                m2.clear();
                while (c < n) {
                    m2[a[c]] = m2[a[c]] + 1;
                    c += 1;
                    if (m2.begin()->first == b[i])
                        break;
                }
            }

            if (m1.size() > 0 && m1.begin()->first == b[i]) {
                m1.begin()->second -= 1;
                if (m1.begin()->second == 0) {
                    m1.erase(m1.begin());
                }
                if (m1.empty()) {
                    m1 = m2;
                    m2.clear();
                }
            } else if (m2.size() > 0 && m2.begin()->first == b[i] && m1.begin()->first > b[i]) {
                m2.begin()->second -= 1;
                if (m2.begin()->second == 0) {
                    m2.erase(m2.begin());
                }
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        init();
        solve();
    }
    return 0;
}