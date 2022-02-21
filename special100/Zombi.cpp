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
  ll to;
  ll weight;
  Edge(ll to2, ll weight2) {
    to = to2;
    weight = weight2;
  }
};

int main() {
  ll N, M, K, S;
  cin >> N >> M >> K >> S;
  ll P, Q;
  cin >> P >> Q;
  vector<ll> zombicity(N, P);
  vector<bool> cannot(N, false);
  vector<ll> danger;

  for (ll i = 0; i < K; i++) {
    ll C;
    cin >> C;
    C--;
    zombicity[C] = Q;
    danger.push_back(C);
    cannot[C] = true;
  }

  vector<vector<Edge>> G(N);
  vector<vector<Edge>> G2(N);
  vector<pair<ll, ll>> hen;

  for (ll i = 0; i < M; i++) {
    ll A, B;
    cin >> A >> B;
    A--;
    B--;
    hen.push_back(make_pair(A, B));
    G[A].push_back(Edge(B, 1));
    G[B].push_back(Edge(A, 1));
  }

  for (auto x : danger) {
    vector<bool> seen2(N);
    queue<pair<ll, ll>> que;
    que.push(make_pair(x, 0));
    while (que.front().second < S) {
      ll city = que.front().first;
      ll depth = que.front().second;
      que.pop();
      if (seen2[city]) continue;
      seen2[city] = true;
      for (auto y : G[city]) {
        zombicity[y.to] = Q;
        que.push(make_pair(y.to, depth + 1));
      }
    }
  }

  for (auto d : hen) {
    ll a = d.first;
    ll b = d.second;
    if (cannot[a] || cannot[b]) continue;
    if (a == N - 1) {
      G2[a].push_back(Edge(b, zombicity[b]));
      G2[b].push_back(Edge(a, 0));
    }
    if (b == N - 1) {
      G2[b].push_back(Edge(a, zombicity[a]));
      G2[a].push_back(Edge(b, 0));
    } else {
      G2[a].push_back(Edge(b, zombicity[b]));
      G2[b].push_back(Edge(a, zombicity[a]));
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (auto x : G2[i]) {
  //     if (i < x.to)
  //       cout << i + 1 << " to " << x.to + 1 << " = " << x.weight << endl;
  //   }
  // }

  vector<bool> seen(N, false);
  vector<ll> dist(N, 1e10);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
  dist[0] = 0;
  que.push(make_pair(dist[0], 0));
  while (!que.empty()) {
    ll p = que.top().second;
    que.pop();
    if (seen[p]) continue;
    seen.at(p) = true;
    for (auto e : G2[p]) {
      if (chmin(dist[e.to], dist[p] + e.weight)) {
        que.push(make_pair(dist[e.to], e.to));
      }
    }
  }
  cout << dist[N - 1] << endl;
}