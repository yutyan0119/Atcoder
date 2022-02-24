#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for (int i = s; i < e; i++)

typedef long long ll;

/* ---------------------------------------------------*/

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) {
    par.assign(n, -1);
    siz.assign(n, 1);
  }
  int root(int x) {
    if (par[x] == -1)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  int size(int x) { return siz[x]; }
};

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> va(N), vb(N);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    va[i] = make_pair(x, i);
    vb[i] = make_pair(y, i);
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < N - 1; i++) {
    edges.push_back(make_tuple(va[i + 1].first - va[i].first, va[i].second,
                               va[i + 1].second));
    edges.push_back(make_tuple(vb[i + 1].first - vb[i].first, vb[i].second,
                               vb[i + 1].second));
  }
  sort(edges.begin(), edges.end());
  UnionFind uf(N);
  ll ans = 0;
  for (auto p : edges) {
    int x, y, c;
    tie(c, x, y) = p;

    if (!uf.issame(x, y)) {
      uf.unite(x, y);
      ans += c;
    }
  }
  cout << ans << endl;
}