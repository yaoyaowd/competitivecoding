#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 7;
const int mod = 998244353;

int n;
vector<pair<int, int>> a;

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int total = 0;
  cin >> n;
  for (int i =0 ; i < n; ++i) {
    int x;
    cin >> x;
    total += x;
    a.push_back(make_pair(x, i + 1));
  }
  int alice = a[0].first;
  sort(a.begin(), a.end());
  vector<pair<int, int>> ans;
  int atot = alice;
  for (int i = 0; i < n; ++i)
    if (a[i].first <= alice / 2) {
      ans.push_back(a[i]);
      atot += a[i].first;
    }
  if (atot > total / 2) {
    cout << ans.size() + 1 << endl;
    cout << 1;
    for (int i = 0; i < ans.size(); ++i)
      cout << " " << ans[i].second;
    cout << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
