#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int t;
int n;
vector<string> a;
int ending[10];

void work() {
  cin >> n;
  a.clear();
  memset(ending, 0, sizeof(ending));
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    a.push_back(s);
    ending[s[3] - '0'] = 1;
  }

  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j)
      if (a[j] == a[i]) {
        ++ret;
        break;
      }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j)
      if (a[i] == a[j]) {
        for (int t = 0; t < 10; ++t) {
          if (ending[t] == 0) {
            ending[t] = 1;
            a[i][3] = t + '0';
            break;
          }
        }
        break;
      }
  }

  cout << ret << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t > 0) {
    work();
    t--;
  }
  return 0;
}
