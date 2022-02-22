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

struct Edge {
  int to;
  ll weight;
  Edge(int to2, ll weight2) {
    to = to2;
    weight = weight2;
  }
};

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<Edge>> G(V);
  vector<vector<ll>> dp(V, vector<ll>(V, 1e15));
  for (int i = 0; i < V; i++) {
    dp[i][i] = 0;
  }
  for (int i = 0; i < E; i++) {
    int s, t;
    ll d;
    cin >> s >> t >> d;
    G[s].push_back(Edge(t, d));
    dp[s][t] = d;
  }
  cout << dp[1][0] << endl;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      for (int k = 0; k < V; k++) {
        chmin(dp[j][k], dp[j][i] + dp[i][k]);
      }
    }
  }
  for (int i = 0; i < V; i++) {
    if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (j) cout << " ";
      if (dp[i][j] > 1e15/2)
        cout << "INF";
      else
        cout << dp[i][j];
    }
    cout << "\n";
  }
}