class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> matrix;
        vector<int> final;
        if(rowIndex  == 0){
            return {1};
        }
        if(rowIndex  == 1){
            return {1,1};
        }
        if (rowIndex >= 0)
            matrix.push_back({1});
        if (rowIndex >= 1)
            matrix.push_back({1, 1});

        for (int i = 2; i <= rowIndex; i++) {
            vector<int> a1(i + 1, 1);

            for (int j = 1; j < i; j++) {
                a1[j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
            }
            matrix.push_back(a1);
            final = a1;
        }

        return final;
    }
};