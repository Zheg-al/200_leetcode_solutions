//https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return {};
        vector <vector <int> > result;
        result.push_back ({1});
        for (int i = 1; i < numRows; i++){
            vector <int> row;
            row.push_back (1);
            for (int j = 1; j < i; j++)
                row.push_back (result[i - 1][j - 1] + result[i - 1][j]);
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};
