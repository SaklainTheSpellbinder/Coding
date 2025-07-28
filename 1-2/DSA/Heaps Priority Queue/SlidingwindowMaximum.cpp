#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>


using namespace std;
void slidingwindows(vector<int>arr,int k){  //O(nlogk)
    priority_queue<pair<int,int>>pq;
    //deafult max heap according to first  value of pair
    for(int i=0;i<k;i++){
        pq.push({arr[i],i});
    }

    cout<<pq.top().first<<" ";

    for(int i=k;i<arr.size();i++){
        while(!pq.empty() && pq.top().second<=(i-k)){
            pq.pop();
        }
        pq.push({arr[i],i});
        cout<<pq.top().first<<" ";
    }
    cout<<endl;
}

void slidingWindowMax(vector<int>& arr, int k) { //O(n)
    deque<int> dq; // To store indices of useful elements
    vector<int> result; // To store the maximums of each window

    for (int i = 0; i < arr.size(); i++) {
        // Step A: Remove indices of elements outside the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front(); // Remove the outdated index
        }

        // Step B: Remove indices of elements smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back(); // Remove indices of smaller elements
        }

        // Step C: Add the current index to the deque
        dq.push_back(i);

        // Step D: Record the maximum for the current window
        if (i >= k - 1) { // Only start recording when the first window is complete
            result.push_back(arr[dq.front()]); // The front holds the index of the maximum
        }
    }

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int>arr={1,3,-1,-3,5,3,6,7};
    int k=3;
    slidingwindows   (arr,k);
}