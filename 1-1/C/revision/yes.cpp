/**
 *    author:  tourist
 *    created: 25.06.2024 17:36:33
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
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0 && x > 1) {
      int rm = x % y;
      if (rm < y - 1) {
        int take = min(y - 1 - rm, k);
        x += take;
        k -= take;
        continue;
      }
      x += 1;
      while (x % y == 0) {
        x /= y;
      }
      k -= 1;
    }
    if (k > 0) {
      assert(x == 1);
      x = k % (y - 1) + 1;
    }
    cout << x << '\n';
  }
  return 0;
}
