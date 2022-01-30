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
  bool can = true;
  ll bacount = 0;
  ll facount = 0;
  for (int i = 0; i < N / 2; i++) {
    if (S.at(i) != S.at(N - 1 - i)) {
      can = false;
      break;
    }
  }
  if (can) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < N / 2; i++) {
    if (S.at(N - 1 - i) == 'a') {
      bacount++;
    } else {
      break;
    }
  }
  for (int i = 0; i < N / 2; i++) {
    if (S.at(i) == 'a') {
      facount++;
    } else {
      break;
    }
  }
  if (bacount == 0 || facount >= bacount) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < bacount - facount; i++) {
    S.insert(S.begin(), 'a');
  }
  N = (int)S.size();
  can = true;
  for (int i = 0; i < N / 2; i++) {
    if (S.at(i) != S.at(N - 1 - i)) {
      can = false;
      break;
    }
  }
  cout << ((can) ? "Yes" : "No") << endl;
}