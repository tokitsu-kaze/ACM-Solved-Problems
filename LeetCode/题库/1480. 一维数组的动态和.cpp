class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int now=0;
        for(auto it:nums)
        {
            now+=it;
            res.push_back(now);
        }
        return res;
    }
};
