#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAddPoint(const vector<int>& points) {
    int n = points.size();
    // Check if there is a pair of consecutive points with a difference greater than 1
    for (int i = 0; i < n - 1; ++i) {
        int diff = points[i+1] - points[i];
        if (diff > 1) {
            return true;
        }
    }
    // If no such pair exists, we can't add a point that satisfies the conditions
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i];
        }
        // Sort the points (though they are given sorted in the problem)
        sort(points.begin(), points.end());
        if (canAddPoint(points)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
