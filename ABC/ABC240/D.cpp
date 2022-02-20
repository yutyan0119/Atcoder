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

bool isprime(int A) {
  bool ans = true;
  for (int i = 2; i * i <= A; i++) {
    if (A % i == 0) {
      ans = false;
      break;
    }
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> a;
  ll renzoku = 1;
  ll renzokunum;
  for (ll i = 0; i < N; i++) {
    int p;
    cin >> p;
    a.push_back(p);
    if (i == 0) {
      cout << a.size() << "\n";
      renzokunum = p;
    } else {
      if (p == renzokunum) {
        renzoku++;
        if (renzoku == p) {
          for (int j = 0; j < p; j++) {
            a.pop_back();
          }
          renzoku = 0;
          renzokunum = a.back();
          // cout << renzokunum << "kore" << endl;
          for (int j = a.size() - 1; j >= 0; j--) {
            if (a[j] != renzokunum) {
              break;
            } else {
              renzoku++;
            }
          }
        }
      } else {
        renzoku = 1;
        renzokunum = p;
      }
      cout << a.size() << "\n";
    }
  }
}