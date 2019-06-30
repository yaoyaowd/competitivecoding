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
#define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, m;

int main() {
  freopen("in.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  if (n == 2 && m == 3) {
    cout << "1 1\n1 3\n1 2\n2 2\n2 3\n2 1\n";
    return 0;
  }
  for (int i = 0; i < n / 2; ++i)
    for (int j = 0; j < m; ++j) {
      cout << i + 1 << " " << j + 1 << endl;
      cout << n - i << " " << m - j << endl;
    }
  if (n % 2) {
    int x = n / 2;
    deque<int> have;
    cout << x+1 << " " << 1 << '\n';
    for (int i = 1; i < m; ++i) {
      have.pb(i);        
    }
    while (have.size()) {
      cout << x+1 << " "  << have.back()+1 << '\n';
      have.pop_back();
      if (have.size()) {
        cout << x+1 << " " << have.front()+1 << '\n';
        have.pop_front();
      }
    } 
  }
  return 0;
}