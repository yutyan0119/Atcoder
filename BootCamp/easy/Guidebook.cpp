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
  vector<tuple<string, int, int>> S(N);
  for (int i = 0; i < N; i++) {
    int p;
    cin >> get<0>(S[i]);
    cin >> p;
    get<1>(S[i]) = -p;
    get<2>(S[i]) = i + 1;
  }
  sort(S.begin(), S.end());
  for (int i = 0; i < N; i++) {
    cout << abs(get<2>(S[i])) << endl;
  }
}