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
  int H, W;
  ll K, V;
  cin >> H >> W >> K >> V;
  vector<vector<ll>> A(H + 1, vector<ll>(W + 1, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ll aij;
      cin >> aij;
      A[i + 1][j + 1] = aij + A[i + 1][j] + A[i][j + 1] - A[i][j];
    }
  }
  int area = 0;

  for (int i = 1; i <= H; i++)  //長方形の縦のサイズ
  {
    for (int j = 1; j <= W; j++)  //横のサイズ
    {
      for (int k = 0; k <= H - i; k++)  //左上の行
      {
        for (int l = 0; l <= W - j; l++)  //左上の列
        {
          ll tochidai = A[k + i][l + j] - A[k + i][l] - A[k][l + j] + A[k][l];
          ll kensetuhi = K * i * j;
          if (tochidai + kensetuhi <= V) {
            chmax(area, i * j);
          }
        }
      }
    }
  }
  cout << area << "\n";
}