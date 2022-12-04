class Solution {
public:
    int findMin(vector<int>& nums) {
        int l,r,mid;
        l=1;
        r=(int)nums.size();
        while(l<r)
        {
            mid=(l+r)>>1;
            if(nums[mid-1]>=nums[r-1]) l=mid+1;
            else r=mid;
        }
        return nums[l-1];
    }
};
