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
  int N, M;
  cin >> N >> M;
  priority_queue<ll, vector<ll>, less<ll>> A;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    A.push(a);
  }
  while (M > 0) {
    ll t = A.top();
    A.pop();
    A.push(t / 2);
    --M;
  }
  ll sum = 0;
  while (!A.empty()) {
    sum += A.top();
    A.pop();
  }

  cout << sum << endl;
}