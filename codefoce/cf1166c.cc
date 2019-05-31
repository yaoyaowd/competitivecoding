#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <assert.h>

#define pb push_back
#define mp make_pair
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define maxn 100010
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n;
vector<int> a;

int solve(int x, int i) {
  int minj = i, maxj = n - 1;
  while (minj < maxj) {
    int midj = (minj + maxj + 1) / 2;
    if (a[midj] <= x + x) {
      minj = midj;
    } else {
      maxj = midj - 1;
    }
  }
  return minj - i;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += solve(a[i], i);
  }
  cout << ans << endl;
  return 0;
}