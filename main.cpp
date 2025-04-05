#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;

#define rep(i, x, limit) for (int i = (int)x; i < (int)limit; i++)
#define REP(i, x, limit) for (int i = (int)x; i <= (int)limit; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define eps (1e-10)
#define Equals(a,b) (fabs((a) - (b)) < eps )
#define debug(x) cerr << #x << " = " << x << el

const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

template<class T> T factorial(T n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main() {
  ll n;
  cin >> n;

  ll prev;
  ll now;
  bool ans = true;

  for (int i = 0; i < n; i++) {
    if (i == 0) cin >> now;
    else {
      prev = now;
      cin >> now;
      if (prev >= now) {ans = false;break;}
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;

}