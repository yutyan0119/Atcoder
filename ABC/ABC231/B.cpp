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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  vector <string> S(N);
  map <string,int> map; 
  for (int i = 0; i < N; i++)
  {
    cin >> S.at(i);
    if (map.find(S.at(i)) == map.end()){
      map[S[i]] = 1;
    }
    else{
      map[S[i]]++;
    }
  }
  int maxcount = 0;
  string ans;
  for (auto iter = map.begin(); iter != map.end() ; iter++){
    if (chmax(maxcount, iter->second)){
      ans = iter->first;
    }
  }
  cout << ans << endl;
}