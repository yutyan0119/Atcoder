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

/* ---------------------------------------------------*/

int main() {
  int N;
  int Q;
  cin >> N >> Q;
  vector<tuple<int, int, int>> query(Q);
  for (int i = 0; i < Q; i++) {
    cin >> get<0>(query[i]);
    if (get<0>(query[i]) == 1 || get<0>(query[i]) == 2) {
      cin >> get<1>(query[i]) >> get<2>(query[i]);
    } else {
      cin >> get<1>(query[i]);
    }
  }
  vector<tuple<queue<int>, int, int>> train(N);

  for (int i = 0; i < N; i++) {
    get<0>(train[i]).push(i + 1);
    get<1>(train[i]) = get<2>(train[i]) = i + 1;
  }

  for (int i = 0; i < Q; i++) {
    if (get<0>(query[i]) == 1) {
      int x = get<1>(query[i]);
      int y = get<2>(query[i]);
      for (int i = 0; i < N; i++) {
        if (get<1>(train[i]) == x) {
          x = i;
        }
        if (get<2>(train[i]) == y) {
          y = i;
        }
      }

      int size = get<0>(train[y]).size();
      for (int i = 0; i < size; i++) {
        get<0>(train[x]).push(get<0>(train[y]).front());
        get<2>(train[x]) = get<0>(train[y]).front();
        get<0>(train[y]).pop();
      }
      get<1>(train[y]) = get<2>(train[y]) = 0;
    }
    if (get<0>(query[i]) == 2) {
      int x = get<1>(query[i]);
      int y = get<2>(query[i]);
      for (int i = 0; i < N; i++)
      {
        if (get<1>(train[i])!=0){
          int size = get<0>(train[i]).size();
          
        }
      }
      

    }
    if (get<0>(query[i]) == 3) {
      int x = get<1>(query[i]);
      int y = get<2>(query[i]);
    }
  }
}