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

typedef long long ll;

/* ---------------------------------------------------*/

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) {
    par.assign(n, -1);
    siz.assign(n, -1);
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

using Edge = pair<int, pair<int, int>>;

int main() {
  int V, E;
  cin >> V >> E;
  UnionFind U(V);
  vector<Edge> edges(E);
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = Edge(w, make_pair(u, v));
  }
  sort(edges.begin(), edges.end());

  ll res = 0;
  for (int i = 0; i < E; i++) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (U.issame(u, v)) continue;

    res += w;
    U.unite(u, v);
  }
  cout << res << endl;
}