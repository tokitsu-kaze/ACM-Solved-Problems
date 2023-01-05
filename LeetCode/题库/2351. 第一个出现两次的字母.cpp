class Solution {
public:
    char repeatedCharacter(string s) {
        int cnt[26]={0};
        for(auto &it:s)
        {
            if(cnt[it-'a']) return it;
            cnt[it-'a']++;
        }
        return '0';
    }
};
