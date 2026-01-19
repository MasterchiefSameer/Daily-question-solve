// C++
// Prefix Sum + Binary Search

class Solution {
    int rows, cols;

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        rows = mat.size();
        cols = mat[0].size();

        vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));

        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                prefix[r][c] = prefix[r-1][c] + prefix[r][c-1]
                             - prefix[r-1][c-1] + mat[r-1][c-1];
            }
        }

        int left = 0, right = min(rows, cols), ans = 0;

        while (left <= right) {
            int size = (left + right) / 2;
            if (exists(prefix, size, threshold)) {
                ans = size;
                left = size + 1;
            } else {
                right = size - 1;
            }
        }
        return ans;
    }

    bool exists(vector<vector<int>>& prefix, int size, int limit) {
        for (int r = size; r <= rows; r++) {
            for (int c = size; c <= cols; c++) {
                int sum = prefix[r][c] - prefix[r-size][c]
                        - prefix[r][c-size] + prefix[r-size][c-size];
                if (sum <= limit) return true;
            }
        }
        return false;
    }
};