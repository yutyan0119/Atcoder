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
  cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll rotate = 0;
  for (ll i = 0; i < Q; i++) {
    int T;
    cin >> T;
    if (T == 1) {
      int x, y;
      cin >> x >> y;
      swap(A.at((x - 1 - rotate + 2 * N) % N),
           A.at((y - 1 - rotate + 2 * N) % N));
    }
    if (T == 2) {
      int x, y;
      cin >> x >> y;
      rotate++;
    }
    if (T == 3) {
      int x, y;
      cin >> x >> y;
      cout << A.at((x - 1 - rotate + 2 * N) % N) << "\n";
    }
  }
}