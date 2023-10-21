#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);

vector<vector<tuple<int, int, int, int>>> table;
vector<vector<int>> dist;
queue<pair<int, int>> todo;
void bfs(pair<int, int> s) {
  dist.at(s.first).at(s.second) = 1;
  todo.push(s);
  while (!todo.empty()) {
    pair<int, int> v;
    v = todo.front();
    todo.pop();

    if (get<0>(table.at(v.first).at(v.second)) == 0 &&
        dist.at(v.first - 1).at(v.second) == INF) {
      dist.at(v.first - 1).at(v.second) = dist.at(v.first).at(v.second) + 1;
      todo.push(make_pair(v.first - 1, v.second));
    }
    if (get<1>(table.at(v.first).at(v.second)) == 0 &&
        dist.at(v.first).at(v.second + 1) == INF) {
      dist.at(v.first).at(v.second + 1) = dist.at(v.first).at(v.second) + 1;
      todo.push(make_pair(v.first, v.second + 1));
    }
    if (get<2>(table.at(v.first).at(v.second)) == 0 &&
        dist.at(v.first + 1).at(v.second) == INF) {
      dist.at(v.first + 1).at(v.second) = dist.at(v.first).at(v.second) + 1;
      todo.push(make_pair(v.first + 1, v.second));
    }
    if (get<3>(table.at(v.first).at(v.second)) == 0 &&
        dist.at(v.first).at(v.second - 1) == INF) {
      dist.at(v.first).at(v.second - 1) = dist.at(v.first).at(v.second) + 1;
      todo.push(make_pair(v.first, v.second - 1));
    }
  }
}

int main() {

  while (true) {
    int h, w;
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;

    table.assign(h,
                 vector<tuple<int, int, int, int>>(w, make_tuple(1, 1, 1, 1)));
    dist.assign(h, vector<int>(w, INF));

    for (int i = 0; i < 2 * h - 1; i++) {
      if (i % 2 == 0)
        for (int j = 0; j < w - 1; j++) {
          int temp;
          cin >> temp;
          if (temp == 0) {
            get<1>(table.at(i / 2).at(j)) = 0;
            get<3>(table.at(i / 2).at(j + 1)) = 0;
          }
        }
      else
        for (int j = 0; j < w; j++) {
          int temp;
          cin >> temp;
          if (temp == 0) {
            get<2>(table.at(i / 2).at(j)) = 0;
            get<0>(table.at(i / 2 + 1).at(j)) = 0;
          }
        }
    }
    bfs(make_pair(0, 0));
    if (dist.at(h-1).at(w-1) == INF) cout << 0 << endl;
    else cout << dist.at(h - 1).at(w - 1) << endl;
  }
}