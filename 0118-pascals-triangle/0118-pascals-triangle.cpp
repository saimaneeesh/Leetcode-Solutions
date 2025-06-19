class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> matrix(n); // Flattened to 2D vector

        if (numRows == 1) {
            matrix[0] = {1};
            return matrix;
        }

        if (numRows == 2) {
            matrix[0] = {1};
            matrix[1] = {1, 1};
            return matrix;
        }

        matrix[0] = {1};
        matrix[1] = {1, 1};

        for (int i = 2; i < n; i++) {
            vector<int> arr(i + 1);
            arr[0] = 1;
            arr[i] = 1;
            for (int j = 1; j < i; j++) {
                arr[j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
            }
            matrix[i] = arr;
        }

        return matrix;
    }
};