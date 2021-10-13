#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for(int i = s; i <e ; i++)

/* ---------------------------------------------------*/

int main() {
  int N,M;
  cin >> N >> M;
  vector <int> cnt(M,0);
  rep(i, 0, N) {
    int k; 
    cin >> k;
    rep(j, 0, k) {
      int a; 
      cin >> a;
      a--;
      cnt[a]++;
      }
  }
 
  int ans = 0;
  rep(i, 0, M) {
    if (cnt[i] == N) ans++;
  }
  cout << ans << endl;
}