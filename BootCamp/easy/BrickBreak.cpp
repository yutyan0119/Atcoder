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
  int N;
  cin >> N;
  vector <pair<int,int>> a(N);
  for (int i = 0; i < N; i++)
  {
      cin >> a[i].first;
      a[i].second = a[i].first - (i+1);
  }
  bool can = false;
  for (int i = 0; i < N; i++)
  {
    if (a[i].second >= 0){
      can = true;
    }
  }
  cout << can << endl;
  int ans = 1000000;
  if (can){
    for (int i = 0; i < N; i++)
    {
      if(a[i].second >= 0){
        chmin(ans,a[i].second);
      }
    }
    cout << ans << endl;
  }
  else {
    cout << -1 << endl;
  }
}