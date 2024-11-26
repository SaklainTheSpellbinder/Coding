#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long maxManhattanValue = (n * (n - 1)) / 2;

        if (k > maxManhattanValue) {
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i + 1;
        }

        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                cout << p[i] << " ";
            }
            cout << endl;
            continue;
        }

        for (int i = 0; i < n && k > 0; ++i) {
            long long maxSwapValue = n - i - 1;
            if (k >= maxSwapValue) {
                reverse(p.begin() + i, p.end());
                k -= maxSwapValue;
            } else {
                reverse(p.begin() + i, p.begin() + i + k + 1);
                k = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
