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
  int N, K;
  cin >> N >> K;
  priority_queue<ll> A;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    A.push(tmp);
  }
  bool can = true;
  int count = 0;
  while (can) {
    ll a[K];
    for (int i = 0; i < K; i++) {
      a[i] = A.top();
      A.pop();
      if (a[i] == 0) {
        can = false;
        break;
      }
      a[i]--;
    }
    if (!can) {
      break;
    } else {
      for (int i = 0; i < K; i++) {
        A.push(a[i]);
      }
      count++;
    }
  }
  cout << count << endl;
}