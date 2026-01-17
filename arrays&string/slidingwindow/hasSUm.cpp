#include <iostream>
#include <vector>
using namespace std;

bool hasSum(vector<int>& arr, int target) {
    int i = 0, csum = 0;
    
    for (int j = 0; j < arr.size(); j++) {
        csum += arr[j]; // Add current element

        // Shrink window while sum is too large
        while (csum > target && i < j) {
            csum -= arr[i];
            i++;
        }

        if (csum == target) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {3, 2, 0, 4, 7};
    int target = 6;
    // Output: 0 (false) because no contiguous elements sum to 6
    cout << (hasSum(arr, target) ? "True" : "False"); 
    return 0;
}
