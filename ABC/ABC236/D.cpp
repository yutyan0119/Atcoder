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

  UnionFind(int n) { Parent = vector<int>(n, -1); }

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

int n;
vector<vector<int>> A(20, vector<int>(20));
vector<bool> used(20);
vector<pair<int, int>> vec;

int calc() {
  if (vec.size() == n) {
    int rec = 0;
    for (auto p : vec) rec ^= (A[p.first][p.second]);
    return rec;
  }

  int l;  // 1番若い番号を入れる箱
  for (int i = 1; i <= 2 * n; i++) {
    if (!used[i]) {
      l = i;
      break;
    }
  }
  used[l] = true;

  int ret = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (!used[i]) {
      vec.push_back(make_pair(l, i));  //使ってないやつをペア来んで入れる
      used[i] = true;
      ret = max(ret, calc());  //ペアがうまるまで繰り返す
      vec.pop_back();          //戻る
      used[i] = false;
    }
  }
  used[l] = false;
  return ret;  //最後まで行くと最大値が帰ってくる
}

int main() {
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; i++) {
    for (int j = i + 1; j <= 2 * n; j++) {
      cin >> A[i][j];
    }
  }
  cout << calc() << "\n";
  return 0;
}