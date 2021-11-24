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
  int N, M;
  cin >> N >> M;
  vector<int> k(M);
  vector<vector<int>> s(M);
  int p[M];
  for (int i = 0; i < M; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      int x;
      cin >> x;
      s[i].push_back(x);
    }
  }
  int ans = 0;
  bool on[N + 1] = {false};
  for (int i = 0; i < M; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < (1 << N); i++) {  // Switchの状態を定める
    bool all_turn_on = true;            //全部つくかのパラメータ
    for (int j = 0; j < N; j++) {
      if (i & 1 << j) {  // Switch_jがON
        on[j + 1] = true;
      } else {
        on[j + 1] = false;  //それ以外はOFF
      }
    }
    for (int j = 0; j < M; j++)  //電球を選ぶ
    {
      int count = 0;  // Switch何個ONか
      for (int l = 0; l < k[j]; l++) {
        if (on[s[j][l]]) { //s[j][l]に電球番号が入ってる。
          count++; //on担ってたらカウント増やす
        }
      }
      if (count % 2 != p[j]) { //電球のつく要件を満たすか。
        all_turn_on = false;
        break; //満たさなかったら諦める。
      }
    }
    if (all_turn_on) { //ここまで到達してついてたら
      ans++; //答えを増やす
    }
  }
  cout << ans << endl;
}