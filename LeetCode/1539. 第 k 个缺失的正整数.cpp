class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans=0;
        int pre=0;
        for(auto it:arr)
        {
            if(ans+it-pre-1>=k)
            {
                return pre+k-ans;
            }
            ans+=it-pre-1;
            pre=it;
            
        }
        return pre+k-ans;
    }
};
