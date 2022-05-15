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
  int N;
  cin >> N;
  vector<ll> A(46, 0), B(46, 0), C(46, 0);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    a %= 46;
    A[a]++;
  }
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    a %= 46;
    B[a]++;
  }
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    a %= 46;
    C[a]++;
  }
  ll count = 0;
  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        if ((i + j + k) % 46) {
          continue;
        } else {
          count += A[i] * B[j] * C[k];
        }
      }
    }
  }
  cout << count << endl;
}