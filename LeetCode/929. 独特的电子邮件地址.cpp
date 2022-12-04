class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto it:emails)
        {
            int f=0;
            int plsf=0;
            string res="";
            for(auto ch:it)
            {
                if(ch=='@') f=1;
                if(ch=='+') plsf=1;
                if(f)
                {
                    res+=ch;
                    continue;
                }
                if(plsf) continue;
                if(ch!='.') res+=ch;
            }
            s.insert(res);
        }
        return (int)s.size();
    }
};
