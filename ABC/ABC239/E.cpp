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

ll N, Q;
vector<vector<ll>> numdata;
vector<bool> seen;
vector<vector<ll>> Hen;
vector<ll> X;
vector<vector<ll>> Children;

void dfs(ll root) {
  seen[root] = true;
  for (auto x : Hen.at(root)) {
    if (seen.at(x))
      continue;
    else {
      seen[x] = true;
      // Children.at(root).push_back(x);
      numdata.at(root).push_back(X[x]);
      dfs(x);
      numdata[root].insert(numdata[root].end(),numdata[x].begin(),numdata[x].end());
    }
  }
}  //子供を求めるO(2N-1)

void dfs2(ll root) {
  seen[root] = true;
  for (auto x : Hen[root]) {
    if(seen[x]) continue;
    dfs2(x);
    // cout <<"tougou" << root << " " << x << endl;
    numdata[root].insert(numdata[root].end(),numdata[x].begin(),numdata[x].end());
  }
}//O(2N-1)

int main() {
  cin >> N >> Q;
  numdata.assign(N, vector<ll>());  //頂点iから到達可能な点数のベクトル
  seen.assign(N, false);            // dfsに用いる
  Hen.assign(N, vector<ll>());  //頂点iから繋がっている場所のベクトル
  X.assign(N, 0);               //頂点iの点数のベクトル
  Children.assign(N, vector<ll>());  //頂点iから到達可能な子のベクトル
  for (ll i = 0; i < N; i++) {
    cin >> X[i];
  }
  for (ll i = 0; i < N - 1; i++) {
    ll A, B;
    cin >> A >> B;
    A--;
    B--;
    Hen.at(A).push_back(B);
    Hen.at(B).push_back(A);
  }
  dfs(0); //0からdfsして子を求める
  seen.assign(N,false);
  for (ll i = 0; i < N; i++) {
    numdata.at(i).push_back(X[i]);
    sort(numdata.at(i).rbegin(), numdata.at(i).rend());
  }
  // for (ll i = 0 ; i < N ; i++){
  //     cout << i << "の点数データ";
  //   for (auto x : numdata[i]){
  //     cout << x  << " ";
  //   }
  //   cout << "\n";
  // }
  for (ll i = 0; i < Q; i++) {
    ll V, K;
    cin >> V >> K;
    V--;
    K--;
    cout << numdata.at(V).at(K) << "\n";
  }
}