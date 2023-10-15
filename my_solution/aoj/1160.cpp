#include <bits/stdc++.h>
using namespace std;

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    vector<vector<int>> c(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
    cin >> c.at(i).at(j);

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    stack<pair<int, int>> todo;
    int ans = 0;

    for (int k = 0; k < h; k++) {
      for (int l = 0; l < w; l++) {
        if (c.at(k).at(l) == 0 || seen.at(k).at(l) == true) continue;
        else {
          ans++;
          seen.at(k).at(l) = true;
          todo.push(make_pair(k, l));
          while (!todo.empty()) {
            int i, j;
            tie(i, j) = todo.top();
            seen.at(i).at(j) = true;
            todo.pop();
            if (i != 0 && j != 0 && c.at(i-1).at(j-1) == 1 && seen.at(i-1).at(j-1) == false) todo.push(make_pair(i-1, j-1));
            if (i != 0 && c.at(i-1).at(j) == 1 && seen.at(i-1).at(j) == false) todo.push(make_pair(i-1, j));
            if (i != 0 && j != w-1 && c.at(i-1).at(j+1) == 1 && seen.at(i-1).at(j+1) == false) todo.push(make_pair(i-1, j+1));
            if (j != 0 && c.at(i).at(j-1) == 1 && seen.at(i).at(j-1) == false) todo.push(make_pair(i, j-1));
            if (j != w-1 && c.at(i).at(j+1) == 1 && seen.at(i).at(j+1) == false) todo.push(make_pair(i, j+1));
            if (i != h-1 && j != 0 && c.at(i+1).at(j-1) == 1 && seen.at(i+1).at(j-1) == false) todo.push(make_pair(i+1, j-1));
            if (i != h-1 && c.at(i+1).at(j) == 1 && seen.at(i+1).at(j) == false) todo.push(make_pair(i+1, j));
            if (i != h-1 && j != w-1 && c.at(i+1).at(j+1) == 1 && seen.at(i+1).at(j+1) == false) todo.push(make_pair(i+1, j+1)); 

          }

        }

      }
    }
    cout << ans << endl;

  }


}