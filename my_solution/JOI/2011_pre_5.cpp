#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);

vector<vector<char>> table;
vector<vector<int>> dist;
queue<pair<int, int>> todo;
vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};
void bfs(pair<int, int> s) {
  dist.at(s.first).at(s.second) = 0;
  todo.push(s);
  while (!todo.empty()) {
    pair<int, int> v = todo.front();
    todo.pop();

    for (int i = 0; i < 4; i++) {
      int r = v.first + dr.at(i);
      int c = v.second + dc.at(i);

      if (table.at(r).at(c) != 'X' && dist.at(r).at(c) == INF) {
        todo.push(make_pair(r, c));
        dist.at(r).at(c) = dist.at(v.first).at(v.second) + 1;
      }

    }
  }
}

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  table.assign(H+2, vector<char>(W+2, 'X'));
  pair<int, int> start;
  vector<pair<int, int>> goal(N);

  for (int i = 0; i < H; i++)
  for (int j = 0; j < W; j++) {
    char temp;
    cin >> temp;
    if (temp >= '1' && temp <= '9') {
      goal.at(temp - '0' - 1) = make_pair(i+1, j+1);
    }
    if (temp == 'S') {
      start = make_pair(i+1, j+1);
    }
    table.at(i+1).at(j+1) = temp;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i >= 1) {
      start = goal.at(i-1);
    }
    dist.assign(H+2, vector<int>(W+2, INF));
    bfs(start);
    ans += dist.at(goal.at(i).first).at(goal.at(i).second);
  }

  cout << ans << endl;
}