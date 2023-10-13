#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 50);

template<class T> T factorial(T n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main() {
  int n;
  cin >> n;
  vector<pair<double, double>> xy(n);
  double ans = 0;

  vector<int> v(n);
  for (int i = 0; i < n; i++) v.at(i) = i;

  for (int i = 0; i < n; i++) cin >> xy.at(i).first >> xy.at(i).second;

  do {
    for (int i = 1; i < n; i++) {
      ans += sqrt(
         pow((xy.at(v.at(i-1)).first - xy.at(v.at(i)).first), 2) + pow(((xy.at(v.at(i-1)).second - xy.at(v.at(i)).second)), 2)
      );
    }
  } while (next_permutation(v.begin(), v.end()));

  ans /= factorial(n);

  cout << fixed << setprecision(10);
  cout << ans << endl;
}