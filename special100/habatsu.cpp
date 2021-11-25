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
  int N;
  cin >> N;
  int M;
  cin >> M;
  vector<set<int>> R(N + 1);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;  // xとyが仲良し
    R[x].insert(y);
    R[y].insert(x);
  }
  int ans = 0;
  for (int i = 0; i < 1 << (N + 1); i++)  // bitセット
  {
    vector<int> member(0);
    for (int j = 1; j <= N; j++)  //人jが選ばれてるよ。
    {
      if (i & 1 << j) {
        member.push_back(j);
      }
    }
    bool can = true;
    for (int j = 0; j < (int)member.size(); ++j) {
      for (int k = j + 1; k < (int)member.size(); ++k) {
        int x1 = member[j];
        int x2 = member[k];
        if (R[x1].find(x2) == R[x1].end()) {
          can = false;
          break;
        }
      }
    }
    if (can) {
      int habatsu = (int)member.size();
      chmax(ans, habatsu);
    }
  }
  cout << ans << endl;
}