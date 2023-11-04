#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  sort(a.begin(), a.end());

  long long ans = 1, left = 0, right = 0;
  long long temp = 1;

  while (right < n-1) {
    right++;
    while (a.at(right) - a.at(left) >= m) {
      left++;
    }
    chmax(ans, right - left + 1);
  }
  cout << ans << endl;
}