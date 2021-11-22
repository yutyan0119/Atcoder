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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

/* ---------------------------------------------------*/

int main() {
  string X;
  cin >> X;
  int N;
  cin >> N;
  string S[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  map<char, int> mapping;
  for (int i = 0; i < 26; i++) {
    mapping[X[i]] = i;
  }
  sort(S, S+N, [&](string a, string b) {
    int len = min((int)a.length(), (int)b.length());
    for (int i = 0; i < len; i++) {
      int x = mapping[a[i]];
      int y = mapping[b[i]];
      if (x != y) return x < y;
    }
    return a.length() < b.length();
  });
  for (int i = 0; i < N; i++) {
    cout << S[i] << endl;
  }
}