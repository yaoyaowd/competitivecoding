#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 7;
const int mod = 998244353;

template <unsigned int N> class Field {
  typedef unsigned int ui;
  typedef unsigned long long ull;
public:
  Field(int x = 0) : v(x) {}
  Field<N>&operator+=(const Field<N>&o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
  Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
  Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
  inline explicit operator ui() const { return v; }
private:
  ui v;
};

template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}

typedef Field<mod> F;


int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    c[i] = x - 1;
  }

  vector<int> w;
  for (int i = 0; i < m; ++i) {
    if (w.size() == 0 || w.back() != c[i])
      w.push_back(c[i]);
  }
  m = w.size();
  if (m > 2 * n) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> e(n);
  for (int i = 0; i < m; ++i)
    e[w[i]].push_back(i);

  vector<vector<F>> d(m + 1, vector<F>(m + 1, 1));
  for (int l = 1; l <= m; ++l) {
    for (int a = 0; a + l <= m; ++a) {
      int lo = w[a];
      for (int i = 0; i < l; ++i) 
        lo = min(lo, w[a + i]);
      int j = e[lo][0] - a;
      int k = e[lo].back() - a;
      if (j < 0 || k >=l) {
        d[a][l] = 0;
        continue;
      }

      F left = 0, right = 0;
      for (int u = 0; u <= j; ++u)
        left += d[a][u] * d[a + u][j - u];
      for (int v = k + 1; v <= l; ++v)
        right += d[a + k + 1][v - (k + 1)] * d[a + v][l - v];
      d[a][l] = left * right;
      for (int i = 0; i < e[lo].size() - 1; ++i) {
        if (e[lo][i] + 1 != e[lo][i + 1]) {
          d[a][l] *= d[e[lo][i]+1][e[lo][i+1] - e[lo][i] - 1];
        }
      }
    }
  }

  cout << d[0][m] << endl;
  return 0;
}
