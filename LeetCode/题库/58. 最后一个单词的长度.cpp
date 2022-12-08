class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        reverse(s.begin(),s.end());
        for(auto it:s)
        {
            if(it==' ')
            {
                if(res) return res;
            }
            else res++;
        }
        return res;
    }
};
