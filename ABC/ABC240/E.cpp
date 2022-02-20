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

vector<vector<ll>> Edge;
vector<bool> seen;
vector<ll> leaf;
vector<ll> L;
vector<ll> R;
ll id = 0;

void dfs(ll par) {
  seen[par] = true;
  if (Edge[par].size() == 1 && par != 0) {
    id++;
    leaf[par] = id;
    return;
  }
  for (auto chil : Edge.at(par)) {
    if (seen.at(chil)) continue;
    dfs(chil);
  }
}

void dfs2(ll par) {
  seen[par] = true;
  if (leaf[par]) {
    L[par] = R[par] = leaf[par];
    return;
  }
  for (auto chil : Edge[par]) {
    if (seen[chil]) continue;
    dfs2(chil);
    chmin(L[par], L[chil]);
    chmax(R[par], R[chil]);
  }
}

int main() {
  ll N;
  cin >> N;
  Edge.assign(N, vector<ll>());
  seen.assign(N, false);
  leaf.assign(N, 0);
  L.assign(N, 1e9);
  R.assign(N, -1e9);
  for (ll i = 0; i < N - 1; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    Edge[a].push_back(b);
    Edge[b].push_back(a);
  }
  dfs(0);
  seen.assign(N, false);
  dfs2(0);
  for (ll i = 0; i < N; i++) {
    cout << L[i] << " " << R[i] << endl;
  }
}