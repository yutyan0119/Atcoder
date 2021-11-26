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
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  vector<ll> b(N);
  vector<ll> maxfront(N);  // 0~iまでの列で最大の値を保存
  ll ans = 1e12;

  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    if (i == 0) {
      maxfront.at(i) = a.at(0);
    } else {
      maxfront.at(i) =
          max(maxfront.at(i - 1), a.at(i));  // 0~iまでの列で最大の値を保存
    }
  }

  for (int i = 0; i < (1 << N); i++) {
    ll sum = 0;        //毎回の合計
    vector<int> list;  //選択するビルの番号を入れる。
    vector<ll> maxfrontC(N);
    for (int j = 0; j < N; j++) {
      b.at(j) = a.at(j);
    }  //いじるやつはbにします。
    for (int j = 0; j < N; j++) {
      maxfrontC[j] = maxfront[j];
    }

    for (int j = 0; j < N; j++) {
      if (i & 1 << j) {
        list.push_back(j);
      }
    }
    if ((int)list.size() < K) {
      continue;  // K以下のときは次の操作を行わない
    }

    for (int j = 0; j < (int)list.size(); j++) {
      int x = list.at(j);
      int index = max(x - 1, 0);
      if (b.at(x) <= maxfrontC.at(index) && x != 0) {
        sum += maxfrontC.at(index) - b.at(x) + 1;
        b.at(x) = maxfrontC.at(index) + 1;
        for (int k = x; k < N; k++) {
          maxfrontC.at(k) = max(b.at(x), maxfrontC.at(k));
        }
      }
    }
    chmin(ans, sum);
  }
  cout << ans << endl;
}