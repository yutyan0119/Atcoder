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
  int N, M;
  cin >> N >> M;
  vector<ll> P(M);
  vector<ll> city(N + 1, 0);
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  for (int i = 0; i < M; i++) {
    cin >> P[i];
  }
  for (int i = 0; i < M - 1; i++) {
    if (P[i] < P[i + 1]) {
      city[P[i] - 1]++;
      city[P[i + 1] - 1]--;
    } else {
      city[P[i + 1] - 1]++;
      city[P[i] - 1]--;
    }
  }
  for (int i = 1; i < N; i++) {
    city[i] += city[i - 1];
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> A[i] >> B[i] >> C[i];
  }
  ll value = 0;
  for (int i = 0; i < N - 1; i++) {
    ll normalval = A[i] * city[i];
    ll icval = C[i] + B[i] * city[i];
    value += min(icval, normalval);
  }
  cout << value << endl;
}