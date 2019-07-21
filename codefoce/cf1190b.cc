#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 7;
const int mod = 998244353;

ll n;
vector<ll> a;

bool scheck() {
    for (int i = 0; i < n; ++i)
        if (a[i] < i) {
            return true;
        }

    int c = 0;
    for (int i = 0; i < n - 1; ++i)
        if (a[i] == a[i + 1]) {
            c++;
            if (i > 0 && a[i - 1] == a[i] - 1) {
                return true;
            }
        }
    if (c > 1) {
        return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    if (n == 1) {
        if (a[0] % 2 == 1) {
            cout << "sjfnb" << endl;
        } else {
            cout << "cslnb" << endl;
        }
    } else if (scheck()) {
        cout << "cslnb" << endl;
    } else {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            a[i] -= i;
            sum = (sum + a[i]) % 2;
        }
        if (sum % 2 == 1) {
            cout << "sjfnb" << endl;
        } else {
            cout << "cslnb" << endl;
        }
    }
    return 0;
}