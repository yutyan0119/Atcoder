#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
};

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
};

typedef long long ll;

struct Edge {
  int to;
  ll weight;
  Edge(int to2, ll weight2) {
    to = to2;
    weight = weight2;
  };
};

/* ---------------------------------------------------*/
int main() {
  ll INF = 1LL << 60;
  int N, M;
  cin >> N >> M;
  vector<vector<Edge>> G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    G.at(a).push_back(Edge(b, -c));
  }
  bool negative = false;
  vector<ll> score(N, INF);
  score[0] = 0;
  for (int i = 0; i <= N * 2; i++) {
    for (int j = 0; j < N; j++) {
      if (score[j] == INF) continue;
      for (auto e : G.at(j)) {
        if (chmin(score[e.to], score[j] + e.weight)) {
          if (e.to == N - 1 && i == 2 * N) negative = true;//N-1が最低値決定後、N回後も変化してたらOUT
        }
      }
    }
  }
  if (negative)
    cout << "inf" << endl;
  else {
    cout << -1 * score[N - 1] << endl;
  }
}