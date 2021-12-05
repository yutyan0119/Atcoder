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

string toBinary(int n) {
  string r;
  while (n != 0) {
    r += (n % 2 == 0 ? "0" : "1");
    n /= 2;
  }
  return r;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> count(30, 0);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    string B = toBinary(A.at(i));
    for (int j = 0; j < B.size(); ++j) {
      if (B.at(j) == '1') {
        count[j]++;
      }
    }
  }
  int x = 0;
  for (int i = 0; i < 30; i++)
  {
    if(count[i]%2 ==1){
      x += pow(2,i);
    }
  }
  if (find(A.begin(),A.end(),x) != A.end()){
    cout << "Win" << endl;
  }
  else {
    cout << "Lose" << endl;
  }
  return 0;
}