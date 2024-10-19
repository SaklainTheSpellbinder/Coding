/**
 *    author:  tourist
 *    created: 30.06.2024 17:35:58
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = 0;
    int64_t sum = 0;
    for (int i = 1; i < n; i++) {
      int delta = max(a[i - 1] - a[i], 0);
      mx = max(mx, delta);
      sum += delta;
      a[i] += delta;
    }
    cout << sum + mx << '\n';
  }
  return 0;
}