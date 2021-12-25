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

vector<bool> seen;

void dfs(vector<vector<int>>& G, int v, vector<int>& count, int pa = -1) {
  for (auto x : G[v]) {
    if (pa == x) continue;
    count[x] += count[v];
    dfs(G, x, count, v);
  }
}

int main() {
  int N;
  int Q;
  cin >> N >> Q;
  vector<vector<int>> G(N);
  vector<int> count(N, 0);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 0; i < Q; i++) {
    int p;
    int x;
    cin >> p >> x;
    p--;
    count[p] += x;
  }
  dfs(G, 0, count);
  for (int i = 0; i < N; i++) {
    cout << count[i] << " ";
  }
  cout << endl;
}