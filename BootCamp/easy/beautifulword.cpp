#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for(int i = s; i <e ; i++)

/* ---------------------------------------------------*/

int main() {
  int a[26] = {0};
  string w ;
  cin >> w;
  for (int i = 0; i < (int)w.size(); i++)
  {
    a[w.at(i)-'a']++;
  }
  for (int j = 0; j < 26; j++)
  {
    if (a[j]%2 == 1){
      cout << "No" << endl; 
      return 0;
    }
  }
  cout << "Yes" << endl;
  
}