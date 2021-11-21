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

#define N 200100
ll t[N];
ll k[N];
vector<int> e[N];  //!=e(N),配列をN個用意してます。
bool used[N] = {false};
int main() {
  int n, x;
  ll ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> k[i];
    for (int j = 0; j < k[i]; j++) {
      cin >> x;               // A_ijを受け取り
      e[i].push_back(x - 1);  // e[i]にインデックスをあわせて入れる
    }
  }
  used[n - 1] = true;  //まずn-1は到達可能
  for (int i = n - 1; i >= 0; i--) { //順番に後ろから到達可能なところをたどっていく
    if (used[i]) {
      ans += t[i];
      for (int j = 0; j < k[i]; j++) {
        used[e[i][j]] = true; //絶対ちっさい番号なのでモーマンタイ
      }
    }
  }
  cout << ans << endl;
  return 0;
}