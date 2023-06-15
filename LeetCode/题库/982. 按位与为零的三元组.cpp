const int MAX=(1<<16)+10;
int cnt[MAX];
class Solution {
public:
    int countTriplets(vector<int>& nums) {
		int i,j,n,ans;
		n=nums.size();
		memset(cnt,0,sizeof cnt);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cnt[nums[i]&nums[j]]++;
			}
		}
		ans=0;
		for(i=0;i<MAX;i++)
		{
			for(j=0;j<n;j++)
			{
				if((nums[j]&i)==0) ans+=cnt[i];
			}
		}
		return ans;
    }
};
