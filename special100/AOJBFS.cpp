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
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  for (int i = 0; i < n; i++) {
    int a;
    int b;
    cin >> a >> b;
    a--;
    for (int j = 0; j < b; j++) {
      int k;
      cin >> k;
      k--;
      G[a].push_back(k);
    }
  }
  
  queue<int> que;
  vector<int> number(n, -1);
  que.push(0);
  number[0] = 0;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int x : G[v]) {
      if(number[x] != -1)continue;
      que.push(x);
      number[x] = number[v] + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << number[i] << endl;
  }
}