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
const long long INF = 1LL << 60;
/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  vector<double> gold(N + 1, 0);
  vector<double> silver(N + 1, 0);
  gold[0] = 1;
  silver[0] = 0;
  int A[N];
  int ans[N + 1];
  int select = 1;  // gold は1 , silver は0
  ans[N] = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < N + 1; i++) {
    gold[i] = max(gold[i - 1], silver[i - 1] / A[i - 1]);
    silver[i] = max(silver[i-1], A[i - 1] * gold[i - 1]);
  }
  for (int i = 0; i < N; i++) {
    if (select == 1) {
      if (gold[N - i] == gold[N - i - 1]) {
        ans[N - i - 1] = 0;
        select = 1;
        cout << i << endl;
      } else {
        ans[N - i - 1] = 1;
        select = 0;
        cout << i << endl;
      }
    }
    else if (select == 0) {
      if (silver[N - i] == silver[N - i - 1]) {
        ans[N - i - 1] = 0;
        select = 0;
        cout << i << endl;
      } else {
        ans[N - i - 1] = 1;
        select = 1;
        cout << i << endl;
      }
    }
  }
  for (int i = 0; i < N-1; i++)
  {
    cout << ans[i] << " ";
  }
  cout << ans[N-1] << endl;
  cout << gold[N] << endl;
}