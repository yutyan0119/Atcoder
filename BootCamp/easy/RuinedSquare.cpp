#include <bits/stdc++.h>
using namespace std;
int main(){
  vector <pair<int, int>> x(4);
  for (int i = 0; i < 2; i++)
  {
    cin >> x[i].first >> x[i].second;
  }
  int difx = x[0].first-x[1].first;
  int dify = x[0].second-x[1].second;
  int rotx = dify;
  int roty = -difx;
  x[2] = {x[1].first+rotx, x[1].second+roty};
  x[3] = {x[0].first+rotx, x[0].second+roty};
  cout << x[2].first << " " << x[2].second << " " << x[3].first << " " << x[3].second << endl;
}