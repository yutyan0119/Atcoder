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

/* ---------------------------------------------------*/

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> L(M);
  vector<int> R(M);
  vector<vector<int>> rui(N + 2, vector<int>(N + 2, 0));
  // rui[x][y] は区間[x,y)に含まれる電車の数
  for (int i = 0; i < M; i++) {
    cin >> L[i] >> R[i];
    for (int j = 0; j <= L[i]; j++) {
      for (int k = R[i] + 1; k < N + 2; k++) {
        rui[j][k]++;
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    int p, q;
    cin >> p >> q;
    printf("%d\n", rui[p][q + 1]);
  }
}