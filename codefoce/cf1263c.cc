#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;
 
int t;
int n;
vector<int> ans;
 
void work() {
  cin >> n;
  ans.clear();
  for (int i = 1; i <= n / i; ++i) {
    ans.push_back(i);
    if (i != n / i) {
      ans.push_back(n / i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() + 1 << endl;
  cout << 0;
  for (int i = 0; i < ans.size(); ++i)
    cout << " " << ans[i];
  cout << endl;
}
 
int main() {
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
