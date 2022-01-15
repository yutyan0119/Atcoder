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
ll rotate_ll(ll N) {
  string S = to_string(N);
  string ans = "";
  for (int i = 1; i < S.size(); i++) {
    ans += S.at(i);
  }
  ans += S.at(0);
  return stoll(ans);
}

int solve(ll a, ll N, bool rotate) {
  cout << N << "rotate can = " << rotate << endl;
  if (N == 1) {
    return 0;
  }
  if (N > 10 && rotate) {
    if (N % a == 0) {
      if (rotate_ll(N) % 10 != 0) {
        int a1 = solve(a, N / a, 1);
        int a2 = solve(a, rotate_ll(N), 0);
        if (a1 == -1 && a2 == -1) {
          return -1;
        } else if (a1 != -1 && a2 != -1) {
          return min(a1, a2) + 1;
        } else {
          return (a1 == -1) ? a2 + 1 : a1 + 1;
        }
      } else {
        if (solve(a, N / a, 1) == -1) {
          return -1;
        } else {
          return solve(a, N / a, 1) + 1;
        }
      }
    }
    if (N % a != 0) {
      if (rotate_ll(N) % 10 != 0) {
        if (solve(a, rotate_ll(N), 0) == -1) {
          return -1;
        } else {
          return solve(a, rotate_ll(N), 0) + 1;
        }
      } else {
        return -1;
      }
    }
  }
  if (N > 10 && N % 10 != 0 && !rotate) {
    if (N % a != 0) {
      return -1;
    }
    if (N % a == 0) {
      if (solve(a, N / a, 1) == -1) {
        return -1;
      } else {
        return solve(a, N / a, 1) + 1;
      }
    }
  }
  if ((N > 10 && N % 10 == 0) || (N <= 10)) {
    if (N % a != 0) {
      return -1;
    }
    if (N % a == 0) {
      if (solve(a, N / a, 1) == -1) {
        return -1;
      } else {
        return solve(a, N / a, 1) + 1;
      }
    }
  }
}

int main() {
  ll a, N;
  cin >> a >> N;
  cout << solve(a, N, 1) << endl;
}