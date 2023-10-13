#include <bits/stdc++.h>
using namespace std;

template<class T>
bool isOk(T key) {
  return true;
}

template<class T>
T binary_search(vector<T> &v, T key) {
  int left = -1;
  int right = (int)v.size();

  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (isOk(mid, key)) right = mid;
    else if (!isOk(mid, key)) left = mid; 
  }

  return right;
}

int main() {

}