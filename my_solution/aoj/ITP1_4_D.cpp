#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> s(n);
  for (int i = 0; i < n; i++) cin >> s.at(i);
  int q;
  cin >> q;
  vector<long long> t(q);
  for (int i = 0; i < q; i++) cin >> t.at(i);

  long long ans = 0;
  for (auto x: t) {
    int left = 0;
    int right = n-1;
    

    // 改善できる
    if (s.at(right) == x) {
      ans++;
      continue;
    }
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (s.at(mid) > x) {
       right = mid;
       continue;
      }
      else if (s.at(mid) <= x) {
        left = mid;
        continue;
      }
    }
    if (s.at(left) == x) ans++;
  }
  cout << ans << endl;
}