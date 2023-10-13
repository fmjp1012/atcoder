#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  vector<bool> used_r(8), used_c(8);
  vector<pair<int, int>> rc(k);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    used_r.at(x) = true; used_c.at(y) = true;
    rc.at(i).first = x; rc.at(i).second = y;
  }

  vector<int> unused_r, unused_c;
  for (int i = 0; i < 8; i++) {
    if (!used_r.at(i)) unused_r.push_back(i);
  } 
  for (int i = 0; i < 8; i++) {
    if (!used_c.at(i)) unused_c.push_back(i);
  }

  sort(unused_r.begin(), unused_r.end());
  sort(unused_c.begin(), unused_c.end());

  vector<bool> comp(8, true); 

  do {
    bitset<15>  sum, diff;
    for (auto temp: rc) {
      sum.set(temp.first + temp.second);
      diff.set(temp.first - temp.second + 7);
    }
    for (int i = 0; i < 8 - k; i++) {
      int temp_sum = unused_r.at(i) + unused_c.at(i);
      int temp_diff = unused_r.at(i) - unused_c.at(i) + 7;

      if (!sum.test(temp_sum)) sum.set(temp_sum);
      if (!diff.test(temp_diff)) diff.set(temp_diff);
    }

    if (sum.count() == 8 && diff.count() == 8) break;
  } while(next_permutation(unused_c.begin(), unused_c.end()));

  vector<vector<bool>> T(8, vector<bool>(8));
  for (auto temp_rc: rc) T.at(temp_rc.first).at(temp_rc.second) = true;
  for (int i = 0; i < 8-k; i++) T.at(unused_r.at(i)).at(unused_c.at(i)) = true;
  
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (T.at(i).at(j)) cout << 'Q';
      else cout << '.';
    }
    cout << endl;
  }
}