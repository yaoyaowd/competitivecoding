#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

vector<pair<int, int>> p;
int n;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
    p[i].first += 1e6;
    p[i].second += 1e6;
  }

  while (true) {
    vector<vector<int>> cnt(2, vector<int>(2));
    
    for (int i = 0; i < n; ++i)
      cnt[p[i].first % 2][p[i].second % 2] += 1;
    
    if (cnt[0][0] + cnt[1][1] > 0 && cnt[0][1] + cnt[1][0] > 0) {
      cout << cnt[0][0] + cnt[1][1] << endl;
      for (int i = 0; i < n; ++i)
        if ((p[i].first + p[i].second) % 2 == 0)
          cout << i + 1 << " ";
      break;
    }

    if (cnt[0][0] + cnt[0][1] > 0 && cnt[1][1] + cnt[1][0] > 0) {
      vector<int> a;
      for (int i = 0; i < n; ++i)
        if (p[i].first % 2 == 0)
          a.push_back(i);
      cout << a.size() << endl;
      for (int i = 0; i < a.size(); ++i)
        cout << a[i] + 1 << " ";
      break;
    }

    int x, y;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (cnt[i][j] > 0) {
          x = i;
          y = j;
        }
    for (int i = 0; i < n; ++i) {
      p[i].first = (p[i].first - x) / 2;
      p[i].second = (p[i].second - y) / 2;
    }
  }
  return 0;
}
