#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector <pair<int,int>> A;
  int B[N];
  for (int i = 0; i < N; i++)
  {
    cin >> B[i];
  }
  for (int i=0;i<N;i++){
    A.push_back({B[i], i});
  }
  sort(A.begin(), A.end());
  for (int i = 0; i<N; i++){
    cout << A.at(i).second + 1 << " ";
  }
  cout << endl;
}