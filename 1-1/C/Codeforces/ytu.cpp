#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  // Faster input/output
    cin.tie(NULL);

    int t;
    cin >> t;  // Read the number of test cases

    while (t--) {  // Loop through each test case
        int n;
        cin >> n;  // Read the size of the array

        int arr[n];  // Declare an array of size n (valid in C99 or C++)

        // Read elements of the array
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int flag = 0;
        int count = 0;

        while (flag == 0) {  // Outer loop to modify the array until flag is 1
            flag = 1;
            for (int i = 0; i < n - 1; i++) {  // Inner loop to traverse the array
                if (arr[i] > arr[i + 1]) {  // Condition for decrement
                    arr[i]--;
                    flag = 0;  // Set flag to 0 if modification is made
                }
            }
            if (arr[n - 1] != 0) {  // Check the last element after the loop
                arr[n - 1]--;
                flag = 0;  // Set flag to 0 if modification is made
            }
            count++;  // Increment count after each modification loop
        }

        cout << count-1 << "\n";  // Output the count of modifications
    }

    return 0;
}
