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

vector<int> number;
vector<int> coin = {500, 100, 50};
vector<int> limit(3);

void dfs(int& count, int& sum) {
  if (number.size() == 3) {
    int testsum = 0;
    for (int i = 0; i < 3; i++) {
      testsum += coin[i] * number[i];
    }
    if (sum == testsum) {
      count++;
    }
    return;
  }
  for (int i = 0; i <= limit.at(number.size()); i++) {
    number.push_back(i);
    dfs(count, sum);
    number.pop_back();
  }
}

int main() {
  int count = 0;
  int sum;
  for (int i = 0; i < 3; i++) {
    cin >> limit[i];
  }
  cin >> sum;
  dfs(count, sum);
  cout << count << endl;
}