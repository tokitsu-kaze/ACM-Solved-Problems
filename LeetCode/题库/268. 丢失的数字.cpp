class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int res,n,i;
		n=nums.size();
		res=0;
		for(i=1;i<=n;i++)
		{
			res^=i;
			res^=nums[i-1];
		}
		return res;
    }
};
