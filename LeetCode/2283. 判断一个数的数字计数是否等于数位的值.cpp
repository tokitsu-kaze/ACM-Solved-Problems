class Solution {
public:
    bool digitCount(string num) {
        int cnt[11]={0};
        int n=(int)num.size();
        for(auto it:num) cnt[it-'0']++;
        for(int i=0;i<n;i++)
        {
            if(cnt[i]!=num[i]-'0') return false;
        }
        return true;
    }
};
