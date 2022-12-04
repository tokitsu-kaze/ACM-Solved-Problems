class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<1 || nums[i]>n) continue;
            int x=nums[i];
            while(x>=1 && x<=n)
            {
                if(nums[x-1]==x) break;
                swap(x,nums[x-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i+1!=nums[i]) return i+1;
        }
        return n+1;
    }
};
