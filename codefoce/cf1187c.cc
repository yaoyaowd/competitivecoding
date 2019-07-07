#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;

int n,m;
int a[maxn];
int b[maxn];
int t[maxn];
int l[maxn];
int r[maxn];

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> t[i] >> l[i] >> r[i];
    
    for (int i = 0; i < m; ++i)
        if (t[i] == 1) {
            for (int j = l[i] + 1; j <= r[i]; ++j) {
                b[j] = 1;
            }
        }

    int cur = 1001;
    a[1] = cur;
    for (int i = 2; i <= n; ++i)
        if (b[i] == 1) {
            a[i] = cur;
        } else {
            cur--;
            a[i] = cur;
        }

    for (int i = 0; i < m; ++i)
        if (t[i] == 0) {
            bool success = false;
            for (int j = l[i] + 1; j <= r[i]; ++j)
                if (a[j] < a[j - 1])
                    success = true;
            if (!success) {
                cout << "NO" << endl;
                return 0;
            }
        }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i + 1] << " ";
    cout << endl;
    return 0;
}