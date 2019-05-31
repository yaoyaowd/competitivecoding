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
int a[26];

int main() {
  cin >> n;
  string name;
  for (int i = 0; i < n; ++i) {
    cin >> name;
    a[name[0] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    int x = a[i] / 2;
    ans += x * (x - 1) / 2;
    x = a[i] - x;
    ans += x * (x - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}