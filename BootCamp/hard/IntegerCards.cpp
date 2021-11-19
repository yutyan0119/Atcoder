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

using pll = pair<ll, ll>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N), B(M), C(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end()); /*Aを昇順にソート*/
  for (int i = 0; i < M; i++) {
    cin >> B.at(i) >> C.at(i);
  }

  vector<int> id(M);
  iota(id.begin(), id.end(), 0);  // 0はじまりでidの要素を埋めていく
  sort(id.begin(), id.end(),
       [&](int i, int j) { return C[i] > C[j]; });  // C、つまり置き換える番号が大きい順にidを並び替え

  ll sum = 0;
  ll K = 0;
  for (auto i : id) {//idの各要素iに対して
    for (int j = 0; j < B[i]; ++j) {//Bは置き換える個数
      if (K >= N) break; //Kはカウンター,もしNになったら、個数オーバー
      sum += max(A[K++], C[i]); //Aの大きいやつから順にCのほうが大きければ置き換えることを繰り返す
    }
  }
  for (ll i = K; i < N; i++) {
    sum += A[i];
  }
  cout << sum << endl;
}