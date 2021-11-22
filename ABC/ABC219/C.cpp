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
  int N,K;
  cin >> N >> K;
  vector <pair<int,int>> data(N);
  for (int i = 0; i < N; i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    data[i].first = a+b+c;
    data[i].second = i;
  }
  bool can[N]={0};
  sort(data.begin(),data.end(),greater<pair<int,int>>());

    for (int i = 0; i < K; i++)
  {
    can[data[i].second] = 1;
  }
  int basis = data[K-1].first;
  for (int i = K; i < N; i++)
  {
    if (data[i].first + 300 >= basis){
      can[data[i].second] = 1;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if(can[i]){
      cout << "Yes" << endl;
    }else {
      cout << "No" << endl;
    }
  }
  
}