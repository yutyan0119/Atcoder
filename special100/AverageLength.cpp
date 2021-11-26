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
  int N;
  cin >> N;
  int A[N];
  vector <pair<int,int>> City(N);
  for (int i = 0; i < N; i++) {
    A[i] = i;
    cin >> City[i].first >> City[i].second;
  }
  double sum = 0;
  do
  { 
    for (int i = 0; i < N-1; i++)
    {
      ll startx = City[A[i]].first;
      ll starty = City[A[i]].second;
      ll goalx = City[A[i+1]].first;
      ll goaly = City[A[i+1]].second;
      sum += sqrt((startx-goalx)*(startx-goalx)+(starty-goaly)*(starty-goaly));
    }
  } while (next_permutation(A,A+N));
  double Nkai = 1.0;
  for (int i = 1; i <= N; i++)
  {
    Nkai *= i;
  }
  printf("%.8f\n",sum/Nkai);
}