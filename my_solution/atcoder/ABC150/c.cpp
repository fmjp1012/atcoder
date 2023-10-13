#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 50);

int main() {
  int n; 
  cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) cin >> p.at(i);
  for (int i = 0; i < n; i++) cin >> q.at(i);

  if (p>q) swap(p, q);
  long long ans = 0;

  do {
    if (p == q) break;
    ans++;
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;
}