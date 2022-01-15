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
  string abc;
  cin >> abc;
  string bca = "";
  bca += abc.at(1);
  bca += abc.at(2);
  bca += abc.at(0);
  string cab = "";
  cab += abc.at(2);
  cab += abc.at(0);
  cab += abc.at(1);
  cout << stoi(abc) + stoi(bca) + stoi(cab) << endl;
}