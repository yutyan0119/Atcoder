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
  int n;
  cin >> n;
  if (n % 2) {
    return 0;
  }
  vector<int> a(n, 1);
  for (int i = 0; i < n / 2; i++) {
    a[i] = 0;
  }
  do {
    int left = 0;
    int right = 0;
    bool can = true;
    for (int i = 0; i < n; i++) {
      if (a[i])
        right++;
      else
        left++;
      if (right > left) {
        can = false;
      }
    }
    if (can) {
      for (int i = 0; i < n; i++) {
        if (a[i])
          cout << ')';
        else
          cout << '(';
      }
      cout << "\n";
    }
  } while (next_permutation(a.begin(), a.end()));
}