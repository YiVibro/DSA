#include<bits/stdc++.h>
using namespace std;

bool searchMatrixFlattened(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int r = mid / cols;
        int c = mid % cols;

        if (mat[r][c] == target) return true;
        else if (mat[r][c] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>>mat={{1,2,3},{5,6,7},{8,9,10}};
    cout<<searchMatrixFlattened(mat,6);
    return 0;
}