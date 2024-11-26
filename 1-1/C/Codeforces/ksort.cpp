#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long min_coins_to_non_decreasing(vector<int>& arr) {
    long long coins = 0;
    vector<int> b(arr.size(), 0); // This will store the minimum increments needed to make arr non-decreasing

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            b[i] = b[i - 1] + (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        } else {
            b[i] = b[i - 1];
        }
    }

    return b[arr.size() - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << min_coins_to_non_decreasing(arr) << "\n";
    }

    return 0;
}
