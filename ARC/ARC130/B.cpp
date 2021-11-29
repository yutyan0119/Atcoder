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

//方針。後ろのクエリが優先される場合は後ろから実行していき、上書きできない場所をsetで管理しておく
int main() {
  ll H;
  ll W;
  cin >> H >> W;
  ll C, Q;
  cin >> C >> Q;
  vector<ll> t(Q), c(Q), n(Q);
  for (int i = 0; i < Q; i++) {
    cin >> t[i] >> n[i] >> c[i];
    --n[i];
    --c[i];
  }
  vector<ll> ans(C);
  set<ll> rowused, columnused;
  for (ll i = Q - 1; i >= 0; --i) {
    if (t[i] == 1) {
      if (columnused.find(n[i]) != columnused.end()) {
        continue;
      } else {
        columnused.insert(n[i]);
        ans[c[i]] += W - rowused.size();
      }
    }
    if (t[i] == 2) {
      if (rowused.find(n[i]) != rowused.end()) {
        continue;
      } else {
        rowused.insert(n[i]);
        ans[c[i]] += H - columnused.size();
      }
    }
  }
  for (int i = 0; i < C; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}