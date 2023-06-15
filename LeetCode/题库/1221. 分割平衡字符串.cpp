class Solution {
public:
    int balancedStringSplit(string s) {
		int l,r,ans;
		l=r=ans=0;
		for(auto &it:s)
		{
			if(it=='L') l++;
			else r++;
			if(l==r) ans++;
		}
		return ans;
    }
};
