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
  string S;
  cin >> S;
  int N = (int)S.size();
  ll ans = 0;
  for (int i = 0; i < 1 << (N - 1); i++)  // bit決定
  {
    int keta = 0;
    for (int j = 0; j < N - 1; j++) {
      if (i & 1 << j) {  // j番目にbitが立ってるのでj番目まで+j+1番目以降
        ans += stol(S.substr(keta, j - keta + 1));
        keta = j + 1;
      }
    }
    ans += stol(S.substr(keta));
  }
  cout << ans << endl;
}