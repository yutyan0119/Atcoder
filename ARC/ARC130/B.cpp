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
  ll H;
  ll W;
  cin >> H >> W;
  ll C, Q;
  cin >> C >> Q;
  vector<ll> color(C, 0);
  map<ll, pair<ll, ll>> column;
  map<ll, pair<ll, ll>> row;
  vector<ll> rowcount(Q + 1);
  vector<ll> columncount(Q + 1);  //[0,r)に来たt==1の回数を保存します。
  rowcount[0] = 0;
  columncount[0] = 0;
  for (int i = 0; i < Q; i++) {
    int t;
    ll n;
    ll c;
    cin >> t >> n >> c;
    n--;
    c--;
    if (t == 1) {
      color.at(c) += W;
      if (column.find(n) != column.end()) {
        color.at(column[n].first) -= W;
      }
      columncount[i + 1] = columncount[i] + 1;
      column[n] = {c, i};
      rowcount[i + 1] = rowcount[i];
    } else if (t == 2) {
      color.at(c) += H;
      if (row.find(n) != row.end()) {
        color.at(row[n].first) -= H;
      }
      row[n] = {c, i};
      rowcount[i + 1] = rowcount[i] + 1;
      columncount[i + 1] = columncount[i];
    }
  }
  for (auto x : column) {
    color[x.second.first] -= rowcount[Q] - rowcount[x.second.second];
  }
  for (auto x : row) {
    color[x.second.first] -= columncount[Q] - columncount[x.second.second];
  }
  for (auto x : color) {
    cout << x << " ";
  }
  cout << endl;
}