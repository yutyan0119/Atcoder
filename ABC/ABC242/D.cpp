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
string S;

vector<char> A = {'A', 'B', 'C'};
vector<char> B = {'B', 'C', 'A'};
vector<char> C = {'C', 'A', 'B'};

char solve(ll t, ll k) {
  if (t == 0) {
    return S.at(k);
  } else if (k == 0) {
    if (S.at(0) == 'A') {
      return A[t % 3];
    } else if (S.at(0) == 'B') {
      return B[t % 3];
    } else if (S.at(0) == 'C') {
      return C[t % 3];
    }
  } else {
    char tmp = solve(t - 1, k / 2);
    if (k % 2) {
      if (tmp == 'A') {
        return A[2];
      } else if (tmp == 'B') {
        return B[2];
      } else if (tmp == 'C') {
        return C[2];
      }
    } else {
      if (tmp == 'A') {
        return A[1];
      } else if (tmp == 'B') {
        return B[1];
      } else if (tmp == 'C') {
        return C[1];
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> S;
  ll Q;
  cin >> Q;
  for (ll i = 0; i < Q; i++) {
    ll t;
    ll k;
    cin >> t >> k;
    k--;
    cout << solve(t, k) << "\n";
  }
}