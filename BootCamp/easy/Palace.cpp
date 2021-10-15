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

/* ---------------------------------------------------*/

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  int H[N];
  pair <double,int> ans = {10000,0};
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  for (int i = 0; i < N; i++)
  {
    double Tav = T - H[i] *0.006;
    if (abs(Tav-A) < ans.first){
      ans.first=abs(Tav-A);
      ans.second = i+1;
    }
  }
  cout << ans.second << endl;
}