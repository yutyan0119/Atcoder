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
  string S;
  cin >> S;
  vector<string> a(S.size());
  for (int i = 0; i < S.size(); i++)
  {
    a[i] = S.substr(i,S.size()-i)+S.substr(0,i);
  }
  sort(a.begin(),a.end());
  cout << a[0] << endl;
  cout << a[S.size()-1] << endl;
}