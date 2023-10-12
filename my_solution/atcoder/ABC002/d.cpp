#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> xy(m);
  for (int i = 0; i < m; i++) cin >> xy.at(i).first >> xy.at(i).second;

  int ans = 1;
  for (int i = 0; i < (1 << n); i++) {

    bitset<12> s(i);

    bool flag = true;
    for (int j = 0; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if (s.test(j) && s.test(k)) {
          if (find(xy.begin(), xy.end(), make_pair(j+1, k+1)) == xy.end()) {
            flag = false;
            break;
          }
        }
      }

      if (!flag) break;

    }

    if (flag) chmax(ans, (int)s.count());
  }
  cout << ans << endl;
}