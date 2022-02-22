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

ll INF = 1e10;

struct Edge {
  int to;
  int weight;
  Edge(int to2, int weight2) {
    to = to2;
    weight = weight2;
  }
};

int main() {
  ll N, K;
  cin >> N >> K;
  vector<vector<Edge>> G(N);
  vector<vector<ll>> Graph(N);
  vector<ll> C(N);  // cost
  vector<ll> R(N);  // range
  vector<ll> dist(N, INF);
  for (ll i = 0; i < N; i++) {
    cin >> C[i] >> R[i];
  }
  for (ll i = 0; i < K; i++) {
    int A;
    int B;
    cin >> A >> B;
    A--;
    B--;
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }

  for (ll i = 0; i < N; i++) {
    queue<pair<ll, ll>> que;
    que.push(make_pair(i, 0));
    vector<bool> seen(N, false);
    while (que.front().second < R[i] && !que.empty()) {
      ll city = que.front().first;
      ll path = que.front().second;
      que.pop();
      if (seen[city]) continue;
      seen[city] = true;
      for (auto p : Graph[city]) {
        if (seen[p]) continue;
        // cout << i << " TO " << p << " " << path + 1 << " " << C[i]
        //      << endl;
        que.push(make_pair(p, path + 1));
        G[i].push_back(Edge(p, C[i]));
      }
    }
  }
  dist[0] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
  que.push(make_pair(dist[0], 0));
  vector<bool> seen(N, false);
  while (!que.empty()) {
    ll min_v = que.top().second;
    que.pop();
    if (seen[min_v]) continue;
    seen[min_v] = true;
    for (auto e : G[min_v]) {
      // cout << min_v << " to " << e.to << endl;
      if (chmin(dist[e.to], dist[min_v] + e.weight)) {
        que.push(make_pair(dist[e.to], e.to));
      }
    }
  }
  cout << dist[N - 1] << endl;
}