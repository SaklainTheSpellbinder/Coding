#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long i = 1;
    while (n > i) {
        n -= i;  
        i++;     
    }
    cout << n << endl;  
    return 0;
}
