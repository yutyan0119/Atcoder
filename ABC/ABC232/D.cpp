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
  int N;
  int M;
  cin >> N >> M;
  vector<vector<int>> Takahashi(N, vector<int>(0));

  vector<vector<int>> Aokibase(N, vector<int>(0));
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    Takahashi.at(A).push_back(B);
    Takahashi.at(B).push_back(A);
  }
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    Aokibase.at(A).push_back(B);
    Aokibase.at(B).push_back(A);
  }
  for (int i = 0; i < N; i++) {
    sort(Takahashi.at(i).begin(), Takahashi.at(i).end());  //中身ソートしておく
  }
  vector<int> base(N);
  for (int i = 0; i < N; i++) {
    base[i] = i;
  }
  do {
    for (int i = 0; i < N; i++) {
      cerr << base[i];
    }
    cerr << endl;
    vector<vector<int>> Aoki(N, vector<int>(0));
    for (int j = 0; j < N; j++) {
      Aoki.at(base[j]) = Aokibase.at(j);  //まず、インデックスを入れ替えて挿入
    }
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < Aoki.at(j).size(); k++) {
        Aoki.at(j).at(k) = base[Aoki.at(j).at(k)];  //それぞれの中身を変換
      }
      sort(Aoki.at(j).begin(), Aoki.at(j).end());  //中身をソートする
    }
    if (Aoki == Takahashi) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(base.begin(), base.end()));
  cout << "No" << endl;
}