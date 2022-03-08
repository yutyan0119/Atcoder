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
ll a, n;

ll rotate_ll(ll N) {
  string S = to_string(N);
  string ans = "";
  ans.push_back(S.at(S.size() - 1));
  for (int i = 1; i < S.size(); i++) {
    ans += S.at(i - 1);
  }
  return stoll(ans);
}

ll keta(ll num) {
  ll ans = 0;
  while (num) {
    num /= 10;
    ans++;
  }
  return ans;
}

map<ll, ll> m;
queue<ll> que;

int main() {
  cin >> a >> n;
  m[1] = 0;
  que.push(1);
  while (!que.empty()) {
    ll x = que.front();
    que.pop();
    if (x % 10 != 0 && x >= 10) {
      ll nextx = rotate_ll(x);
      if (m.find(nextx) == m.end()) {
        m[nextx] = m[x] + 1;
        que.push(nextx);
      }
    }
    if (keta(x * a) <= keta(n)) {
      ll nextx = x * a;
      if (m.find(nextx) == m.end()) {
        m[nextx] = m[x] + 1;
        que.push(nextx);
      }
    }
  }
  if (m.find(n) != m.end()) {
    cout << m[n] << endl;
  } else {
    cout << -1 << endl;
  }
}