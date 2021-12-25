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

int N;
ll x;
int ans = 0;

vector<vector<int>> a;
void dfs(vector<int>& A, vector<int> L) {
  if (A.size() == N) {
    ll sum = 1;
    for (int i = 0; i < N; i++) {
      sum *= a[i][A[i]];
      if (sum > x)break;
    }
    if (sum == x) ans++;
    return;
  }
  for (int v = 0; v < L[A.size()]; v++) {
    A.push_back(v);
    dfs(A,L);
    A.pop_back();
  }
}

int main() {
  cin >> N;
  cin >> x;
  vector<int> L(N);
  a.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
    for (int j = 0; j < L[i]; j++) {
      int A;
      cin >> A;
      a[i].push_back(A);
    }
  }
  vector <int> P;
  dfs(P,L);
  cout << ans << endl;
}