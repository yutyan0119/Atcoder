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
  vector<vector<int>> road(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    road[a].push_back(b);
    road[b].push_back(a);
  }
  vector<int> P(N, -1);
  P[0] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, P[0]));
  int maxdepth = 0;
  int maxpoint = 0;
  while (!q.empty()) {
    int s = q.front().first;
    int depth = q.front().second;
    q.pop();
    for (auto x : road[s]) {
      if (P[x] != -1) continue;
      P[x] = depth + 1;
      if (chmax(maxdepth, depth + 1)) maxpoint = x;
      q.push(make_pair(x, depth + 1));
    }
  }
  P.assign(N, -1);
  P[maxpoint] = 0;
  q.push(make_pair(maxpoint, P[maxpoint]));
  while (!q.empty()) {
    int s = q.front().first;
    int depth = q.front().second;
    q.pop();
    for (auto x : road[s]) {
      if (P[x] != -1) continue;
      P[x] = depth + 1;
      if (chmax(maxdepth, depth + 1)) maxpoint = x;
      q.push(make_pair(x, depth + 1));
    }
  }
  cout << maxdepth + 1 << endl;
}