class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(pos==(int)nums.size() || nums[pos]!=target) return -1;
        return pos;
    }
};
