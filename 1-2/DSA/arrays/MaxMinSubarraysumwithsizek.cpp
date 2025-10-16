 #include <iostream>
#include <vector>
#include <climits>
using namespace std;

//fixed window problem

void maxMinSumSubarray(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) {
        cout << "Window size is larger than array size!" << endl;
        return;
    }

    int windowSum = 0;
    for (int i = 0; i < k; ++i)
        windowSum += arr[i];

    int maxSum = windowSum;
    int minSum = windowSum;

    for (int i = k; i < n; ++i) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
        minSum = min(minSum, windowSum);
    }

    cout << "Maximum sum of subarray of size " << k << " = " << maxSum << endl;
    cout << "Minimum sum of subarray of size " << k << " = " << minSum << endl;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2, 6};
    int k = 3;

    maxMinSumSubarray(arr, k);

    return 0;
}
