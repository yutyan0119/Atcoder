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
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> pointsum1(N + 1);
  vector<int> pointsum2(N + 1);
  pointsum1.push_back(0);
  pointsum2.push_back(0);
  int index1 = 1;
  int index2 = 1;
  for (int i = 0; i < N; i++) {
    int C, P;
    cin >> C >> P;
    if (C == 1) {
      for (int j = index1; j < i + 1; j++) {
        pointsum1[j] = pointsum1[j - 1];
      }
      pointsum1[i + 1] = pointsum1[i] + P;
      index1 = i + 2;
    } else {
      for (int j = index2; j < i + 1; j++) {
        pointsum2[j] = pointsum2[j - 1];
      }
      pointsum2[i + 1] = pointsum2[i] + P;
      index2 = i + 2;
    }
  }
  for (int i = index1; i <= N; i++) {
    pointsum1[i] = pointsum1[i - 1];
  }
  for (int i = index2; i <= N; i++) {
    pointsum2[i] = pointsum2[i - 1];
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << pointsum1[r + 1] - pointsum1[l] << " "
         << pointsum2[r + 1] - pointsum2[l] << "\n";
  }
}