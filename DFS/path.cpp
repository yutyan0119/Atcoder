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

using Graph = vector<vector<int>>;
/* ---------------------------------------------------*/

vector<bool> seen;

void dfs(const Graph& G, int v) {
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v]) {
      continue;
    }
    dfs(G, next_v);
  }
}

int main() {
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  seen.assign(N,false);
  dfs(G,s);
  if(seen[t]) cout << "Yes" << endl;
  else cout << "No" << endl;
}