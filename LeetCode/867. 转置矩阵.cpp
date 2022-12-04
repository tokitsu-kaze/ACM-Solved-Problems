class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        for(int j=0;j<(int)matrix[0].size();j++)
        {
            vector<int> tmp;
            for(int i=0;i<(int)matrix.size();i++)
            {
                tmp.push_back(matrix[i][j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
