class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if((int)nums.size()==0) return vector{-1,-1};
        int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int b=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if(a==(int)nums.size()) return vector{-1,-1};
        if(nums[a]!=target) return vector{-1,-1};
        return vector{a,b};
    }
};
