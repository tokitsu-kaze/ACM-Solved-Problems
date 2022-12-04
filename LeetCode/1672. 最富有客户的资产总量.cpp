class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto it:accounts)
        {
            int now=0;
            for(auto it2:it) now+=it2;
            ans=max(ans,now);
        }
        return ans;
    }
};
