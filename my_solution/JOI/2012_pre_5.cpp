#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> seen;
queue<pair<int, int>> todo;
vector<vector<int>> table;

int ans = 0;
void bfs(pair<int, int> s) {
  seen.at(s.first).at(s.second) = true;
  todo.push(s);

  while (!todo.empty()) {
    pair<int, int> v;
    v = todo.front();
    todo.pop();

    // yoko
    if (table.at(v.first).at(v.second - 1) == 0 &&
        seen.at(v.first).at(v.second - 1) == false) {
      seen.at(v.first).at(v.second - 1) = true;
      todo.push(make_pair(v.first, v.second - 1));
    } else if (table.at(v.first).at(v.second - 1) == 1) {
      ans++;
    }

    if (table.at(v.first).at(v.second + 1) == 0 &&
        seen.at(v.first).at(v.second + 1) == false) {
      seen.at(v.first).at(v.second + 1) = true;
      todo.push(make_pair(v.first, v.second + 1));
    } else if (table.at(v.first).at(v.second + 1) == 1) {
      ans++;
    }

    // tate
    if (v.first % 2 == 1) {
      if (table.at(v.first - 1).at(v.second - 1) == 0 &&
          seen.at(v.first - 1).at(v.second - 1) == false) {
        seen.at(v.first - 1).at(v.second - 1) = true;
        todo.push(make_pair(v.first - 1, v.second - 1));
      } else if (table.at(v.first - 1).at(v.second - 1) == 1) {
        ans++;
      }

      if (table.at(v.first - 1).at(v.second) == 0 &&
          seen.at(v.first - 1).at(v.second) == false) {
        seen.at(v.first - 1).at(v.second) = true;
        todo.push(make_pair(v.first - 1, v.second));
      } else if (table.at(v.first - 1).at(v.second) == 1) {
        ans++;
      }

      if (table.at(v.first + 1).at(v.second - 1) == 0 &&
          seen.at(v.first + 1).at(v.second - 1) == false) {
        seen.at(v.first + 1).at(v.second - 1) = true;
        todo.push(make_pair(v.first + 1, v.second - 1));
      } else if (table.at(v.first + 1).at(v.second - 1) == 1) {
        ans++;
      }

      if (table.at(v.first + 1).at(v.second) == 0 &&
          seen.at(v.first + 1).at(v.second) == false) {
        seen.at(v.first + 1).at(v.second) = true;
        todo.push(make_pair(v.first + 1, v.second));
      } else if (table.at(v.first + 1).at(v.second) == 1) {
        ans++;
      }

    } else {
      if (table.at(v.first - 1).at(v.second + 1) == 0 &&
          seen.at(v.first - 1).at(v.second + 1) == false) {
        seen.at(v.first - 1).at(v.second + 1) = true;
        todo.push(make_pair(v.first - 1, v.second + 1));
      } else if (table.at(v.first - 1).at(v.second + 1) == 1) {
        ans++;
      }

      if (table.at(v.first - 1).at(v.second) == 0 &&
          seen.at(v.first - 1).at(v.second) == false) {
        seen.at(v.first - 1).at(v.second) = true;
        todo.push(make_pair(v.first - 1, v.second));
      } else if (table.at(v.first - 1).at(v.second) == 1) {
        ans++;
      }

      if (table.at(v.first + 1).at(v.second + 1) == 0 &&
          seen.at(v.first + 1).at(v.second + 1) == false) {
        seen.at(v.first + 1).at(v.second + 1) = true;
        todo.push(make_pair(v.first + 1, v.second + 1));
      } else if (table.at(v.first + 1).at(v.second + 1) == 1) {
        ans++;
      }

      if (table.at(v.first + 1).at(v.second) == 0 &&
          seen.at(v.first + 1).at(v.second) == false) {
        seen.at(v.first + 1).at(v.second) = true;
        todo.push(make_pair(v.first + 1, v.second));
      } else if (table.at(v.first + 1).at(v.second) == 1) {
        ans++;
      }
    }
  }
}

int main() {
  int h, w;
  cin >> w >> h;
  table.assign(h + 4, vector<int>(w + 4, 0));
  for (int i = 0; i < w+4; i++)
    table.at(0).at(i) = 1;
  for (int i = 0; i < w+4; i++)
    table.at(h + 4 - 1).at(i) = 1;
  for (int i = 0; i < h+4; i++)
    table.at(i).at(0) = 1;
  for (int i = 0; i < h+4; i++)
    table.at(i).at(w + 4 - 1) = 1;
  seen.assign(h + 4, vector<bool>(w + 4, false));

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      int temp;
      cin >> temp;
      if (temp == 1)
        table.at(i + 2).at(j + 2) = 1;
    }

  bfs(make_pair(1, 1));
  ans -= 4*(w+2) + 4*(h+2) - 2;
  cout << ans << endl;
}