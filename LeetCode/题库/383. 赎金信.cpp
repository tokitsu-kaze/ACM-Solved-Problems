int cnta[333],cntb[333];
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));
        for(auto it:magazine) cnta[it-'a']++;
        for(auto it:ransomNote) cntb[it-'a']++;
        for(int i=0;i<26;i++)
        {
            if(cntb[i]>cnta[i]) return false;
        }
        return true;
    }
};
