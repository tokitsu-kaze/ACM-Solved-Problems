class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res=0;
        for(auto it:grid)
        {
            for(auto it2:it) res+=it2<0;
        }
        return res;
    }
};
