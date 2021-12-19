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
  cout << (S.at(0)-'0')*(S.at(2)-'0') << endl;
  vector <int> A = {0,1,2};
  vector <int> B = {0,1,2};
  cout << (A==B) << endl;
}