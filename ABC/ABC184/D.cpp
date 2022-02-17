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
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<vector<ll>> A(N, vector<ll>(2, -1));

  while (Q) {
    ll n, x, y;
    cin >> n;
    if (n == 1) {
      cin >> x >> y;
      x--;
      y--;
      A[x][1] = y;
      A[y][0] = x;
    } else if (n == 2) {
      cin >> x >> y;
      x--;
      y--;
      A[x][1] = -1;
      A[y][0] = -1;
    } else if (n == 3) {
      cin >> x;
      x--;
      while (true) {
        if (A[x][0] == -1) {
          break;
        } else {
          x = A[x][0];
        }
      }
      vector<ll> ans;
      while (true) {
        if (A[x][1] == -1) {
          ans.push_back(x);
          break;
        }
        ans.push_back(x);
        x = A[x][1];
      }
      cout << ans.size() << " ";
      for (ll i = 0; i < ans.size(); i++) {
        cout << ans[i]+1;
        if (i != ans.size() - 1) {
          cout << " ";
        } else {
          cout << "\n";
        }
      }
    }
    Q--;
  }
}