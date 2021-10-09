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
  int A[5];
	rep(i, 0, 5) cin >> A[i];
	vector<int> v;
	rep(i, 0, 5) v.push_back(i);
	int ans = 100000;
	do {
		int t = 0;
		rep(i, 0, 5) {
			int vi = v[i];
			if (0 < t % 10) t = t - (t % 10) + 10;
			t += A[vi];
		}
		chmin(ans, t);
	} while (next_permutation(v.begin(),v.end()));

	cout << ans << endl;
}