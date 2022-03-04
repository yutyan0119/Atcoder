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

int main() {
  ll N, K;
  cin >> N >> K;
  ll ame = 0;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<ll> tame;
  if (N > K) {
    for (ll i = 0; i < K; i++) {
      ame += A[ame % N];
    }
  } else {
    for (ll i = 0; i < K; i++) {
      ll amari = ame % N;
      tame.push_back(amari);
      if (i <= 20) {
        // cout << amari << "\n";
      }
      if (i > N && tame[N] == amari) {
        // cout << ame % N << endl;
        // cout << i << endl;
        ll roop = i - N;
        ll nokori = K - i;
        ll roopamari = (K - i) % roop;
        // cout << nokori /roop << endl;
        // cout << roop*(nokori/roop) + i << endl;
        // cout << roopamari << endl;
        ll roopame = ame;
        for (int j = 0; j < roop; j++) {
          roopame += A[roopame % N];
        }
        roopame -= ame;
        // cout << roopame << endl; //ok 8,5,6,3
        ame = ame + (roopame * (nokori / roop));
        // cout << ame << endl;
        // cout << 826617499998784056 - ame << endl;
        for (ll j = 0; j < roopamari; j++) {
          // cout << ame % N << endl;
          ame += A[ame % N];
        }
        break;
      }
      ame += A[amari];
    }
  }
  cout << ame << "\n";
}
// 10 1000000000000
// 260522 914575 436426 979445 648772 690081 933447 190629 703497 47202
