#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

void sortQueueUsingStack(std::queue<int>& q) {
    std::stack<int> st;
    int size = q.size();

    for (int i = 0; i < size; ++i) {
        int minVal = INT_MAX;
        int count = q.size();

        // Find the minimum element in the queue
        for (int j = 0; j < count; ++j) {
            int temp = q.front(); q.pop();
            if (temp < minVal) minVal = temp;
            q.push(temp);
        }

        // Move elements to stack, skip the first minVal occurrence
        bool skipped = false;
        for (int j = 0; j < count; ++j) {
            int temp = q.front(); q.pop();
            if (!skipped && temp == minVal) {
                skipped = true;
                continue;
            }
            st.push(temp);
        }

        // Put minVal at the end of the queue
        q.push(minVal);

        // Restore other elements
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
}


void sortStackUsingQueue(std::stack<int>& st) {
    std::queue<int> q;

    // Step 1: Move elements from stack to queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    int size = q.size();
    while (size--) {
        int maxVal = INT_MIN;
        int count = q.size();

        // Step 2: Find max value and track its index
        for (int i = 0; i < count; ++i) {
            int val = q.front();
            q.pop();

            if (val > maxVal) maxVal = val;
            q.push(val);
        }

        // Step 3: Remove first occurrence of maxVal and push others back
        bool maxRemoved = false;
        for (int i = 0; i < count; ++i) {
            int val = q.front();
            q.pop();
            if (!maxRemoved && val == maxVal) {
                maxRemoved = true;
            } else {
                q.push(val);
            }
        }

        // Push maxVal onto the stack
        st.push(maxVal);
    }
}


void sortStackIterative(stack<int>& input){
    stack<int> temp;

    while (!input.empty()) {
        int top = input.top();
        input.pop();

        // move elements from temp back to input if they're larger
        while (!temp.empty() && temp.top() > top) {
            input.push(temp.top());
            temp.pop();
        }

        temp.push(top);
    }

    // transfer back to original stack if needed
    while (!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
}

// C++ Code to Sort a Stack Recursively
void insertSorted(stack<int>& st, int val) {
    if (st.empty() || val > st.top()) {
        st.push(val);
        return;
    }

    int top = st.top();
    st.pop();
    insertSorted(st, val);
    st.push(top);
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int top = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, top);
    }
}


void sortQueueUsingQueue(std::queue<int>& q) {
    int size = q.size();

    for (int i = 0; i < size; ++i) {
        int minVal = INT_MAX;
        int count = q.size();

        // Step 1: Find minimum in unsorted portion
        for (int j = 0; j < count; ++j) {
            int temp = q.front(); q.pop();
            if (j < count - i && temp < minVal) minVal = temp;
            q.push(temp);
        }

        // Step 2: Move minimum to back (skipping its first occurrence)
        bool skipped = false;
        for (int j = 0; j < count; ++j) {
            int temp = q.front(); q.pop();
            if (!skipped && temp == minVal && j < count - i) {
                skipped = true;  // don’t reinsert now
                continue;
            }
            q.push(temp);
        }

        // Step 3: Place minVal at the rear
        q.push(minVal);
    }
}

void sortQueueWithoutExtraDS(queue<int>& q) {
    int size = q.size();

    for (int i = 0; i < size; ++i) {
        int minVal = INT_MAX;

        // Find minimum in unsorted portion
        for (int j = 0; j < size; ++j) {
            int val = q.front(); q.pop();
            if (j < size - i && val < minVal) minVal = val;
            q.push(val);
        }

        // Move elements back, skipping the first minVal
        bool minPlaced = false;
        for (int j = 0; j < size; ++j) {
            int val = q.front(); q.pop();
            if (!minPlaced && val == minVal && j < size - i) {
                minPlaced = true; // skip this once
                continue;
            }
            q.push(val);
        }

        // Place minVal at rear
        q.push(minVal);
    }
}


