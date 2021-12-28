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

using Graph = vector<vector<int>>;
/* ---------------------------------------------------*/

int N, W;
vector<int> a;
void calcsum(int sum, int k, int &count) {  // 0,1,...kまでの和
  if (k == -1) {
    if (sum == W) count++;
    return;
  }
  calcsum(sum + a[k], k - 1,count);
  calcsum(sum, k - 1,count);
}

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    a.push_back(p);
  }
  int count = 0;
  calcsum(0, N - 1,count);
  cout << count << endl;
}