bool searchMatrixStaircase(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    int r = 0, c = cols - 1; // start at top-right

    while (r < rows && c >= 0) {
        if (mat[r][c] == target) return true;
        else if (mat[r][c] > target) c--;
        else r++;
    }

    return false;
}
