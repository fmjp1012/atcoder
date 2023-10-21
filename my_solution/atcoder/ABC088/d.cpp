#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);

vector<vector<char>> table;
vector<vector<int>> dist;
queue<pair<int, int>> todo;
vector<int> dh = {-1, 0, 1, 0};
vector<int> dw = {0, 1, 0, -1};
void bfs(pair<int, int> s) {
  dist.at(s.first).at(s.second) = 0;
  todo.push(s);
  while (!todo.empty()) {
    pair<int, int> v;
    v = todo.front();
    todo.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> next_v =
          make_pair(v.first + dh.at(i), v.second + dw.at(i));
      if (table.at(next_v.first).at(next_v.second) == '.' &&
          dist.at(next_v.first).at(next_v.second) == INF) {
        dist.at(next_v.first).at(next_v.second) =
            dist.at(v.first).at(v.second) + 1;
        todo.push(next_v);
      }
    }
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  table.assign(h + 2, vector<char>(w + 2, '#'));
  dist.assign(h + 2, vector<int>(w + 2, INF));
  int cnt = 0;

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      char temp;
      cin >> temp;
      if (temp == '#')
        cnt++;
      else
        table.at(i + 1).at(j + 1) = temp;
    }

  bfs(make_pair(1, 1));

  if (dist.at(h).at(w) == INF)
    cout << -1 << endl;
  else {
    cout << h * w - cnt - (dist.at(h).at(w) + 1) << endl;
  }
}