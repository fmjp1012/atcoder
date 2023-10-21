#include <bits/stdc++.h>
using namespace std;

template<class T>
bool isOk(vector<T> &v, T &key, T &mid) {
  if (v.at(mid) > key) return true;
  else return false;
}

template<class T>
T binary_search(vector<T> &v, T key) {
  long long left = 0;
  long long right = v.size();

  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (isOk(v, key, mid)) right = mid;
    else if (!isOk(v, key, mid)) left = mid;
  }

  return left;
}

int main() {
  long long D, n, m;
  cin >> D >> n >> m;
  vector<long long> d(n);
  d.at(0) = 0;
  for (int i = 1; i < n; i++) cin >> d.at(i);
  sort(d.begin(), d.end());
  vector<long long> k(m);
  for (int i = 0; i < m; i++) cin >> k.at(i);

  long long ans = 0;
  for (auto x: k) { 
    long long right = binary_search(d, x);
    if (right == n-1) ans += min(abs(x - d.at(right)), D - x);
    else ans += min(d.at(right+1) - x, x - d.at(right));
  }

  cout << ans << endl;
}