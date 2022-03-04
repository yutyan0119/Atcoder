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

class UnionFind {
 public:
  // 親の番号を格納する。親だった場合は-(その集合のサイズ)
  vector<int> Parent;

  UnionFind(int N) { Parent = vector<int>(N, -1); }

  // Aがどのグループに属しているか調べる
  int root(int A) {
    if (Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }

  // 自分のいるグループの頂点数を調べる
  int size(int A) {
    return -Parent[root(A)];  //親をとってきたい]
  }

  // AとBをくっ付ける
  bool connect(int A, int B) {
    // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
    A = root(A);
    B = root(B);
    if (A == B) {
      //すでにくっついてるからくっ付けない
      return false;
    }

    // 大きい方(A)に小さいほう(B)をくっ付ける
    // 大小が逆だったらひっくり返す
    if (size(A) < size(B)) {
      swap(A, B);
    }

    // Aのサイズを更新する
    Parent[A] += Parent[B];
    // Bの親をAに変更する
    Parent[B] = A;

    return true;
  }
};
/* ---------------------------------------------------*/

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll Q;
  cin >> Q;
  vector<ll> all;
  ll num = 0;
  for (ll i = 0; i < Q; i++) {
    int q;
    cin >> q;
    if (q == 1) {
      ll x;
      cin >> x;
      num++;
      all.push_back(x);
    }
    if (q == 2) {
      ll x, k;
      cin >> x >> k;
      sort(all.begin(), all.end());
      ll n = lower_bound(all.begin(), all.end(), x) - all.begin();
      // cout << n << "a\n";
      if (n < k)
        cout << "-1\n";
      else
        cout << all[n - k] << "\n";
    }
    if (q == 3) {
      ll x, k;
      cin >> x >> k;
      sort(all.begin(), all.end());
      ll n = lower_bound(all.begin(), all.end(), x) - all.begin();
      // cout << n+k << " " << num <<"\n";
      if (num < n + k)
        cout << -1 << "\n";
      else
        cout << all[n + k - 1] << "\n";
    }
  }
}