#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a.at(i);

  sort(a.begin(), a.end());

  long long temp = 0;
  long long sum = 0;

  for (long long i = 0; i < n; i++) {
    sum += a.at(i) * (n-1);
    temp += a.end() - lower_bound(a.begin() + i + 1, a.end(), 100000000LL - a.at(i));
  }

  sum -= temp * 100000000LL;
  cout << sum << endl;
}