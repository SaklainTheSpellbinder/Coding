#include<iostream>
#include<limits.h>
using namespace std;
int maxsubarraysum(int arr[],int n){
    int maxsum= INT_MIN;
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            int currsum=0;
            for(int i=start;i<=end;i++){
                currsum+=arr[i];
            }
            maxsum=max(maxsum,currsum);
        }
    }
    return maxsum;
}
int maxsubarraysum2(int arr[],int n){
    int maxsum=INT_MIN;
    for(int start=0;start<n;start++){
        int cursum=0;
        for(int end=start;end<n;end++){
            cursum+=arr[end];
            maxsum=max(maxsum,cursum);
        }
    }
    return maxsum;
}

int maxsubarraysum3(int arr[],int n){        //kadane's algo//eta all minus hole mara khay
    int maxsum=INT_MIN;
    int cursum=0;
    for(int start=0;start<n;start++){
        cursum+=arr[start];        //cursum=max(arr[start],cursum+arr[start]);   eta dile r oi zero kora lagbe na
        maxsum=max(maxsum,cursum);
        if(cursum<0)
            cursum=0;
    }
    return maxsum;
}

void maxSubarraySumWithIndices(int arr[], int n) {
    int maxSum = INT_MIN;
    int curSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < n; i++) {
        curSum += arr[i];

        if (curSum > maxSum) {
            maxSum = curSum;
            start = tempStart;
            end = i;
        }

        if (curSum < 0) { 
            curSum = 0;
            tempStart = i + 1; // Potential start of new subarray
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={-1,-3,-2,-4,-5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxsubarraysum3(arr,n)<<"\n";
}

