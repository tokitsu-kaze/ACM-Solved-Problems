class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto it:matrix)
        {
            for(auto it2:it)
            {
                if(it2==target) return true;
            }
        }
        return false;
    }
};
