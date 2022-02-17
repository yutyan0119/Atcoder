#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  int nil = -1;
  vector<int> front(n + 1, nil);
  vector<int> back(n + 1, nil);

  while (q > 0) {
    int c;
    cin >> c;
    if (c == 1) {
      int x, y;
      cin >> x >> y;
      back[x] = y;
      front[y] = x;
    } else if (c == 2) {
      int x, y;
      cin >> x >> y;
      back[x] = nil;
      front[y] = nil;
    } else {
      int x;
      cin >> x;
      while (front[x] != nil) {
        x = front[x];
      }
      vector<int> ans;
      while (x != nil) {
        ans.push_back(x);
        x = back[x];
      }
      cout << ans.size() << " ";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
        if (i == ans.size() - 1) {
          cout << "\n";
        }
      }
    }
    q--;
  }
}