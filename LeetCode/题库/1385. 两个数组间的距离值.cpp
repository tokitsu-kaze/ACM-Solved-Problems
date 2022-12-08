class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res=0;
        for(auto it:arr1)
        {
            int now=111;
            for(auto it2:arr2)
            {
                now=min(now,abs(it-it2));
            }
            if(now>d) res++;
        }
        return res;
    }
};
