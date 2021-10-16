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
  int select[N + 1];  // gold は1 , silver は0
  select[N] = 1;
  ans[N] = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < N + 1; i++) {
    gold[i] = max(gold[i - 1], silver[i - 1] / A[i - 1]);
    silver[i] = max(silver[0], A[i - 1] * gold[i - 1]);
  }
  for (int i = 0; i < N; i++) {
    if (ans[N - i] == 0 ) {
      if (gold[N - i] == gold[N - i - 1] && select[N - i] == 1) {
        ans[N - 1 - i] = 0;
        select[N - 1 - i] = 1;
        cout << "金から金" << endl;
      } else if (select[N - i] == 1) {
        ans[N - 1 - i] = 1;
        select[N - 1 - i] = 0;
        cout << "銀から金" << endl;
      }
    } else {
      if (silver[N - i] == silver[N - i - 1] && select[N - i] == 0) {
        ans[N - 1 - i] = 0;
        select[N - 1 - i] = 0;
        cout << "銀から銀" << endl;
      } else if (select[N] == 0) {
        ans[N - 1 - i] = 1;
        select[N - 1 - i] = 1;
        cout << "金から銀" << endl;
      }
    }
  }
  for (int i = 0; i < N - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[N - 1] << endl;
  for (int i =0 ;i< N -1 ; i++){
    cout << select[i] << " ";
  }
  cout << select[N-1] << endl;
}