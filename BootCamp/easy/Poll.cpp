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
  int N;
  cin >> N;
  map<string, int> cnt;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    cnt[s] ++;
  }
  int ma = -1;
  for (auto a:cnt)
  {
    chmax(ma,a.second);
  }
  for (auto a:cnt)
  {
    if(a.second == ma) cout << a.first << endl;
  }
  
}