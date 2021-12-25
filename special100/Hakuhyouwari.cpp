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
int m, n;
vector<vector<int>> field;
int maxcount = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<bool>> seen;

void dfs(vector<vector<int>> G, int y, int x, int& count) {}

int main() {
  cin >> m >> n;
  field.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      
    }
    
  }
  
}