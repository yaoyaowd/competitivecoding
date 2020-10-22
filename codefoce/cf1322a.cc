#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int n;
std::string s;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> s;

  int sum = 0;
  bool inseq = false;
  int ans = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ')') {
      sum--;
    } else if (s[i] == '(') {
      sum++;
    }
    if (sum < 0) {
      inseq = true;
    }
    if (inseq) {
      ans++;
    }
    if (sum >= 0) {
      inseq = false;
    }
  }
  if (sum == 0) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
