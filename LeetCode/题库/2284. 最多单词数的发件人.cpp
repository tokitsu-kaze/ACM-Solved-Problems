#define sz(x) ((int)x.size())
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int i;
        map<string,int> mp;
        for(i=0;i<sz(senders);i++)
        {
            int cnt=0;
            for(auto it:messages[i])
            {
                if(it==' ') cnt++;
            }
            mp[senders[i]]+=cnt+1;
        }
        int mx=0;
        for(auto it:mp)
        {
            mx=max(it.second,mx);
        }
        vector<string> res;
        for(auto it:mp)
        {
            if(it.second == mx)
            {
                res.push_back(it.first);
            }
        }
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        return res[0];
            
    }
};
