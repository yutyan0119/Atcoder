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
  ll N, A, B, C;
  vector<ll> a(3);
  cin >> N >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  A = a[2];
  B = a[1];
  C = a[0];
  ll ans = 10000;
  for (int i = N / A; i >= 0; --i) {
    ll nokori = N - A * i;
    for (int j = nokori / B; j >= 0; --j) {
      ll nokori2 = nokori;
      nokori2 = nokori - B * j;
      if (nokori2 % C == 0) {
        chmin(ans, (i + j + nokori2 / C));
      }
    }
  }
  cout << ans << endl;
}