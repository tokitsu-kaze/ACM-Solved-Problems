class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        int sq=sqrt(c+0.5);
        map<long long,int> mp;
        for(int i=0;i<=sq;i++)
        {
            mp[1ll*i*i]++;
            if(mp.count(c-1ll*i*i)) return true;
        }
        return false;
    }
};
