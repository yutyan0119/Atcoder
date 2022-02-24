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

using Edge = pair<int, pair<int, int>>;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<Edge> E(M);
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    E[i] = Edge(C, make_pair(A, B));
  }

  sort(E.begin(), E.end());

  ll size = N;
  ll res = 0;
  UnionFind U(N);
  for (int i = 0; i < M; i++) {
    if (size == K) break;
    int w = E[i].first;
    int f = E[i].second.first;
    int t = E[i].second.second;
    if (U.issame(f, t)) continue;
    U.unite(f, t);
    res += w;
    size--;
  }
  cout << res << endl;
}